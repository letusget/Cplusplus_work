#include <stdio.h>
#include <stdbool.h>

#define resourceNum 3
#define processNum 5

// ϵͳ���ã�ʣ�ࣩ��Դ
int available[resourceNum] = { 3,3,2 };
// ���̵��������
int maxRequest[processNum][resourceNum] = { {7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3} };
// �����Ѿ�ռ�У����䣩��Դ
int allocation[processNum][resourceNum] = { {0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2} };
// ���̻���Ҫ��Դ
int need[processNum][resourceNum] = { {7,4,3},{1,2,2},{6,0,0},{0,1,1},{4,3,1} };
// �Ƿ�ȫ
bool Finish[processNum];
// ��ȫ���к�
int safeSeries[processNum] = { 0,0,0,0,0 };
// ����������Դ����
int request[resourceNum];
// ��Դ��������
int num;

// ��ӡ���ϵͳ��Ϣ
void showInfo() {
	printf("\n------------------------------------------------------------------");
	
	printf("��ǰϵͳ������Դʣ�ࣺ");
	for (int j = 0; j < resourceNum; j++) {
		printf("%d", available[j]);
	}

	printf("\n\n��ǰϵͳ��Դ�����\n");
	printf(" PID\t Max\t\tAllocation\t Need\n");
	for (int i = 0; i < processNum; i++) {
		printf(" P%d", i);
		for (int j = 0; j < resourceNum; j++) {
			printf("%2d", maxRequest[i][j]);
		}
		printf("\t\t");
		for (int j = 0; j < resourceNum; j++) {
			printf("%2d", allocation[i][j]);
		}
		printf("\t\t");
		for (int j = 0; j < resourceNum; j++) {
			printf("%2d", need[i][j]);
		}
		printf("\n");
	}
}

// ��ӡ��ȫ�����Ϣ
void SafeInfo(int* work, int i) {
	int j = 0;
	printf(" P%d\t", i);

	for (j = 0; j < resourceNum; j++) {
		printf("%2d", work[j]);
	}
	printf("\t\t");

	for (j = 0; j < resourceNum; j++) {
		printf("%2d", allocation[i][j]);
	}
	printf("\t\t");

	for (j = 0; j < resourceNum; j++) {
		printf("%2d", allocation[i][j] + work[j]);
	}
	printf("\n");
}

// �ж�һ�����̵���Դ�Ƿ�ȫΪ��
bool isAllZero(int kang) {
	num = 0;
	for (int i = 0; i < resourceNum; i++) {
		if (need[kang][i] == 0) {
			num++;
		}
	}

	if (num == resourceNum) {
		return true;
	}
	else {
		return false;
	}
}

// ��ȫ���
bool isSafe() {
	// int resourceNumFinish = 0;
	int safeIndex = 0;
	int allFinish = 0;
	int work[resourceNum] = { 0 };
	int r = 0;
	int temp = 0;
	int pNum = 0;

	// Ԥ����Ϊ�˱���available[];
	for (int i = 0; i < resourceNum; i++) {
		work[i] = available[i];
	}
	// ��δ��ɽ�����Ϊfalse
	for (int i = 0; i < processNum; i++) {
		bool result = isAllZero(i);
		if (result == true) {
			Finish[i] = true;
			allFinish++;
		}
		else {
			Finish[i] = false;
		}
	}
	// Ԥ���俪ʼ
	while (allFinish != processNum) {
		num = 0;
		for (int i = 0; i < resourceNum; i++) {
			if (need[r][i] <= work[i] && Finish[r] == false) {
				num++;
			}
		}
		if (num == resourceNum) {
			for (int i = 0; i < resourceNum; i++) {
				work[i] = work[i] + allocation[r][i];
			}
			allFinish++;
			SafeInfo(work, r);
			safeSeries[safeIndex] = r;
			safeIndex++;
			Finish[r] = true;
		}
		r++; // ��ʽ�����ڴ˴�
		if (r >= processNum) {
			r = r % processNum;
			if (temp == allFinish) {
				break;
			}
			temp = allFinish;
		}
	}
		// �ж�ϵͳ�Ƿ�ȫ
		for (int i = 0; i < processNum; i++) {
			if (Finish[i] == false) {
				printf("\n��ǰϵͳ����ȫ!\n\n");
				return false;
			}
		}

		//��ӡ��ȫ����
		printf("\n��ǰϵͳ��ȫ��\n\n��ȫ����Ϊ��");
		for (int i = 0; i < processNum; i++) {
			bool result = isAllZero(i);
			if (result == true) {
				pNum--;
			}
		}

		for (int i = 0; i < pNum; i++) {
			printf("%d", safeSeries[i]);
		}
		return true;
}

void main() {
	int curProcess = 0;
	int a = -1;
	showInfo();
	printf("\nϵͳ��ȫ���������\n");
	printf(" PID\t Work\t\tAllocation\t Need\t\tWork+Allocation\n");

	bool isStart = isSafe();
	// �û��������Ԥ��ϵͳ��Դ���������ܼ������н��̷��乤��
	while (isStart)
	{
		//�����û����룬�Է��û�������ڽ������������֣��Լ����������ַ��������ǲ�����ģ�
		do {
			if (curProcess >= processNum || a == 0) {
				printf("\n�벻Ҫ���볬������������ֵ���������ַ���\n");
				while (getchar() != '\n') {};//��ջ�����	
				a = -1;
			}
			printf("\n------------------------------------------------------------------------------------\n");
			printf("\n����Ҫ����Ľ��̣�");
			a = scanf("%d", &curProcess);
			printf("\n");

		} 		while (curProcess >= processNum || a == 0);

		//�����û����룬�˴�ֻ�������֣��Է��û����������ַ��������ǲ�����ģ�
		for (int i = 0; i < resourceNum; i++) {
			do {
				if (a == 0) {
					printf("\n�벻Ҫ�������������������ַ������������룺\n");
					while (getchar() != '\n') {};//��ջ�����	
					a = -1;
				}
				printf("������Ҫ��������� P%d �ĵ� %d ����Դ��", curProcess, i + 1);
				a = scanf("%d", &request[i]);
			} while (a == 0);
		}

		//�ж��û�����ķ����Ƿ�������������ʼ����Ԥ����
		num = 0;
		for (int i = 0; i < resourceNum; i++) {
			if (request[i] <= need[curProcess][i] && request[i] <= available[i]) {
				num++;
			}
			else {
				printf("\n�������󣡿���ԭ�����£�\n(1)������������Դ���ܴ��ڸý��̵�ĳЩ��Դ�������Ҫ��\n(2)ϵͳ��ʣ����Դ�Ѿ������ˣ�\n");
				break;
			}
		}
		if (num == resourceNum) {
			num = 0;
			for (int j = 0; j < resourceNum; j++) {
				//������Դ
				available[j] = available[j] - request[j];
				allocation[curProcess][j] = allocation[curProcess][j] + request[j];
				need[curProcess][j] = need[curProcess][j] - request[j];
				//��¼�����Ժ��Ƿ�ý�����ҪֵΪ0��
				if (need[curProcess][j] == 0) {
					num++;
				}
			}
			//��������Ժ���ָý��̶�������Դ������Ϊ0�ˣ������ͷŸý���ռ����Դ����Ϊ��ɣ�
			if (num == resourceNum) {
				//�ͷ��������Դ
				for (int i = 0; i < resourceNum; i++) {
					available[i] = available[i] + allocation[curProcess][i];
				}
				printf("\n\n���η������ P%d ���,�ý���ռ����Դȫ���ͷ���ϣ�\n", curProcess);
			}
			else {
				//��Դ������Բ���һ���������������
				printf("\n\n���η������ P%d δ��ɣ�\n", curProcess);
			}

			showInfo();
			printf("\nϵͳ��ȫ�������\n");
			printf(" PID\t Work\t\tAllocation\t Need\t\tWork+Allocation\n");

			//Ԥ��������Ժ��жϸ�ϵͳ�Ƿ�ȫ������ȫ����ɼ������з��䣬������ȫ�����Ѿ��������Դ������
			if (!isSafe()) {
				for (int j = 0; j < resourceNum; j++) {
					available[j] = available[j] + request[j];
					allocation[curProcess][j] = allocation[curProcess][j] - request[j];
					need[curProcess][j] = need[curProcess][j] + request[j];
				}
				printf("��Դ���㣬�ȴ���...\n\n����ʧ�ܣ�\n");
			}
		}
	}
}