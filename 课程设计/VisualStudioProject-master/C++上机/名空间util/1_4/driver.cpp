#include <iostream>
#include "util.h"

using namespace std;
using namespace util;

int main() {
	int n_side;
	double d_side;

	cout << "请输入一个整数和一个双精度浮点数：" << endl;
	cin >> n_side;
	cin >> d_side;

	cout << "两个数的平方为：" << endl;
	cout << square(n_side) << endl;
	cout << square(d_side) << endl;
	
	return 0;
}