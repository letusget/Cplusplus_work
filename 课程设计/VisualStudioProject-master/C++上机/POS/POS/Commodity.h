#pragma once
#ifndef Commodity_H_ // ȷ��ͷ�ļ����ᱻ�ظ�����
#define Commodity_H_

// ������Ʒ��
class CCommodity
{
public:
	void setInfo(long ld, char upc[], char name[], double price, char manu[]);
	void acquire(char upc[]);
	void showInfo();
	void total(int num);
	void outPut(char* ptr);
	CCommodity();
	~CCommodity();

private:
	long m_nld = 0; // ��ƷΨһ��ʶ
	char* m_pszUpc = NULL; // ͨ�ò�Ʒ����
	char* m_pszName = NULL; // ��Ʒ����
	double m_dPrice = 0; // ��Ʒ�۸�
	char* m_pszManufacturer = NULL; // ��Ʒ������

};

#endif