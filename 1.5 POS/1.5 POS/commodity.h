#pragma once
#include <iostream>
#include <string>
using namespace std;

class CCommodity
{
public:
	CCommodity(long m_nld, 
	char * m_pszUpc,
	char * m_pszName,
	int m_dPrice,
	char * m_pszManufacturer);

	CCommodity();

	void showmenu();  //չʾ�˵���Ϣ
	void exitsys();  //�˳�ϵͳ
	void addPsz();  //��Ӳ�Ʒ��Ϣ
	int pszNum;  //��¼��Ʒ����
	CCommodity * pszArray;
	void psz_Find(char *id);  //���Ҳ�Ʒ��Ϣ
	//void psz_Print(char *id);

	void print_nld(long nld);

	void print_pszUpc(char * pszUpc);
	
	void print_pszName(char * pszName);
	
	void print_dPrice(int dPrice);
	
	void print_pszManufacturer(char * pszManufactruer);
	
	
	~CCommodity();

private:
	long m_nld;  //��ƷΨһ��ʶ
	char * m_pszUpc;  //ͨ�ò�Ʒ����
	char * m_pszName;  //��Ʒ���� �����ظ�
	int m_dPrice;  //��Ʒ�۸�
	char * m_pszManufacturer;  //��Ʒ������

};


