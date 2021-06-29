#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<vector>
using namespace std;
class ReadFile
{
public:
	//�����������
	map<int, vector<string>>mFile;
	//����ļ���
	map<int, string>mFileName;
	//���캯��
	ReadFile();
	//��ȡ�ļ�
	void read();
	//����[]
	void operator[](int i);
};
ReadFile::ReadFile()
{
	this->mFileName.insert(make_pair(1, "1.txt"));
	this->mFileName.insert(make_pair(2, "2.txt"));
	this->mFileName.insert(make_pair(3, "3.txt"));
	this->mFileName.insert(make_pair(4, "4.txt"));
	this->mFileName.insert(make_pair(5, "5.txt"));
	cout << "�ļ�����ȡ�ɹ�!" << endl;
}
void ReadFile::read()
{
	for (int i = 1; i <= 5; i++)
	{
		ifstream ifs;
		ifs.open(this->mFileName[i], ios::in); 
			if (!ifs.is_open())
			{
				cout << "�ļ�Ϊ�ջ��ߴ�ʧ��!" << endl;
				cout << " �� �� �� ͬ Ŀ ¼ �� �� �� �� �� ����!" << endl;
			}
		vector<string>vTemp;
		string str;
		while (getline(ifs, str))
		{
			vTemp.push_back(str);
		}
		this->mFile.insert(make_pair(i, vTemp));
		vTemp.clear();
		ifs.close();
	}
	cout << "��ȡ�ı��ɹ�!" << endl;
}
void ReadFile::operator[](int i)
{
	for (string str : this->mFile[i])
	{
		cout << str << endl;
	}
}
void test()
{
	ReadFile rf;
	rf.read();
	while (true)
	{
		cout << "������Ҫ���ʵ��ļ��±�(1-5)�����˳�(0):";
		int n;
		cin >> n;
		if (n >= 1 && n <= 5)
			rf[n];
		else if (n == 0)
		{
			cout << " �� �� Խ �� 1. �� �� �� �� 2. �� ��" << endl;
				int choice;
			cin >> choice; 
				if (choice == 1)
					continue;
				else
				{
					cout << "�˳�!bye" << endl;
					exit(0);
				}
		}
	}
}
int main()
{
	test();
	return 0;
}