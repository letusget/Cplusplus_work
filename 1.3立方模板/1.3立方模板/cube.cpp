#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

template<typename T>
T cube(T a)
{
	cout << "����ģ��" << endl;
	return a*a;
}

int main()
{
	int a;
	double b;
	cout << "������һ��int�ͺ�һ��double�����ݣ��Կո���룩��" ;
	cin >> a >> b;
	int temp_a = a;
	int temp_b = b;

	int aa=cube(a);
	int bb=cube(b);

	cout << temp_a << "��ƽ��Ϊ��" << aa << endl;
	cout << temp_b << "��ƽ��Ϊ��" << bb << endl;
	
	return 0;
}