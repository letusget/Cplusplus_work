#pragma once
#include <iostream>
#include <string>

using namespace std;

#define size 32
#define len 56
#define key 4

class CCaesar {
private:
	static CCaesar* instance;  //��������һ�������ָ��
	CCaesar() {
		cout << "����һ����������" << endl;
	}
	~CCaesar() {
		cout << "����һ����������" << endl;
	}

public:
	static CCaesar* getinstance(); // Ψһʾ������

	static void menu(); // ��ʾ�˵�

	static char code[len]; // ���뱾
	static void init_Code(); // ��ʼ�����뱾
	static void print_Code();  //������ʾ���뱾

	static char* Encrypt(char* conse1);  //���ܺ���
	static char* Decrypt(char* conse2);  //���ܺ���

	static void deleteCaesar(); // ɾ����������
};
