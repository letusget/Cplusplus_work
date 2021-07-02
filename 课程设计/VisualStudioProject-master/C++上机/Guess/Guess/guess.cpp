#include <iostream>
#include "Random.h"

using namespace std;

void Guess(CRandom& hRandom);

const int nBound = 10;
const int nLimit = 10;

int main() {
	CRandom Rand(nBound, nLimit);

	cout << "=====================================" << endl;
	cout << "============= 猜数游戏 ==============" << endl;
	cout << "=====================================" << endl;
	
	cout << "============ 输入 S 开始 ============" << endl;
	char choice;
	cin >> choice;
	
	Rand.Start();
	while (choice == 'S') {
		Guess(Rand);
	}
	return 0;
}

void Guess(CRandom& hRandom) {
	cout << "请输入您猜的整数：" << endl;
	int nValue = 0;
	int result = 0;

	cin >> nValue;
	result = hRandom.Judge(nValue);

	switch (result) {
	
	default:
		cout << "ERROR!" << endl;
		break;
	case 1:
		cout << "Congratulation!" << endl;
		exit(0);
		break;
	case 2:
		cout << "Sorry, too small, remaining:" << hRandom.getCount() << endl;
		break;
	case 3:
		cout << "Sorry, too large, remaining:" << hRandom.getCount() << endl;
		break;
	case 4:
		cout << "Sorry, exhausted, value:" << hRandom.getValue() << endl;
		exit(0);
		break;
	}
	
	
}
