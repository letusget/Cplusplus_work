#include<cstdio>
#include"doublelong.h"
using namespace std;

int main() {
	doublelong x1, x2;
	doublelong y;
	cin >> x1 >> x2;
	y = x1 + x2;
	cout << "x1+x2:" << y << endl;
	y = x1 - x2;
	cout << "x1-x2:" << y << endl;
	y = x1 * x2;
	cout << "x1*x2:" << y << endl;
	y = x1 / x2;
	cout << "x1/x2:" << y << endl;
	x1 += x2;
	cout << "x1+=x2:" << x1 << endl;
	x1 -= x2;
	cout << "x1-=x2:" << x1 << endl;
	x1 *= x2;
	cout << "x1*=x2:" << x1 << endl;
	x1 /= x2;
	cout << "x1/=x2:" << x1 << endl;

	return 0;

}
