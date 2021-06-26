#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<cctype>
using namespace std;

const int header_size = 256;
const char Taken = 'T';
const char Free = 'F';
const char Deleted = 'D';

class frandom :public fstream {
public:
	frandom();
	frandom(const char*);//初始化并open exsiting file
	frandom(const char*, int, int, int);//初始化并open new file
	~frandom();//析构函数，关闭文件
	void open(const char*, int, int, int);//open new file
	void open(const char*);//open exsting file
	void close();//文件关闭
	long get_slots()const { return slots; }//获得文件可容纳的记录总数
	long get_key_size()const { return key_size; }//关键字的长度
	long get_total_bytes()const { return total_bytes; }//当前文件的总字节数
	long get_no_records()const { return no_records; }//已存储的记录数
	bool add_record(char*);//添加关键字
	bool find_record(char*);//查找关键字
	bool remove_record(char*);//删除关键字
private:
	//文件头信息
	long slots;//文件可容纳的记录总数
	long record_size;//实际的记录大小，包含标识符
	long key_size;//关键字的长度
	long total_bytes;//文件的总字节数

	long no_records;//已存储的记录数
	long loc_address; //记录可存储位置
	char* buffer;//存储一条记录
	char* stored_key; //存储关键字（带null)
	long get_address(const char*)const;
	bool locate(char*);
};

//检查文件是否打开,析构函数 
frandom::~frandom() {
	if (is_open())//fstream内库函数
	{
		//删除动态分配的存储区
		delete[] stored_key;
		delete[] buffer;
		char buff[header_size];
		for (int i = 0; i < header_size; i++)
			buff[i] = ' ';
		//写入更新过的文件头
		sprintf(buff, "%ld %ld %ld %ld", slots, record_size, key_size, no_records);
		seekp(0, ios_base::beg);
		write(buff, header_size);
	}
}

//初始化成员数据
frandom::frandom() :fstream() {
	buffer = stored_key = 0;
	slots = record_size = key_size = 0;
	total_bytes = no_records = 0;
}

//默认构造函数创建对象 
frandom::frandom(const char* filename) : fstream() {
	buffer = stored_key = 0;
	open(filename);
}

//创建新文件，并对象与新文件连接起来
frandom::frandom(const char* filename, int s1, int actual_record_size, int ks) :fstream() {
	buffer = stored_key = 0;
	open(filename, s1, actual_record_size, ks);
}

//打开已存在的文件
void frandom::open(const char* filename)
{
	fstream::open(filename, ios::in | ios::out | ios::binary);
	if (is_open())
	{
		//文件头
		char buff[header_size];
		read(buff, header_size);

		//sscanf从固定如数组中读取内容而不是流中
		sscanf(buff, "%ld %ld %ld %ld", &slots, &record_size, &key_size, &no_records);
		total_bytes = slots * record_size + header_size;//字节总数计算
		stored_key = new char[key_size + 1];//开辟每一个可存储的记录大小
		buffer = new char[record_size];
	}
}

//打开新文件
void frandom::open(const char* filename, int s1, int actual_record_size, int ks)
{
	fstream::open(filename, ios::in | ios::out | ios::binary);

	//文件存在
	if (is_open()) {
		setstate(ios::failbit);
		fstream::close();
		return;
	}

	//打开失败时，创建新的文件
	fstream::open(filename, ios::out | ios::binary);
	if (is_open())
		fstream::close();
	fstream::open(filename, ios::in | ios::out | ios::binary);
	if (is_open()) {
		//初始化操作
		clear();
		char buff[header_size];
		slots = s1;
		record_size = actual_record_size + 1;
		key_size = ks;
		total_bytes = slots * record_size + header_size;
		no_records = 0;

		//为关键字分配空间
		stored_key = new char[key_size + 1];
		for (int i = 0; i < header_size; i++)
			buff[i] = ' ';

		//填写文件头信息 
		sprintf(buff, "%ld %ld %ld %ld", slots, record_size, key_size, no_records);
		write(buff, header_size);

		//为记录创建存储区
		buffer = new char[record_size];
		for (int i = 1; i < record_size; i++)
			buffer[i] = ' ';
		buffer[0] = Free;//初始化
		for (int i = 0; i < slots; i++)//注意此处必须写入规定大小的字符串，否则会影响后续的bit统计
			write(buffer, record_size);
	}
}

long frandom::get_address(const char* key)const {
	memcpy(stored_key, key, key_size);//拷贝关键字stored_key <- key
	stored_key[key_size] = '\0';
	return (atol(stored_key) % slots) * record_size + header_size;//计算哈希初始地址
}

//搜寻记录
bool frandom::locate(char* key) {
	long address, start_address, unocc_address;
	int delete_flag = false;
	address = get_address(key);//获取当前的哈希地址
	unocc_address = start_address = address;
	do {
		seekg(address, ios::beg);//定位到当前的地址
		switch (get()) {//读取文件中当前位置的字符但不删除
		case Deleted:
			if (!delete_flag) {
				unocc_address = address;
				delete_flag = true;
			}
			break;
		case Free:
			loc_address = delete_flag ? unocc_address : address;
			return false;
		case Taken:
			seekg(address + 1, ios::beg);
			read(stored_key, key_size);
			if (memcmp(key, stored_key, key_size) == 0) {
				loc_address = address;
				return true;
			}
			break;
		}
		address += record_size;
		if (address >= total_bytes)//实现查找循环，因为是哈希表存储
			address = header_size;
	} while (address != start_address);
	loc_address = unocc_address;
	return false;//没有找到
}

bool frandom::add_record(char* record) {
	//实际记录数已经到达极限时或者已经存在该词条 
	if (no_records >= slots || locate(record))
		return false;

	//查找位置 
	seekp(loc_address, ios::beg);

	//写入标记符 T
	write(&Taken, 1);

	//写入存储的字符信息
	write(record, record_size - 1);

	//记录条数加一
	no_records++;

	//添加成功
	return true;
}

bool frandom::find_record(char* record) {
	//定位
	if (locate(record)) {
		seekg(loc_address + 1, ios::beg);
		//读取存储的内容
		read(record, record_size - 1);
		return true;
	}
	else
		return false;
}

bool frandom::remove_record(char* key) {
	if (locate(key)) {
		--no_records;
		seekp(loc_address, ios::beg);
		write(&Deleted, 1);//删除记录，标识符为 D
		return true;
	}
	else
		return false;
}
void frandom::close() {
	if (is_open()) {
		delete[] stored_key;//清空缓存数组
		delete[] buffer;
		char buff[header_size];
		for (int i = 0; i < header_size; i++)
			buff[i] = ' ';
		sprintf(buff, "%ld %ld %ld %ld", slots, record_size, key_size, no_records);
		seekp(0, ios::beg);
		write(buff, header_size);
		fstream::close();
	}
}
int main()
{
	char b[10], c;
	frandom findout;
	remove("data.dat");
	cout << "New file(Y/N)?";
	cin >> c;
	if (toupper(c) == 'Y') {
		findout.open("data.dat", 15, 5, 3);
		if (!findout) {
			cerr << "Couldn't open file" << endl;
			return EXIT_FAILURE;
		}
	}
	else {
		findout.open("data.dat");
		if (!findout) {
			cerr << "Couldn't open file" << endl;
			return EXIT_FAILURE;
		}
	}
	do {
		cout << "\n\n[A]dd\n[F]ind\n[R]emove\n[Q]uit?";
		cin >> c;
		switch (toupper(c))
		{
		case 'A':
			cout << "Which record to add?";
			cin >> b;
			if (findout.add_record(b))
				cout << "Record added" << endl;
			else
				cout << "Record  not added" << endl;
			break;
		case 'F':
			cout << "key?";
			cin >> b;
			if (findout.find_record(b)) {
				b[5] = '\0';
				cout << "Record found:" << b << endl;
			}
			else
				cout << "Record  not found" << endl;
			break;
		case 'R':
			cout << "key?";
			cin >> b;
			if (findout.remove_record(b))
				cout << "Record removed：" << b << endl;
			else
				cout << "Record  not removed" << endl;
			break;
		case 'Q':
			break;
		default:
			cout << "Illegal choice" << endl;
			break;
		}
	} while (toupper(c) != 'Q');
	system("pause");
}
