#include<cstdio>
#include"doublelong.h"
using namespace std;

int main() {
	doublelong x1, x2;
	doublelong y;
	cout << "���������������ÿո�������" << endl;
	cin >> x1 >> x2;

	y = x1 + x2;
	cout << "+ ���� x1+x2:" << y << endl;
	cout << endl;

	y = x1 - x2;
	cout << "- ���� x1-x2:" << y << endl;
	cout << endl;

	y = x1 * x2;
	cout << "* ���� x1*x2:" << y << endl;
	cout << endl;

	y = x1 / x2;
	cout << "/ ���� �������x1/x2:" << y << endl;
	cout << endl;

	x1 += x2;
	cout << "+= ���� x1+=x2:" << x1 << endl;
	cout << endl;

	x1 -= x2;
	cout << "-= ���� x1-=x2:" << x1 << endl;
	cout << endl;

	x1 *= x2;
	cout << "*= ���� x1*=x2:" << x1 << endl;
	cout << endl;

	x1 /= x2;
	cout << "/= ���� x1/=x2:" << x1 << endl;
	cout << endl;

	return 0;

}
