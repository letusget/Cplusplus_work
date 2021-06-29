#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

bool optNext();

//定义student类，存储学生信息
class student {
public:
	//构造函数
	student(fstream&);
	student(string, long, string, int, int, int, int)
	{
		this->name = name;
		this->stuID = stuID;
		this->sex = sex;
		this->enSc = enSc;
		this->maSc = maSc;
		this->peSc = peSc;
		this->prSc = prSc;
	}
	//获取学生信息
	//通过public类型函数访问private类型的学生数据
	int getEn() {
		return enSc;
	}
	int getMa() {
		return maSc;
	}
	int getPr() {
		return prSc;
	}
	int getPe() {
		return peSc;
	}

	//定义操作类
	friend bool disbyID(long);
	friend bool disbyName(string&);
	friend bool add();
	friend bool avgSc();
	friend bool resSc();
	friend bool readFile(fstream& infile);
	friend bool saveFile(ofstream&);
private:
	//定义学生属性
	string name;
	long stuID;
	string sex;
	int enSc;
	int maSc;
	int prSc;
	int peSc;
};


//存放学生信息，遍历学生信息
vector<student> vec;
vector<student>::iterator it;

bool readFile(fstream& infile) {
	while (!infile.eof())
	{
		vec.push_back(infile);
		infile.get();
	}
	return true;
}
student::student(fstream& infile) {
	infile >> name;
	infile >> stuID;
	infile >> sex;
	infile >> enSc;
	infile >> maSc;
	infile >> prSc;
	infile >> peSc;
}
bool saveFile(ofstream& outfile) {
	bool emptyCheck = true; //标志文件为空
	it = vec.begin();
	while (it != vec.end())
	{
		if (!emptyCheck)  //读入文件
			outfile << endl;  //如果是空文件则不添加回车符，否则先添加回车符再输出下一条学生数据
		outfile << it->name << " " << it->stuID << " " << it->sex
			<< " " << it->enSc << " " << it->maSc << " " << it->prSc << " " << it->peSc;
		it++;
		emptyCheck = false;  //标志文件不为空
	}
	return true;
}
//通过学号查找学生数据
bool disbyID(long id) {
	it = vec.begin();
	do {
		if (it->stuID == id)  //如果找到了学号符合的学生数据则输出并结束查找
		{
			cout << it->name << " " << it->stuID << " " << it->sex << " " << it->enSc << " " << it->maSc << " " << it->prSc << " " << it->peSc << endl;
			break;
		}
		else it++;
	} while (it != vec.end());

	if (it == vec.end())  //如果查到最后一条数据也没有找到符合的学生则输出错误信息
	{
		cout << "没有找到符合的学生ID!" << endl;
	}
	return true;
}

//通过学生姓名查找学生数据
bool disbyName(string& name) {
	it = vec.begin();
	do {
		if (it->name == name)  //如果找到了姓名符合的学生数据则输出并结束查找
		{
			cout << it->name << " " << it->stuID << " " << it->sex << " " << it->enSc << " " << it->maSc << " " << it->prSc << " " << it->peSc << endl;
			break;
		}
		else it++;
	} while (it != vec.end());

	if (it == vec.end())  //如果查到最后一条数据也没有找到符合的学生则输出错误信息
	{
		cout << "没有找到符合的学生姓名!" << endl;
	}
	return true;
}
//添加一条新的学生数据
bool add() {
	string name;
	long stuID;
	string sex;
	int enSc;
	int maSc;
	int peSc;
	int prSc;

	cout << "请输入学生信息: " << endl;
	cout << "name: ";
	cin >> name;
	cout << "学生 ID: ";
	cin >> stuID;
	cout << "学生 性别[男/女]: ";
	cin >> sex;
	cout << "学生英语成绩: ";
	cin >> enSc;
	cout << "学生数学成绩: ";
	cin >> maSc;
	cout << "学生程序设计成绩: ";
	cin >> prSc;
	cout << "学生体育成绩: ";
	cin >> peSc;

	//将新添加的学生数据压栈入vector
	vec.push_back(student(name, stuID, sex, enSc, maSc, prSc, peSc));
	return true;
}


//计算学生每一门平均成绩
bool avgSc() {
	int i;
	float sumEn = 0, avgEn = 0;
	float sumMa = 0, avgMa = 0;
	float sumPr = 0, avgPr = 0;
	float sumPe = 0, avgPe = 0;
	it = vec.begin();
	for (i = 0; it != vec.end(); it++, i++)
	{
		sumEn += (float)it->enSc;
		sumMa += (float)it->maSc;
		sumPr += (float)it->prSc;
		sumPe += (float)it->peSc;
	}
	avgEn = sumEn / (float)i;
	avgMa = sumMa / (float)i;
	avgPr = sumPr / (float)i;
	avgPe = sumPe / (float)i;

	cout << "英语: " << avgEn << "  数学: " << avgMa << "  程序设计: " << avgPr << "  体育: " << avgPe << endl;
	return true;
}

//按照各门成绩排序方法
bool cmpEnglish(student a, student b)
{
	return a.getEn() > b.getEn();
}
bool cmpMath(student a, student b)
{
	return a.getMa() > b.getMa();
}
bool cmpProgramming(student a, student b)
{
	return a.getPr() > b.getPr();
}
bool cmpPE(student a, student b)
{
	return a.getPe() > b.getPe();
}

//按各门成绩排序并输出文件
bool resSc()
{
	ofstream outfile_en("English.dat", ios::out);  //打开English.dat文件并建立输入流
	if (!outfile_en) {
		cout << "open error!" << endl;  //打开失败则报错
		exit(1);
	}
	sort(vec.begin(), vec.end(), cmpEnglish);  //按照英语成绩排序
	vector<student>::iterator iter_en;
	for (iter_en = vec.begin(); iter_en != vec.end(); iter_en++)  //输出到文件
	{
		outfile_en << iter_en->name << " " << iter_en->stuID 
			<< " " << iter_en->sex << " " << iter_en->enSc 
			<< " " << iter_en->maSc << " " << iter_en->prSc 
			<< " " << iter_en->peSc << endl;
	}
	outfile_en.close();  //关闭输入流


	ofstream outfile_ma("Math.dat", ios::out);
	if (!outfile_ma) {
		cout << "open error!" << endl;
		exit(1);
	}
	sort(vec.begin(), vec.end(), cmpMath);
	vector<student>::iterator iter_ma;
	for (iter_ma = vec.begin(); iter_ma != vec.end(); iter_ma++)
	{
		outfile_ma << iter_ma->name << " " << iter_ma->stuID << " " << iter_ma->sex << " " << iter_ma->enSc << " " << iter_ma->maSc << " " << iter_ma->prSc << " " << iter_ma->peSc << endl;
	}
	outfile_ma.close();


	ofstream outfile_pro("Program.dat", ios::out);
	if (!outfile_pro) {
		cout << "open error!" << endl;
		exit(1);
	}
	sort(vec.begin(), vec.end(), cmpProgramming);
	vector<student>::iterator iter_pr;
	for (iter_pr = vec.begin(); iter_pr != vec.end(); iter_pr++)
	{
		outfile_pro << iter_pr->name << " " << iter_pr->stuID << " " << iter_pr->sex << " " << iter_pr->enSc << " " << iter_pr->maSc << " " << iter_pr->prSc << " " << iter_pr->peSc << endl;
	}
	outfile_pro.close();


	ofstream outfile_pe("PE.dat", ios::out);
	if (!outfile_pe) {
		cerr << "open error!" << endl;
		exit(1);
	}
	sort(vec.begin(), vec.end(), cmpPE);
	vector<student>::iterator iter_pe;
	for (iter_pe = vec.begin(); iter_pe != vec.end(); iter_pe++)
	{
		outfile_pe << iter_pe->name << " " << iter_pe->stuID << " " << iter_pe->sex << " " << iter_pe->enSc << " " << iter_pe->maSc << " " << iter_pe->prSc << " " << iter_pe->peSc << endl;
	}
	outfile_pe.close();
	cout << "output succeed!" << endl;
	return true;
}

bool optNext() {
	string opt2;
	int exit_ck = 1;
	while (exit_ck) {  //循环结构，在选择每个选项后再次执行这一步
		cout << "A:查询学生ID" << endl;
		cout << "B:查询学生姓名" << endl;
		cout << "C:统计平均成绩" << endl;
		cout << "D:成绩保存到文件" << endl;
		cout << "X:退出" << endl;
		cin >> opt2;
		if (opt2 == "A") {
			long sID;
			cout << "请输入学生ID: " << endl;
			cin >> sID;
			disbyID(sID);
		}
		if (opt2 == "B") {
			string sName;
			cout << "请输入学生姓名: " << endl;
			cin >> sName;
			disbyName(sName);
		}
		if (opt2 == "C") {
			avgSc();
		}
		if (opt2 == "D") {
			resSc();
		}
		if (opt2 == "X")  //标记退出符号，在下次循环开始时退出
			exit_ck = 0;
	}
	return true;
}
int main()
{
	string opt1;
	cout << "A:读取学生信息" << endl;
	cout << "B:新建学生信息" << endl;

	cin >> opt1;

	if (opt1 == "A") //read from existed file
	{
		cout << "输入学生信息读取文件: " << endl;
		string fileName1;
		cin >> fileName1;

		fstream infile(fileName1);
		if (!infile) {
			cout << "文件打开失败!" << endl;
			exit(0);
		}
		readFile(infile);
		optNext();
	}

	else if (opt1 == "B") {  //enter new student data
		cout << "请输入添加的学生数量: " << endl;
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			add();
		cout << "信息添加成功，请输入保存的文件名: ";
		string fileName2;
		cin >> fileName2;
		ofstream outFile(fileName2, fstream::trunc | fstream::out);
		cout << "保存中......" << endl;
		saveFile(outFile);
		cout << "保存成功!" << endl;
		outFile.close();
		optNext();
	}

	return 0;
}
