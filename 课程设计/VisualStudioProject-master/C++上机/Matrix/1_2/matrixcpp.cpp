#include <iostream>

const int M = 3; // 数组行数
const int N = 5; // 数组列数

using namespace std;

int main() {
	int line, row; // 定义行列
	int** array; // 定义二维数组

	// 动态分配空间
	array = new int* [M];
	for (line = 0; line < M; line++) {
		array[line] = new int[N];
	}

	// 初始化
	for (line = 0; line < M; line++) {
		for (row = 0; row < N; row++) {
			array[line][row] = (line + 1) * (row + 1);
		}
	}

	// 打印输出
	for (line = 0; line < M; line++) {
		for (row = 0; row < N; row++) {
			if (row == 0)
				cout << endl;
			cout << array[line][row] << "\t";
		}
	}

	// 释放申请的堆，防止内存泄露
	for (line = 0; line < M; line++ ) {
		delete[] array[line];
	}
	delete[] array;

	return 0;
}