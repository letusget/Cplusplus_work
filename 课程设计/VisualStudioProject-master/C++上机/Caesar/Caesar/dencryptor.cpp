#include <iostream>
#include "Caesar.h"

using namespace std;

int main() {
	CCaesar* caesar = CCaesar::getinstance();
	char plain[size];  //����
	char cipher[size];  //����
	CCaesar::init_Code();
	/*
	����ģʽ��Ϊ����ģʽ������ģʽ
	����ģʽ�У�һ����ֻ�ܴ���һ�����󣬼�����ģʽ����ģʽ���Ա�֤ϵͳ�и���ֻ��һ��ʵ����
	���ṩһ����������ȫ�ַ��ʵ㣬��ʵ�������г���ģ�鹲��
	����ģʽ������˵�����㽫���ò��ã���������ʱ�ʹ���һ��Ψһ��ʵ������
	����ģʽ���ȵ��õĵ�ʱ������ٴ���ʵ������
	�ο���https://blog.csdn.net/Miss_Monster/article/details/88086933
	*/

	int num;
	while (1) {
		CCaesar::menu();
		cout << endl;

		cout << "��������Ҫʵ�ֵĹ��ܣ�";
		cin >> num;
		while (num != 0 && num != 1 && num != 2 && num != 3) {
			cout << "ѡ��������������룺";
			cin >> num;
		}

		switch (num) {
		default:cout << "ѡ�����������ѡ��" << endl;
			break;
		case 0:
			cout << "�ɹ��˳�" << endl;
			exit(0);
			break;
		case 1:
			cout << "��ʼ���ܣ�" << endl;

			cout << "���������ģ���С������32���ַ���:" << endl;
			cin >> plain;

			CCaesar::Encrypt(plain);
			cout << "���ܽ�����£�" << endl;
			for (int i = 0; i < (int)strlen(plain); i++) {
				cout << plain[i];
			}
			cout << endl;
			break;

		case 2:
			cout << "��ʼ���ܣ�" << endl;
			cout << "���������ģ���С������32���ַ���:" << endl;
			cin >> cipher;

			CCaesar::Decrypt(cipher);
			cout << "���ܽ�����£�" << endl;
			for (int i = 0; i < (int)strlen(cipher); i++) {
				cout << cipher[i];
			}
			cout << endl;
			break;
		case 3:
			CCaesar::print_Code();
			break;
		}
	}
	CCaesar::deleteCaesar();
}