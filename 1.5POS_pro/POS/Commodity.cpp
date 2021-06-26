#include <iostream>
#include "Commodity.h"

// CCommodity��ʵ��

#define N 10

using namespace std;

CCommodity::CCommodity() {
	//cout << "CommodityInfo is being created!" << endl;
}

void CCommodity::setInfo(long ld, char upc[], char name[], double price, char manu[]) {
	m_nld = ld;
	m_pszUpc = upc;
	m_pszName = name;
	m_dPrice = price;
	m_pszManufacturer = manu;
}

// ��ȡ�û�����Ĳ�Ʒ����
void CCommodity::acquire(char upc[]) {
	m_pszUpc = upc;
	if (*m_pszUpc) {
		showInfo();
	}
}

// չʾ��Ʒ��Ϣ
void CCommodity::showInfo() {
	/*cout << "��Ʒ���ƣ�"; 
	outPut(m_pszName);
	cout << "\n";
	cout << "���ۣ�" << m_dPrice << "\n";
	cout << "��������Ϣ��"; outPut(m_pszManufacturer);
	cout << endl;*/

	cout << "��Ʒ���ƣ�" ; 
	outPut(m_pszName);
	cout << "\n";
	cout << "���ۣ�" << m_dPrice << endl;
	cout << "��������Ϣ��";
	outPut(m_pszManufacturer);
	cout << endl;
}

// �����ܼ�
void CCommodity::total(int num) {
	double totalVal = m_dPrice * num;
	cout << "��ѡ��Ʒ�ܼ�Ϊ��" << totalVal << endl;
}

// Ϊ�����char*�����Ա����
void CCommodity::outPut(char* ptr) {
	for (int i = 0; i < N; i++) {
		cout << *(ptr + i);
	}
}


CCommodity::~CCommodity()
{
	//cout << "It has been deleted." << endl;
}