#include <iostream>
#include "Commodity.h"

#define N 10 // �������鳤��

using namespace std;

int main() {
	// �����һ����Ʒ��Ϣ
	
	cout << "��ӭ��¼��Ʒ��Ϣϵͳ��" << endl;
	cout << "========================================================" << endl;

	char commodityUpc1[N] = "A00A";
	//char* str1 = { "A00A"};
	/*���������½�һ���ַ���,������A00A Ȼ��str1��һ��ͷָ��,ָ�������.��������½�����
	��Ϊconst���ڵ�,������һ�����Ա༭�ı���,���,һ������������е�ֵ,
	����ͻ�ҵ�,��������ʹ���ַ�����ͺܲ���*/
	char commodityName1[N] = "Apple";
	char commodityManu1[N] = "CN";
	long nld1 = 1001;
	long nld2 = 1002;
	long nld3 = 1003;

	// ������һ����Ʒ���󣬲���Ӧ��ʼ�����Ա����
	CCommodity commodity1;
	commodity1.setInfo(nld1, commodityUpc1, commodityName1, 1.1, commodityManu1);


	// ͬ��
	char commodityUpc2[N] = "B00B";
	char commodityName2[N] = "Banana";
	char commodityManu2[N] = "JP";

	CCommodity commodity2;
	commodity2.setInfo(nld2, commodityUpc2, commodityName2, 2.2, commodityManu2);

	// ͬ��
	char commodityUpc3[N] = "C00C";
	char commodityName3[N] = "Corn";
	char commodityManu3[N] = "US";

	CCommodity commodity3;
	commodity3.setInfo(nld3, commodityUpc3, commodityName3, 3.3, commodityManu3);

	// չʾ��Ʒ����
	cout << "���в�Ʒ����Ϊ:"
		<< commodityUpc1 << "\t"
		<< commodityUpc2 << "\t"
		<< commodityUpc3 << endl;
	cout << "========================================================" << endl;

	// �û�ѡ���Ʒ
	cout << "�������Ʒ����:" << endl;
	char acquireUpc[10] = {};
	cin >> acquireUpc;

	// �����û�ѡ��Ĳ�Ʒ���룬��ʾ��Ӧ�Ĳ�Ʒ��Ϣ
	if (strcmp(acquireUpc, commodityUpc1) == 0) {  //strcmp�Ƚ������ַ����Ƿ����
		commodity1.acquire(acquireUpc);
		cout << "�����빺��������"; // �����ܼ�
		int num;
		cin >> num;
		commodity1.total(num);
	}
	else if (strcmp(acquireUpc, commodityUpc2) == 0) {
		commodity2.acquire(acquireUpc); cout << "�����빺��������";
		int num;
		cin >> num;
		commodity2.total(num);
	}
	else if (strcmp(acquireUpc, commodityUpc3) == 0) {
		commodity3.acquire(acquireUpc); cout << "�����빺��������";
		int num;
		cin >> num;
		commodity3.total(num);

	}
	// delete[] commodityUpc1;

	return 0;
}