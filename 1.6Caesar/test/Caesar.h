#pragma once
#include <iostream>
#include <string>
using namespace std;
#define size 32   //�޶�ÿ��������ַ����ĳ���
#define len 56  //���뱾�ĳ���
#define key 4   //��Կ����

class CCaesar
{
private:
	static CCaesar* instance;  //��������һ�������ָ��
	CCaesar()
	{
		//cout << "����һ����������" << endl;
	}
	~CCaesar()
	{
		//cout << "����һ����������" << endl;
	}


public:
	static CCaesar* getinstance();
	static void menu();  //

	static char code[len];

	static void init_Code();  //��ʼ�����뱾
	
	static void print_Code();  //������ʾ�����
	
	static char* Encrypt(char* conse1);  //���ܺ���
	static char* Decrypt(char* conse2);  //���ܺ���


	static void deleteCaesar();  //�������������������Ϊ����Ĺ����������������˽�еģ�������Ҫ�ֶ��ͷ���

};



