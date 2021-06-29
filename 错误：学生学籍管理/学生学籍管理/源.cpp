#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

bool optNext();

//����student�࣬�洢ѧ����Ϣ
class student {
public:
	//���캯��
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
	//��ȡѧ����Ϣ
	//ͨ��public���ͺ�������private���͵�ѧ������
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

	//���������
	friend bool disbyID(long);
	friend bool disbyName(string&);
	friend bool add();
	friend bool avgSc();
	friend bool resSc();
	friend bool readFile(fstream& infile);
	friend bool saveFile(ofstream&);
private:
	//����ѧ������
	string name;
	long stuID;
	string sex;
	int enSc;
	int maSc;
	int prSc;
	int peSc;
};


//���ѧ����Ϣ������ѧ����Ϣ
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
	bool emptyCheck = true; //��־�ļ�Ϊ��
	it = vec.begin();
	while (it != vec.end())
	{
		if (!emptyCheck)  //�����ļ�
			outfile << endl;  //����ǿ��ļ�����ӻس�������������ӻس����������һ��ѧ������
		outfile << it->name << " " << it->stuID << " " << it->sex
			<< " " << it->enSc << " " << it->maSc << " " << it->prSc << " " << it->peSc;
		it++;
		emptyCheck = false;  //��־�ļ���Ϊ��
	}
	return true;
}
//ͨ��ѧ�Ų���ѧ������
bool disbyID(long id) {
	it = vec.begin();
	do {
		if (it->stuID == id)  //����ҵ���ѧ�ŷ��ϵ�ѧ���������������������
		{
			cout << it->name << " " << it->stuID << " " << it->sex << " " << it->enSc << " " << it->maSc << " " << it->prSc << " " << it->peSc << endl;
			break;
		}
		else it++;
	} while (it != vec.end());

	if (it == vec.end())  //����鵽���һ������Ҳû���ҵ����ϵ�ѧ�������������Ϣ
	{
		cout << "û���ҵ����ϵ�ѧ��ID!" << endl;
	}
	return true;
}

//ͨ��ѧ����������ѧ������
bool disbyName(string& name) {
	it = vec.begin();
	do {
		if (it->name == name)  //����ҵ����������ϵ�ѧ���������������������
		{
			cout << it->name << " " << it->stuID << " " << it->sex << " " << it->enSc << " " << it->maSc << " " << it->prSc << " " << it->peSc << endl;
			break;
		}
		else it++;
	} while (it != vec.end());

	if (it == vec.end())  //����鵽���һ������Ҳû���ҵ����ϵ�ѧ�������������Ϣ
	{
		cout << "û���ҵ����ϵ�ѧ������!" << endl;
	}
	return true;
}
//���һ���µ�ѧ������
bool add() {
	string name;
	long stuID;
	string sex;
	int enSc;
	int maSc;
	int peSc;
	int prSc;

	cout << "������ѧ����Ϣ: " << endl;
	cout << "name: ";
	cin >> name;
	cout << "ѧ�� ID: ";
	cin >> stuID;
	cout << "ѧ�� �Ա�[��/Ů]: ";
	cin >> sex;
	cout << "ѧ��Ӣ��ɼ�: ";
	cin >> enSc;
	cout << "ѧ����ѧ�ɼ�: ";
	cin >> maSc;
	cout << "ѧ��������Ƴɼ�: ";
	cin >> prSc;
	cout << "ѧ�������ɼ�: ";
	cin >> peSc;

	//������ӵ�ѧ������ѹջ��vector
	vec.push_back(student(name, stuID, sex, enSc, maSc, prSc, peSc));
	return true;
}


//����ѧ��ÿһ��ƽ���ɼ�
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

	cout << "Ӣ��: " << avgEn << "  ��ѧ: " << avgMa << "  �������: " << avgPr << "  ����: " << avgPe << endl;
	return true;
}

//���ո��ųɼ����򷽷�
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

//�����ųɼ���������ļ�
bool resSc()
{
	ofstream outfile_en("English.dat", ios::out);  //��English.dat�ļ�������������
	if (!outfile_en) {
		cout << "open error!" << endl;  //��ʧ���򱨴�
		exit(1);
	}
	sort(vec.begin(), vec.end(), cmpEnglish);  //����Ӣ��ɼ�����
	vector<student>::iterator iter_en;
	for (iter_en = vec.begin(); iter_en != vec.end(); iter_en++)  //������ļ�
	{
		outfile_en << iter_en->name << " " << iter_en->stuID 
			<< " " << iter_en->sex << " " << iter_en->enSc 
			<< " " << iter_en->maSc << " " << iter_en->prSc 
			<< " " << iter_en->peSc << endl;
	}
	outfile_en.close();  //�ر�������


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
	while (exit_ck) {  //ѭ���ṹ����ѡ��ÿ��ѡ����ٴ�ִ����һ��
		cout << "A:��ѯѧ��ID" << endl;
		cout << "B:��ѯѧ������" << endl;
		cout << "C:ͳ��ƽ���ɼ�" << endl;
		cout << "D:�ɼ����浽�ļ�" << endl;
		cout << "X:�˳�" << endl;
		cin >> opt2;
		if (opt2 == "A") {
			long sID;
			cout << "������ѧ��ID: " << endl;
			cin >> sID;
			disbyID(sID);
		}
		if (opt2 == "B") {
			string sName;
			cout << "������ѧ������: " << endl;
			cin >> sName;
			disbyName(sName);
		}
		if (opt2 == "C") {
			avgSc();
		}
		if (opt2 == "D") {
			resSc();
		}
		if (opt2 == "X")  //����˳����ţ����´�ѭ����ʼʱ�˳�
			exit_ck = 0;
	}
	return true;
}
int main()
{
	string opt1;
	cout << "A:��ȡѧ����Ϣ" << endl;
	cout << "B:�½�ѧ����Ϣ" << endl;

	cin >> opt1;

	if (opt1 == "A") //read from existed file
	{
		cout << "����ѧ����Ϣ��ȡ�ļ�: " << endl;
		string fileName1;
		cin >> fileName1;

		fstream infile(fileName1);
		if (!infile) {
			cout << "�ļ���ʧ��!" << endl;
			exit(0);
		}
		readFile(infile);
		optNext();
	}

	else if (opt1 == "B") {  //enter new student data
		cout << "��������ӵ�ѧ������: " << endl;
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			add();
		cout << "��Ϣ��ӳɹ��������뱣����ļ���: ";
		string fileName2;
		cin >> fileName2;
		ofstream outFile(fileName2, fstream::trunc | fstream::out);
		cout << "������......" << endl;
		saveFile(outFile);
		cout << "����ɹ�!" << endl;
		outFile.close();
		optNext();
	}

	return 0;
}
