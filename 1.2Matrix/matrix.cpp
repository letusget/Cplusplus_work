#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#define row 3
#define col 5


int main()
{
	int (*matrix)[col]=new int[row][col];
	//�ڶ�������ռ�

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = (i+1)*(j+1);  //�������
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
	//ֱ���ͷ��ڴ漴�ɣ�������ʹ��forѭ������Ϊ������ռ��ʱ�����û��ʹ��forѭ����

	return 0;
}
