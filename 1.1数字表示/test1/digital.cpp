#include <iostream>
#include <string>
using namespace std;
#define col 8  //限制打印字符的高度
#define size 3  //限制打印字符的宽度

void segment_one(int digit);

void segment_two(int digit);

void segment_three(int digit);

void segment_four(int digit);

void segment_five(int digit);



void printnum(int a,int b)
{
	//为了确保可以在一行里打印两个数字，就轮流调用函数
	segment_one(a);
	cout << " ";
	segment_one(b);
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		segment_two(a);
		cout << " ";
		segment_two(b);
		cout << endl;  //回车一定是在行末打印，否则就会出现错误
	}//第二四部分是基本类似的，其实都不是直接打印整个部分，而是每次调用都只打印一行内容，在这里整合

	segment_three(a);
	cout << " ";
	segment_three(b);
	cout << endl;

	for (int j = 0; j < size; j++)
	{
		segment_four(a);
		cout << " ";
		segment_four(b);
		cout << endl;
	}
	
	segment_five(a);
	cout << " ";
	segment_five(b);
	cout << endl;
}

int main()
{
	int num;
	/*cout << "请输入一个数字 :（10-99）" ;
	cin >> num ;
	//cout << "num=" << num << endl;
	
	while(num < 10||num > 99)
	{
		cout << "输入错误，请注意输入数字范围(10-99):" ;
		cin >> num;  //输入检查
	}*/

	string const prompt = "请输入一个数字（10-99）[按任意字符退出] :";
	string const out_range = "输入错误！";
	for (int i = 0; cout << prompt, cin>>i; )  
	{//这里的for是死循环，只要输入的是数字，永远不会跳出循环，只要输入字符，就可以跳出循环结束
		if (i < 10 || i>99)
		{
			cout << out_range;
			continue;  //可以跳出本次for循环，进入下一次for循环
			//如果输入的是错误的数字，则继续输入
		}
		num = i;


		cout << "您输入的数字为 : " << num << endl;

		int a, b;
		a = num / 10;
		b = num % 10;

		//cout << "a=" << a << endl;
		//cout << "b=" << b << endl;

		cout << "您输入的整数为：" << endl;
		cout << endl;
		printnum(a, b);
		cout << endl;

	}

	return 0;
}

void segment_one_0()
{
	for (int i = 0; i<col; i++)
	{
		cout << "*";
	}
}

void segment_one(int digit)
{
	//区分不同的情况，在第一段函数中，对于不同的数字要打印不同的方式
	if (digit == 0 || digit == 2 || digit == 3 || digit == 5 || digit == 6 || digit == 7 || digit == 8 || digit == 9)
	{
		segment_one_0();  //可以将这样类似的for循环输出语句都变为函数引用
	}
	else if (digit == 1)
	{
		for (int i = 0; i<col - 1; i++)
		{
			cout << " ";
		}
		cout << "*";
	}
	else if (digit == 4)
	{
		cout << "*";
		for (int i = 0; i<col - 2; i++)
		{
			cout << " ";
		}
		cout << "*";
	}
	else
	{
		cout << "Error!" << endl;
	}
	//如果有情况遗漏，则打印错误信息		
}

void segment_two(int digit)
{
	//第二四部分是较为难实现的，因为是两个数字，需要在同一行中实现，就不能是简单的挨个输出数字，
	//所以我采用的是每一行输出一部分内容，然后在整个的打印函数中，将其整合起来
	if (digit == 1 || digit == 2 || digit == 3)
	{
		for (int j = 0; j<col - 1; j++)
		{
			cout << " ";
		}
		cout << "*";
	}
	else if (digit == 0 || digit == 4 || digit == 8 || digit == 9)
	{
		cout << "*";
		for (int j = 0; j<col - 2; j++)
		{
			cout << " ";
		}
		cout << "*";
	}
	else if (digit == 5 || digit == 6)
	{
		cout << "*";
		for (int j = 0; j<col - 1; j++)
		{
			cout << " ";
		}
	}
	else if (digit == 7)
	{
		for (int j = 0; j<col - 1; j++)
		{
			cout << " ";
		}
		cout << "*";
	}
	else
	{
		cout << "Error!" << endl;
	}
}

void segment_three(int digit)
{//第三部分的实现和第一部分的实现是很类似的
	if (digit == 2 || digit == 3 || digit == 4 || digit == 5 || digit == 6 || digit == 8 || digit == 9)
	{
		for (int i = 0; i < col; i++)
		{
			cout << "*";
		}
	}
	else if (digit == 1 || digit == 7)
	{
		for (int i = 0; i < col - 1; i++)
		{
			cout << " ";
		}
		cout << "*";
	}
	else if (digit == 0)
	{
		cout << "*";
		for (int i = 0; i < col - 2; i++)
		{
			cout << " ";
		}
		cout << "*";
	}
	else
	{
		cout << "Error!" << endl;
	}
}

void segment_four(int digit)
{
	if (digit == 1 || digit == 3 || digit == 4 || digit == 5 || digit == 7 || digit == 9)
	{
		for (int j = 0; j<col - 1; j++)
		{
			cout << " ";
		}
		cout << "*";

	}
	else if (digit == 0 || digit == 6 || digit == 8)
	{
		cout << "*";
		for (int j = 0; j<col - 2; j++)
		{
			cout << " ";
		}
		cout << "*";
	}
	else if (digit == 2)
	{

		cout << "*";
		for (int j = 0; j<col - 1; j++)
		{
			cout << " ";
		}
	}
	else
	{
		cout << "Error!" << endl;
	}
}

void segment_five(int digit)
{
	if (digit == 0 || digit == 2 || digit == 3 || digit == 5 || digit == 6 || digit == 8)
	{
		for (int i = 0; i < col; i++)
		{
			cout << "*";
		}

	}
	else if (digit == 1 || digit == 4 || digit == 7 || digit == 9)
	{
		for (int i = 0; i < col - 1; i++)
		{
			cout << " ";
		}
		cout << "*";
	}
	else
	{
		cout << "Error!";
	}
}
