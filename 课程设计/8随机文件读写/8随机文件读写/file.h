#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

class ReadFile
{
public:
	//��ȡ��������
	map<int, vector<string>>mFile;
	//����ļ���
	map<int, string>mFileName;
	//���캯��
	ReadFile();
	//��ȡ�ļ�
	void read();
	//���ز�������ʵ�ִ������ļ������д
	void operator[](int i);


};