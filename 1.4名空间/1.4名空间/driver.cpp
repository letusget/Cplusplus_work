#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
#include "util.h"  //�Զ����ͷ�ļ�
using namespace util;   //ʹ���Զ�������ռ�
using namespace std;

int main()
{
	int a; 
	double b;
	cout << "������һ��int�ͺ�һ��double�����ݣ��Կո���룩��";
	cin >> a >> b;
	int temp_a = a;
	double temp_b = b;

	int aa = cube(a);
	double bb = cube(b);

	cout << temp_a << "��ƽ��Ϊ��" << aa << endl;
	cout << temp_b << "��ƽ��Ϊ��" << bb << endl;

	return 0;
}