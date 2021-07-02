#include <iostream>

const int width = 8;

using namespace std;

void segment_one(int digit); // 第一段

void segment_two(int digit); // 第二段

 void segment_three(int digit); // 第三段

 void segment_four(int digit); // 第四段

 void segment_five(int digit); // 第五段

int main() {
	int number = 0; 
	int ones_digit = 0;
	int tens_digit = 0;

	cout << "请输入一个介于[10~99]的整数：" << endl;
	cin >> number;

	if (number >= 10 && number <= 99) {
		tens_digit = number / 10;
		ones_digit = number % 10;
		segment_one(tens_digit);
		cout << " ";
		segment_one(ones_digit);
		cout << "\n";
		
		for (int count = 0; count < 3; count++) {
			segment_two(tens_digit);
			cout << " ";
			segment_two(ones_digit);
			cout << "\n";
		}
		
		segment_three(tens_digit);
		cout << " ";
		segment_three(ones_digit);
		cout << "\n";
		
		for (int count = 0; count < 3; count++) {
			segment_four(tens_digit);
			cout << " ";
			segment_four(ones_digit);
			cout << "\n";
		}
		
		segment_five(tens_digit);
		cout << " ";
		segment_five(ones_digit);
		cout << "\n"; 
		
	}
	else {
		cout << "输入整数不合法" << endl;
	}

	return 0;
}

void segment_one(int digit) {
	switch (digit)
	{
		default: {
			for (int i = 0; i < width; i++) {
				cout << "*";
			}
		}
			break;
		case 1: {
			for (int i = 0; i < width - 1; i++) {
				cout << " ";
			}
			cout << "*";
		}
			  break;
		case 4: {
			cout << "*";
			for (int i = 0; i < width - 2; i++) {
				cout << " ";
			}
			cout << "*";
		}
			break;
	}
}

void segment_two(int digit) {
	switch (digit)
	{
		default:
			break;
		case 1:
		case 2:
		case 3:
		case 7: {
				for (int j = 0; j < width - 1; j++) {
					cout << " ";
				}
				cout << "*";
		}
			  break;
		case 4:
		case 8:
		case 9:
		case 0: {
				cout << "*";
				for (int j = 0; j < width - 2; j++) {
					cout << " ";
				}
				cout << "*";
		}
			  break;
		case 5:
		case 6: {
				cout << "*";
				for (int j = 0; j < width - 1; j++) {
					cout << " ";
				}			
		}
			  break;
	}
	

}

void segment_three(int digit) {
	switch (digit)
	{
		default: {
			for (int i = 0; i < width; i++) {
				cout << "*";
			}
		}
			break;
		case 1:
		case 7: {
			for (int i = 0; i < width - 1; i++) {
				cout << " ";
			}
			cout << "*";
		}
			  break;
		case 0: {
			cout << "*";
			for (int i = 0; i < width - 2; i++) {
				cout << " ";
			}
			cout << "*";
		}
			  break;
	}
}

void segment_four(int digit) {
	switch (digit)
	{
	default:
		break;
	case 1:
	case 3:
	case 4:
	case 5:
	case 7:
	case 9: {
		for (int i = 0; i < width - 1; i++) {
			cout << " ";
		}
		cout << "*";
	}
		  break;
	case 2: {
		cout << "*";
		for (int i = 0; i < width - 1; i++) {
			cout << " ";
		}
	}
		  break;
	case 6:
	case 8:
	case 0: {
		cout << "*";
		for (int i = 0; i < width - 2; i++) {
			cout << " ";
		}
		cout << "*";
	}
		  break;
	}
}

void segment_five(int digit) {
	switch (digit)
	{
	default: {
		for (int i = 0; i < width; i++) {
			cout << "*";
		}
	}
		break;
	case 1:
	case 4:
	case 7: {
		for (int i = 0; i < width - 1; i++) {
			cout << " ";
		}
		cout << "*";
	}
		  break;
	}
}