#include <iostream>
#include <string>
using namespace std;
#define col 8  //���ƴ�ӡ�ַ��ĸ߶�
#define size 3  //���ƴ�ӡ�ַ��Ŀ��

void segment_one(int digit);

void segment_two(int digit);

void segment_three(int digit);

void segment_four(int digit);

void segment_five(int digit);



void printnum(int a,int b)
{
	//Ϊ��ȷ��������һ�����ӡ�������֣����������ú���
	segment_one(a);
	cout << " ";
	segment_one(b);
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		segment_two(a);
		cout << " ";
		segment_two(b);
		cout << endl;  //�س�һ��������ĩ��ӡ������ͻ���ִ���
	}//�ڶ��Ĳ����ǻ������Ƶģ���ʵ������ֱ�Ӵ�ӡ�������֣�����ÿ�ε��ö�ֻ��ӡһ�����ݣ�����������

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
	/*cout << "������һ������ :��10-99��" ;
	cin >> num ;
	//cout << "num=" << num << endl;
	
	while(num < 10||num > 99)
	{
		cout << "���������ע���������ַ�Χ(10-99):" ;
		cin >> num;  //������
	}*/

	string const prompt = "������һ�����֣�10-99��[�������ַ��˳�] :";
	string const out_range = "�������";
	for (int i = 0; cout << prompt, cin>>i; )  
	{//�����for����ѭ����ֻҪ����������֣���Զ��������ѭ����ֻҪ�����ַ����Ϳ�������ѭ������
		if (i < 10 || i>99)
		{
			cout << out_range;
			continue;  //������������forѭ����������һ��forѭ��
			//���������Ǵ�������֣����������
		}
		num = i;


		cout << "�����������Ϊ : " << num << endl;

		int a, b;
		a = num / 10;
		b = num % 10;

		//cout << "a=" << a << endl;
		//cout << "b=" << b << endl;

		cout << "�����������Ϊ��" << endl;
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
	//���ֲ�ͬ��������ڵ�һ�κ����У����ڲ�ͬ������Ҫ��ӡ��ͬ�ķ�ʽ
	if (digit == 0 || digit == 2 || digit == 3 || digit == 5 || digit == 6 || digit == 7 || digit == 8 || digit == 9)
	{
		segment_one_0();  //���Խ��������Ƶ�forѭ�������䶼��Ϊ��������
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
	//����������©�����ӡ������Ϣ		
}

void segment_two(int digit)
{
	//�ڶ��Ĳ����ǽ�Ϊ��ʵ�ֵģ���Ϊ���������֣���Ҫ��ͬһ����ʵ�֣��Ͳ����Ǽ򵥵İ���������֣�
	//�����Ҳ��õ���ÿһ�����һ�������ݣ�Ȼ���������Ĵ�ӡ�����У�������������
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
{//�������ֵ�ʵ�ֺ͵�һ���ֵ�ʵ���Ǻ����Ƶ�
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
