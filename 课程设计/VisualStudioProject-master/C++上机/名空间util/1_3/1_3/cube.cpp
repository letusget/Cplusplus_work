#include <iostream>

using namespace std;

// 模板函数求立方
template <class T>
T cube(T side) {
	return side*side*side;
}

int main() {
	int n_side;
	double d_side;

	cout << "请输入一个整数和小数：" << endl;
	cin >> n_side;
	cin >> d_side;

	cout << "立方分别为：" << endl;
	cout << cube(n_side) << endl;
	cout << cube(d_side) << endl;

	return 0;
}