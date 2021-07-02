#include<cstdio>
#include"doublelong.h"
using namespace std;

int main() {
	doublelong x1, x2;
	doublelong y;
	cout << "请输入两个数（用空格间隔）：" << endl;
	cin >> x1 >> x2;

	y = x1 + x2;
	cout << "+ 运算 x1+x2:" << y << endl;
	cout << endl;

	y = x1 - x2;
	cout << "- 运算 x1-x2:" << y << endl;
	cout << endl;

	y = x1 * x2;
	cout << "* 运算 x1*x2:" << y << endl;
	cout << endl;

	y = x1 / x2;
	cout << "/ 运算 两数相除x1/x2:" << y << endl;
	cout << endl;

	x1 += x2;
	cout << "+= 运算 x1+=x2:" << x1 << endl;
	cout << endl;

	x1 -= x2;
	cout << "-= 运算 x1-=x2:" << x1 << endl;
	cout << endl;

	x1 *= x2;
	cout << "*= 运算 x1*=x2:" << x1 << endl;
	cout << endl;

	x1 /= x2;
	cout << "/= 运算 x1/=x2:" << x1 << endl;
	cout << endl;

	return 0;

}
