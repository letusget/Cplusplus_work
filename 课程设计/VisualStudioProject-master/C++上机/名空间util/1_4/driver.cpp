#include <iostream>
#include "util.h"

using namespace std;
using namespace util;

int main() {
	int n_side;
	double d_side;

	cout << "������һ��������һ��˫���ȸ�������" << endl;
	cin >> n_side;
	cin >> d_side;

	cout << "��������ƽ��Ϊ��" << endl;
	cout << square(n_side) << endl;
	cout << square(d_side) << endl;
	
	return 0;
}