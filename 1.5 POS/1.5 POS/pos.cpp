#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

#include "commodity.h"
using namespace std;



int main()
{
	//long m_nld;  //��ƷΨһ��ʶ

	//char * m_pszUpc;  //ͨ�ò�Ʒ����
	//m_pszUpc = (char *)malloc(20 * sizeof(char));
	//
	////char pszName;
	//char * m_pszName;  //��Ʒ���� �����ظ�
	//m_pszName = (char *)malloc(20 * sizeof(char));

	//int m_dPrice;  //��Ʒ�۸�

	////char pszManufacturer;
	//char * m_pszManufacturer;  //��Ʒ������
	//m_pszManufacturer = (char *)malloc(20 * sizeof(char));

	//CCommodity product;
	////product print_nld();
	//string input_nld = "��������Ʒ��ʶ��";
	//string input_pszUpc = "�������Ʒ���룺";
	//string input_pszName = "��������Ʒ���ƣ�";
	//string input_dprice = "��������Ʒ�۸�";
	//string input_pszManufacturer = "��������Ʒ�����̣�";

	//cout << input_nld;
	//cin >> m_nld;
	//
	//cout << input_pszUpc;
	//cin >> *m_pszUpc;

	//cout << input_pszName;
	//cin >> *m_pszName;
	//
	//cout << input_dprice;
	//cin >> m_dPrice;
	//
	//cout << input_pszManufacturer;
	//cin >> *m_pszManufacturer;
	//
	//product.print_nld(m_nld);
	//product.print_pszUpc(m_pszUpc);
	//product.print_pszName(m_pszName);
	//product.print_dPrice(m_dPrice);
	//product.print_pszManufacturer(m_pszManufacturer);

	//free(m_pszUpc);
	//free(m_pszName);
	//free(m_pszManufacturer);

	CCommodity psz;
	while (1)
	{
		psz.showmenu();
		int choice = 0;
		char* psz_Id = new char[50];
		cout << "��ѡ��Ҫʵ�ֵĹ��ܣ�";
		cin >> choice;
		while (choice != 0 && choice != 1 && choice != 2)
		{
			cout << "�����������������" << endl;
			cin >> choice;
		}
		switch (choice)
		{
		default:
			cout << "���������Ϣ�����󣡣�" << endl;
			break;
		case 0: //�˳�
			psz.exitsys();
			break;
		case 1:  //¼����Ϣ
			psz.addPsz();
			break;
		case 2:  //���Ҳ�Ʒ
			cout << "������Ҫ���Ҳ�Ʒ��ͨ�ò�Ʒ���루UPC����" << endl;
			cin >> *psz_Id;
			
			//cout << "�ַ����ȽϽ����"<< strcmp(psz_Id, psz.m_pszUpc)<< endl;
			psz.psz_Find(psz_Id);
			break;
		}

	}
	


	return 0;
}