#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<fstream> 
#include<cstdlib>
#include<vector>

using namespace std;

//初始化容器，从输入文件获取文本内容
void initial(vector<string>& text)
{
	ifstream infile("输入文件.txt");			//打开名为“输入文件”进行读操作
	if (!infile)							//用于检测输入文件是否存在，infile充当一个handle
	{
		cout << "open error" << endl;
		exit(0);
	}
	string temp;
	while (getline(infile, temp))
	{
		text.push_back(temp);				//向temp中添加元素
	}
	infile.close();							//关闭文件
}
void showtext(vector<string>& text)
{
	int m, n;
	scanf("%d%d", &m, &n);
	printf("第%d行到第%d行的文本为：\n", m, n);
	for (int i = m - 1; i < n; i++)
		cout << text[i] << endl;

}
void insert(vector<string>& text)
{
	int m;
	scanf("%d\n", &m);
	int t = m;
	string temp;
	while (getline(cin, temp))
	{
		if (temp == "^Z")
			break;
		text.insert(text.begin() + t, temp);
		t++;
	}
	for (int i = 0; i < text.size(); i++)
		cout << text[i] << endl;
}
void Delete(vector<string>& text)
{
	int m, n;
	scanf("%d%d", &m, &n);
	text.erase(text.begin() + m - 1, text.begin() + n);
	for (int i = 0; i < text.size(); i++)
		cout << text[i] << endl;
}
void Replace(vector<string>& text)
{
	int m, n;
	scanf("%d%d\n", &m, &n);
	int t = m - 1;
	text.erase(text.begin() + t, text.begin() + n);
	string temp;
	while (getline(cin, temp))
	{
		if (temp == "^Z")
			break;
		text.insert(text.begin() + t, temp);
		t++;
	}
	for (int i = 0; i < text.size(); i++)
		cout << text[i] << endl;
}
void SaveQuit(vector<string>& text)
{
	ofstream outfile("输出文件.txt", ios::out);
	if (!outfile)
	{
		cout << "open error" << endl;
		exit(0);
	}
	for (int i = 0; i < text.size(); i++)
		outfile << text[i] << endl;
	outfile.close();
}
void Quit(vector<string>& text)
{
	initial(text);
}
int main()
{	
	vector<string>text;
	initial(text);		//从输入文件中读取数据
	for (int i = 0; i < text.size(); i++)
		cout << text[i] << endl;
	string command;		//编辑命令处理
	cout << "请输入编辑命令：" << endl;
	while (cin >> command)	//获取编辑命令
	{
		if (command == "*L")
			showtext(text);
		if (command == "*l")
			insert(text);
		if (command == "*D")
			Delete(text);
		if (command == "*R")
			Replace(text);
		if (command == "*X")
			SaveQuit(text);
		if (command == "*Q")
			Quit(text);
	}
	return 0;
}