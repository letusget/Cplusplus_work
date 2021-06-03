
#include "Caesar.h"

//CCaesar* CCaesar::instance = nullptr;
CCaesar* CCaesar::instance = new CCaesar();
CCaesar* CCaesar::getinstance()
{
	return instance;  //ֱ�ӷ���inatance
}

char CCaesar::code[len] = { '0' };

void CCaesar::menu()
{
	cout << "==================================================================" << endl;
	cout << "\t\t��������" << endl;

	cout << endl;
	cout << "�����ܳ���������ڴ�дӢ�ĺ�СдӢ�ļ�, ; ' �� �����ַ�����֧��" << endl;
	cout << "\t\t1. �����ַ�" << endl;
	cout << "\t\t2. �����ַ�" << endl;
	cout << "\t\t3. ��ʾ�����" << endl;
	cout << "\t\t0. �˳���������" << endl;
	cout << endl;
	cout << "==================================================================" << endl;
}

void CCaesar::init_Code()
{//��ʼ����������Գ�ʼ��Ϊ�Լ���Ҫ���κ��ַ�
	for (int i = 0; i < 26; i++)
	{
		code[i] = char(65 + i);
	}
	for (int i = 0; i < 26; i++)
	{
		code[i + 26] = char(97 + i);
	}

	code[len - 1] = char(34);
	code[len - 2] = char(39);
	code[len - 3] = char(59);
	code[len - 4] = char(44);
}

void CCaesar::print_Code()
{
	for (int i = 0; i < len; i++)
	{
		cout << i << "  -------->" << code[i] << endl;
	}
}

char* CCaesar::Encrypt(char* conse1)  //���ܺ���
{
	for (int i = 0; i < (int)strlen(conse1); i++)
	{//����ÿһ���ַ�
		for (int j = 0; j < len; j++)
		{//Ѱ�Ҹ��ַ���������е�λ��
			if (conse1[i] == code[j])
			{//�ҵ��ͽ������key��λ��
				int temp = (j + key) % len;
				conse1[i] = code[temp];
				break;
			}
		}
	}
	return conse1;  //���ظ��ַ���
}
char* CCaesar::Decrypt(char* conse2)  //���ܺ���
{
	for (int i = 0; i < (int)strlen(conse2); i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (conse2[i] == code[j])
			{
				int temp = (j + len - key) % len;
				//�����������е�ֵ��ǰ�ƶ�key���ַ���+len��ȡģ����ʵ��ͷβ���
				conse2[i] = code[temp];
				break;
			}
		}
	}
	return conse2;
}

void CCaesar::deleteCaesar()
{
	delete instance;
}
