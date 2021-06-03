#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
#include "util.h"  //自定义的头文件
using namespace util;   //使用自定义的名空间
using namespace std;

int main()
{
	int a; 
	double b;
	cout << "请输入一个int型和一个double型数据（以空格分离）：";
	cin >> a >> b;
	int temp_a = a;
	double temp_b = b;

	int aa = cube(a);
	double bb = cube(b);

	cout << temp_a << "的平方为：" << aa << endl;
	cout << temp_b << "的平方为：" << bb << endl;

	return 0;
}