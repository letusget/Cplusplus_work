#pragma once
#include <iostream>

using namespace std;

void swap_v(int a, int b)
{
	int t = a;
	a = b;
	b = t;
}

void swap_r(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void swap_p(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void swap_o(int &a, int &b)
{
	a ^= b;
	b ^= a;
	a ^= b;

}

int main()
{
	int a = 10, b = 20;
	cout << "a = " << a << ", b = " << b << "\n";

	swap_r(a, b);
	cout << "swap_r\ta = " << a << ", b = " << b << "\n";

	swap_v(a, b);
	cout << "swap_v\ta = " << a << ", b = " << b << "\n";

	swap_p(&a, &b);
	cout << "swap_p\ta = " << a << ", b = " << b << "\n";

	swap_o(a, b);
	cout << "swap_o\ta = " << a << ", b = " << b << "\n";

	return 0;
}