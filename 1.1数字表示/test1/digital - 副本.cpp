#include <iostream>
using namespace std;
#define col 8
#define size 3

void printrow1()
{
	for (int i = 0; i<col; i++)
	{
		cout << "*";
	}
}

void segment_one(int digit)
{
	
		if(digit==2||digit==3||digit==0||digit==5||digit==6||digit==7||digit==8||digit==9)
		{
			
			printrow1();
		}
		else if(digit==1)
		{
			for(int i=0;i<col-1;i++)
			{
				cout << " ";
			}
			cout << "*";
		}
		else if(digit==4)
		{
			cout << "*";
			for(int i=0;i<col-2;i++)
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

void segment_two_row()
{
	for (int j = 0; j<col - 1; j++)
	{
		cout << " ";
	}
	cout << "*";
}

void segment_two(int digit)
{
	if(digit==1||digit==2||digit==3)
	{
		
			for(int j=0;j<col-1;j++)
			{
				cout<< " ";			
			}
			cout<< "*";
			
	}
	else if(digit==0||digit==4||digit==8||digit==9)
	{
		
			cout << "*";
			for(int j=0;j<col-2;j++)
			{
				cout << " ";
			}
			cout << "*";

	}
	else if(digit==5||digit==6)
	{
			cout << "*";
			for(int j=0;j<col-1;j++)
			{
				cout << " ";
			}
		
	}
	else if(digit==7)
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
{
	if (digit == 2 || digit == 3||digit==4||digit==5||digit==6||digit==8||digit==9)
	{
		for (int i = 0; i < col; i++)
		{
			cout << "*";
		}
	
	}
	else if (digit==1||digit==7)
	{
		for (int i = 0; i < col-1; i++)
		{
			cout << " ";
		}
		cout << "*" ;
	}
	else if (digit==0)
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
			cout << "*" ;
		
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
	else if (digit==1||digit==4||digit==7||digit==9)
	{
		for (int i = 0; i < col - 1; i++)
		{
			cout << " ";
		}
		cout << "*";
	}
	else
	{
		cout << "Error!" ;
	}
}



void printnum(int a,int b)
{
	segment_one(a);
	cout << " ";
	segment_one(b);
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		segment_two(a);
		cout << " ";
		segment_two(b);
		cout << endl;
	}
	

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
	
	/*segment_one(a);
	segment_two(a);
	segment_three(a);
	segment_four(a);
	segment_five(a);*/
}

int main()
{
	int num;
	cout << "Please inter a number :£¨10-99£©" ;
	cin >> num ;
	//cout << "num=" << num << endl;
	
	while(num < 10||num > 99)
	{
		cout << "Error! Please inter again(10-99):" << endl;
		cin >> num;
	}
	
	cout <<"Your number is :" << num << endl;
	
	int a,b;
	a=num/10;
	b=num%10;

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	
	printnum(a,b);
	//printnum(b);

	

	return 0;

}