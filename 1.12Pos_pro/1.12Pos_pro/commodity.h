#pragma once
#include <iostream>
#include <string>
#define N 10 

using namespace std;


class CCommodity
{
public:
	CCommodity();
	//���ò�Ʒ��Ϣ
	void setInfo(long ld, string upc, string name, double price, string manu);
	// ��ȡ�û�����Ĳ�Ʒ����
	void acquire(string upc);
	// չʾ��Ʒ��Ϣ
	void showInfo();
	// �����ܼ�
	void total(int num);
	void outPut(string ptr);

	~CCommodity();

private:
	long m_nld;  //��ƷΨһ��ʶ
	string m_pszUpc;  //ͨ�ò�Ʒ����
	string m_pszName;  //��Ʒ���� �����ظ�
	int m_dPrice;  //��Ʒ�۸�
	string m_pszManufacturer;  //��Ʒ������  

};
