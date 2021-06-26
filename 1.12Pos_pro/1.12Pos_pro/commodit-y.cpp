#include "commodity.h"

CCommodity::CCommodity()
{
	//���캯������
}

//���ò�Ʒ��Ϣ
void CCommodity::setInfo(long ld, string upc, string name, double price, string manu)
{
	m_nld = ld;
	m_pszUpc = upc;
	m_pszName = name;
	m_dPrice = price;
	m_pszManufacturer = manu;
}

// ��ȡ�û�����Ĳ�Ʒ����
void CCommodity::acquire(string upc)
{
	m_pszUpc = upc;
	if (m_pszUpc.length()!=0) {
		showInfo();
	}
}

// չʾ��Ʒ��Ϣ
void CCommodity::showInfo()
{
	cout << "��Ʒ��ʶ����" << m_nld << endl;
	cout << "��Ʒ���ƣ�" << m_pszName << endl; //outPut(m_pszName);
	//cout << "\n";
	cout << "���ۣ�" << m_dPrice << endl;
	cout << "��������Ϣ��" << m_pszManufacturer << endl;
	//outPut(m_pszManufacturer);
	//cout << endl;
}

// �����ܼ�
void CCommodity::total(int num)
{
	double totalVal = m_dPrice * num;
	cout << "��ѡ��Ʒ�ܼ�Ϊ��" << totalVal << endl;
	cout << endl;
	cout << endl;
}

void CCommodity::outPut(string ptr)
{
}

CCommodity::~CCommodity()
{
	//������������
}
