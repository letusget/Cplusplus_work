#include <iostream>

const int M = 3; // ��������
const int N = 5; // ��������

using namespace std;

int main() {
	int line, row; // ��������
	int** array; // �����ά����

	// ��̬����ռ�
	array = new int* [M];
	for (line = 0; line < M; line++) {
		array[line] = new int[N];
	}

	// ��ʼ��
	for (line = 0; line < M; line++) {
		for (row = 0; row < N; row++) {
			array[line][row] = (line + 1) * (row + 1);
		}
	}

	// ��ӡ���
	for (line = 0; line < M; line++) {
		for (row = 0; row < N; row++) {
			if (row == 0)
				cout << endl;
			cout << array[line][row] << "\t";
		}
	}

	// �ͷ�����Ķѣ���ֹ�ڴ�й¶
	for (line = 0; line < M; line++ ) {
		delete[] array[line];
	}
	delete[] array;

	return 0;
}