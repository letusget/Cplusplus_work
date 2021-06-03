#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#define col 8
#define size 3
using namespace std;

void segment_one5(string str)
{
	for (int i = 0; i<col; i++)
	{
		cout << str;
	}
}

void segment_one2(string str)
{
	for (int i = 0; i<col; i++)
	{
		cout << str;
	}
}
void segment_one1(string str)
{
	for (int i = 0; i<col - 1; i++)
	{
		cout << " ";
	}
	cout << str ;
}

void segment_two5(string str)
{
	cout <<str;
	for (int j = 0; j<col - 1; j++)
	{
		cout << "  ";
	}
}

void segment_two2(string str)
{
	for (int j = 0; j<col - 1; j++)
	{
		cout << "  ";
	}
	cout << str;
}

void segment_two1(string str)
{
	for (int j = 0; j<col - 1; j++)
	{
		cout << " ";
	}
	cout << str;
}

void segment_three5(string str)
{

	for (int i = 0; i < col; i++)
	{
		cout << str;
	}
}
void segment_three2(string str)
{
	for (int i = 0; i < col; i++)
	{
		cout << str;
	}
}
void segment_three1(string str)
{
	for (int i = 0; i < col - 1; i++)
	{
		cout << " ";
	}
	cout << str;
}

void segment_four5(string str)
{
	for (int j = 0; j<col - 1; j++)
	{
		cout << "  ";
	}
	cout << str;

}

void segment_four2(string str)
{
	cout << str;
	for (int j = 0; j<col - 1; j++)
	{
		cout << "  ";
	}

}

void segment_four1(string str)
{
	for (int j = 0; j<col - 1; j++)
	{
		cout << " ";
	}
	cout << str;

}

void segment_five5(string str)
{
	for (int i = 0; i < col; i++)
	{
		cout << str;
	}

}

void segment_five2(string str)
{
	for (int i = 0; i < col; i++)
	{
		cout << str;
	}

}

void segment_five1(string str)
{

	for (int i = 0; i < col - 1; i++)
	{
		cout << " ";
	}
	cout << str;
}


void printStr(string one, string two, string three)
{
	segment_one5(one);
	cout << "\t";
	segment_one2(two);
	cout << "\t";
	segment_one1(three);
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		segment_two5(one);
		cout << "\t";
		segment_two2(two);
		cout << "\t";
		segment_two1(three);
		cout << endl;
	}

	segment_three5(one);
	cout << "\t";
	segment_three2(two);
	cout << "\t";
	segment_three1(three);
	cout << endl;
	
	for (int i = 0; i < 3; i++)
	{
		segment_four5(one);
		cout << "\t";
		segment_four2(two);
		cout << "\t";
		segment_four1(three);
		cout << endl;
	}

	segment_five5(one);
	cout << "\t";
	segment_five2(two);
	cout << "\t";
	segment_five1(three);
	cout << endl;


}

int main()
{
	string a, b, c;
	
		cout << "请输入第1个要显示的字符：";
		getline(cin,a);
		cout << endl;
		cout << "请输入第2个要显示的字符：";
		getline(cin, b);
		cout << endl;
		cout << "请输入第3个要显示的字符：";
		getline(cin, c);
		cout << endl;

		cout << "您输入的是： ";
		cout << a << "  "<< b<< " " << c << endl;

		cout << endl;
		printStr(a, b, c);
		cout << endl;


	return 0;
}