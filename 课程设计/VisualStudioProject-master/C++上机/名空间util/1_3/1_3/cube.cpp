#include <iostream>

using namespace std;

// ģ�庯��������
template <class T>
T cube(T side) {
	return side*side*side;
}

int main() {
	int n_side;
	double d_side;

	cout << "������һ��������С����" << endl;
	cin >> n_side;
	cin >> d_side;

	cout << "�����ֱ�Ϊ��" << endl;
	cout << cube(n_side) << endl;
	cout << cube(d_side) << endl;

	return 0;
}