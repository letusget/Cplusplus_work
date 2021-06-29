#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<vector>
using namespace std;
class ReadFile
{
public:
	//存放文章数据
	map<int, vector<string>>mFile;
	//存放文件名
	map<int, string>mFileName;
	//构造函数
	ReadFile();
	//读取文件
	void read();
	//重载[]
	void operator[](int i);
};
ReadFile::ReadFile()
{
	this->mFileName.insert(make_pair(1, "1.txt"));
	this->mFileName.insert(make_pair(2, "2.txt"));
	this->mFileName.insert(make_pair(3, "3.txt"));
	this->mFileName.insert(make_pair(4, "4.txt"));
	this->mFileName.insert(make_pair(5, "5.txt"));
	cout << "文件名获取成功!" << endl;
}
void ReadFile::read()
{
	for (int i = 1; i <= 5; i++)
	{
		ifstream ifs;
		ifs.open(this->mFileName[i], ios::in); 
			if (!ifs.is_open())
			{
				cout << "文件为空或者打开失败!" << endl;
				cout << " 请 检 查 同 目 录 下 文 件 是 否 存在!" << endl;
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
	cout << "读取文本成功!" << endl;
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
		cout << "请输入要访问的文件下标(1-5)或者退出(0):";
		int n;
		cin >> n;
		if (n >= 1 && n <= 5)
			rf[n];
		else if (n == 0)
		{
			cout << " 下 标 越 界 1. 重 新 输 入 2. 退 出" << endl;
				int choice;
			cin >> choice; 
				if (choice == 1)
					continue;
				else
				{
					cout << "退出!bye" << endl;
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