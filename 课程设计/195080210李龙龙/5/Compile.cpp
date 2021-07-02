#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<fstream> 
#include<cstdlib>
#include<vector>

using namespace std;

//��ʼ���������������ļ���ȡ�ı�����
void initial(vector<string>& text)
{
	ifstream infile("�����ļ�.txt");			//����Ϊ�������ļ������ж�����
	if (!infile)							//���ڼ�������ļ��Ƿ���ڣ�infile�䵱һ��handle
	{
		cout << "open error" << endl;  //�ļ���ʧ�ܻ򲻴���ʱ���������ʾ
		exit(0);
	}
	string temp;
	while (getline(infile, temp))
	{
		text.push_back(temp);				//��temp������ļ�����
	}
	infile.close();							//�ر��ļ�
}
void showtext(vector<string>& text)
{
	int m, n;
	scanf("%d%d", &m, &n);
	//cin >> m, n;
	printf("��%d�е���%d�е��ı�Ϊ��\n", m, n);
	for (int i = m - 1; i < n; i++)
		cout << text[i] << endl;

}
void insert(vector<string>& text)
{
	int m;
	scanf("%d\n", &m);
	//cin >> m;
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
	//cin >> m, n;
	text.erase(text.begin() + m - 1, text.begin() + n);
	for (int i = 0; i < text.size(); i++)
		cout << text[i] << endl;
}
void Replace(vector<string>& text)
{
	int m, n;
	scanf("%d%d\n", &m, &n);
	//cin >> m, n;

	int t = m - 1; 
	//����ļ�����
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
	ofstream outfile("����ļ�.txt", ios::out);
	if (!outfile)
	{
		cout << "open error" << endl;
		exit(0);
	}
	for (int i = 0; i < text.size(); i++)
		outfile << text[i] << endl;
	outfile.close();
	exit(0);
}
void Quit(vector<string>& text)
{//ֱ���˳�
	initial(text);
	exit(0);
}
int main()
{	
	vector<string>text;
	initial(text);		//�������ļ��ж�ȡ����
	for (int i = 0; i < text.size(); i++)
		cout << text[i] << endl;
	string command;		//�༭�����
	cout << "������༭���" << endl;
	while (cin >> command)	//��ȡ�༭����
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