#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#define row 3
#define col 5


int main()
{
	int (*matrix)[col]=new int[row][col];
	//在堆上申请空间

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = (i+1)*(j+1);  //行列相乘
		}
	}

	for (int  i = 0; i < row; i++)
	{
		for (int  j = 0; j < col; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	delete[] matrix; 
	//直接释放内存即可，不用再使用for循环，因为在申请空间的时候就是没有使用for循环的

	return 0;
}
