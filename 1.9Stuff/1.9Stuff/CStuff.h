#pragma once
#define _CRT_SECURE_NO_WARNINGS 1  //΢��İ�ȫ��������
#include <iostream>
#include <cstring>
using namespace std;

class CStuff
{
public:
	enum m_StuffType {
		STUDENT, //ѧ��
		TEACHER, //��ʦ
		EXECUTIVE, //������Ա

	};

	void setInfo(long nId, const char* pszNo, const char* pszName, int nAge,
		char nGender);
	virtual void Print() = 0;  //��Ҫ��д�ĳ�����


protected:
	long m_nld;  //��ʾID��ʹ�ø�������Ψһ��ʶѧ���ͽ�ְԱ��
	char* m_pszNo;  //���
	char* m_pszName;  //����
	int m_nAge=0;  //����
	char m_nGender='m';  //�Ա�


};
