#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

template<typename T>
T cube(T a)
{
	cout << "函数模板" << endl;
	return a*a;
}

int main()
{
	int a;
	double b;
	cout << "请输入一个int型和一个double型数据（以空格分离）：" ;
	cin >> a >> b;
	int temp_a = a;
	int temp_b = b;

	int aa=cube(a);
	int bb=cube(b);

	cout << temp_a << "的平方为：" << aa << endl;
	cout << temp_b << "的平方为：" << bb << endl;
	
	return 0;
}