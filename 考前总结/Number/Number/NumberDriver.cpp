#include<iostream>
#include"Number.h"

int main() {
	CNumber hNumber(127);

	std::cout << "base=2," << hNumber.GetValue() << "=>" << hNumber.ToBin() << "\n";

	std::cout << "base=8," << hNumber.GetValue() << "=>" << hNumber.ToOct() << "\n";

	std::cout << "base=16," << hNumber.GetValue() << "=>" << hNumber.ToHex() << "\n";

	std::cout << "base=3," << hNumber.GetValue() << "=>" << hNumber.ToBase(3) << "\n";

	return 0;
}