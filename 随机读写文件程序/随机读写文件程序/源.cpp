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
	frandom(const char*);//��ʼ����open exsiting file
	frandom(const char*, int, int, int);//��ʼ����open new file
	~frandom();//�����������ر��ļ�
	void open(const char*, int, int, int);//open new file
	void open(const char*);//open exsting file
	void close();//�ļ��ر�
	long get_slots()const { return slots; }//����ļ������ɵļ�¼����
	long get_key_size()const { return key_size; }//�ؼ��ֵĳ���
	long get_total_bytes()const { return total_bytes; }//��ǰ�ļ������ֽ���
	long get_no_records()const { return no_records; }//�Ѵ洢�ļ�¼��
	bool add_record(char*);//��ӹؼ���
	bool find_record(char*);//���ҹؼ���
	bool remove_record(char*);//ɾ���ؼ���
private:
	//�ļ�ͷ��Ϣ
	long slots;//�ļ������ɵļ�¼����
	long record_size;//ʵ�ʵļ�¼��С��������ʶ��
	long key_size;//�ؼ��ֵĳ���
	long total_bytes;//�ļ������ֽ���

	long no_records;//�Ѵ洢�ļ�¼��
	long loc_address; //��¼�ɴ洢λ��
	char* buffer;//�洢һ����¼
	char* stored_key; //�洢�ؼ��֣���null)
	long get_address(const char*)const;
	bool locate(char*);
};

//����ļ��Ƿ��,�������� 
frandom::~frandom() {
	if (is_open())//fstream�ڿ⺯��
	{
		//ɾ����̬����Ĵ洢��
		delete[] stored_key;
		delete[] buffer;
		char buff[header_size];
		for (int i = 0; i < header_size; i++)
			buff[i] = ' ';
		//д����¹����ļ�ͷ
		sprintf(buff, "%ld %ld %ld %ld", slots, record_size, key_size, no_records);
		seekp(0, ios_base::beg);
		write(buff, header_size);
	}
}

//��ʼ����Ա����
frandom::frandom() :fstream() {
	buffer = stored_key = 0;
	slots = record_size = key_size = 0;
	total_bytes = no_records = 0;
}

//Ĭ�Ϲ��캯���������� 
frandom::frandom(const char* filename) : fstream() {
	buffer = stored_key = 0;
	open(filename);
}

//�������ļ��������������ļ���������
frandom::frandom(const char* filename, int s1, int actual_record_size, int ks) :fstream() {
	buffer = stored_key = 0;
	open(filename, s1, actual_record_size, ks);
}

//���Ѵ��ڵ��ļ�
void frandom::open(const char* filename)
{
	fstream::open(filename, ios::in | ios::out | ios::binary);
	if (is_open())
	{
		//�ļ�ͷ
		char buff[header_size];
		read(buff, header_size);

		//sscanf�ӹ̶��������ж�ȡ���ݶ���������
		sscanf(buff, "%ld %ld %ld %ld", &slots, &record_size, &key_size, &no_records);
		total_bytes = slots * record_size + header_size;//�ֽ���������
		stored_key = new char[key_size + 1];//����ÿһ���ɴ洢�ļ�¼��С
		buffer = new char[record_size];
	}
}

//�����ļ�
void frandom::open(const char* filename, int s1, int actual_record_size, int ks)
{
	fstream::open(filename, ios::in | ios::out | ios::binary);

	//�ļ�����
	if (is_open()) {
		setstate(ios::failbit);
		fstream::close();
		return;
	}

	//��ʧ��ʱ�������µ��ļ�
	fstream::open(filename, ios::out | ios::binary);
	if (is_open())
		fstream::close();
	fstream::open(filename, ios::in | ios::out | ios::binary);
	if (is_open()) {
		//��ʼ������
		clear();
		char buff[header_size];
		slots = s1;
		record_size = actual_record_size + 1;
		key_size = ks;
		total_bytes = slots * record_size + header_size;
		no_records = 0;

		//Ϊ�ؼ��ַ���ռ�
		stored_key = new char[key_size + 1];
		for (int i = 0; i < header_size; i++)
			buff[i] = ' ';

		//��д�ļ�ͷ��Ϣ 
		sprintf(buff, "%ld %ld %ld %ld", slots, record_size, key_size, no_records);
		write(buff, header_size);

		//Ϊ��¼�����洢��
		buffer = new char[record_size];
		for (int i = 1; i < record_size; i++)
			buffer[i] = ' ';
		buffer[0] = Free;//��ʼ��
		for (int i = 0; i < slots; i++)//ע��˴�����д��涨��С���ַ����������Ӱ�������bitͳ��
			write(buffer, record_size);
	}
}

long frandom::get_address(const char* key)const {
	memcpy(stored_key, key, key_size);//�����ؼ���stored_key <- key
	stored_key[key_size] = '\0';
	return (atol(stored_key) % slots) * record_size + header_size;//�����ϣ��ʼ��ַ
}

//��Ѱ��¼
bool frandom::locate(char* key) {
	long address, start_address, unocc_address;
	int delete_flag = false;
	address = get_address(key);//��ȡ��ǰ�Ĺ�ϣ��ַ
	unocc_address = start_address = address;
	do {
		seekg(address, ios::beg);//��λ����ǰ�ĵ�ַ
		switch (get()) {//��ȡ�ļ��е�ǰλ�õ��ַ�����ɾ��
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
		if (address >= total_bytes)//ʵ�ֲ���ѭ������Ϊ�ǹ�ϣ��洢
			address = header_size;
	} while (address != start_address);
	loc_address = unocc_address;
	return false;//û���ҵ�
}

bool frandom::add_record(char* record) {
	//ʵ�ʼ�¼���Ѿ����Ｋ��ʱ�����Ѿ����ڸô��� 
	if (no_records >= slots || locate(record))
		return false;

	//����λ�� 
	seekp(loc_address, ios::beg);

	//д���Ƿ� T
	write(&Taken, 1);

	//д��洢���ַ���Ϣ
	write(record, record_size - 1);

	//��¼������һ
	no_records++;

	//��ӳɹ�
	return true;
}

bool frandom::find_record(char* record) {
	//��λ
	if (locate(record)) {
		seekg(loc_address + 1, ios::beg);
		//��ȡ�洢������
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
		write(&Deleted, 1);//ɾ����¼����ʶ��Ϊ D
		return true;
	}
	else
		return false;
}
void frandom::close() {
	if (is_open()) {
		delete[] stored_key;//��ջ�������
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
				cout << "Record removed��" << b << endl;
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
