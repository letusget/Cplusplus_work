#include <stdlib.h>
#include <stdio.h>

#define N 12
#define B 3

int pageArr[N] = { 1,2,3,4,1,2,5,1,2,3,4,5 }; // ҳ������
int block[B] = { 0 }; // �����3��������ֵ��ҳ��

typedef struct FLAG {
	int flags[B];
	int counts;
}FLAG;

void opt(int pageArr[], int block[]);
int inBlock(int which);
int finFar(int next);
void Repplace(int index, int value);
void disPlay();

int main() {
	printf("Begin:");
	opt(pageArr, block);
	printf("End!");

	return 0;
}


void opt(int pageArr[], int block[]) {
	int getIndex;
	for (int i = 0; i < N; i++) {
		if (i < 3) { // ǰ3ҳ��#��ȱ#������
			block[i] = pageArr[i];
			printf("ȱҳ����null��--> %d\n", pageArr[i]);
		}
		else {
			if (i == 3) {
				disPlay();
			}
			if (inBlock(pageArr[i]) != -1) {
				disPlay();
				continue;
			}
		}
	}
}

int inBlock(int which)
{
	return 0;
}

int finFar(int next)
{
	return 0;
}

void Repplace(int index, int value)
{
}

void disPlay()
{
}
