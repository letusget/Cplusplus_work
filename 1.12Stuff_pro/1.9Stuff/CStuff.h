#pragma once

#include <iostream>
#include <string>
using namespace std;

class CStuff
{
public:
	enum m_StuffType {
		STUDENT, //ѧ��
		TEACHER, //��ʦ
		EXECUTIVE, //������Ա

	};
public:
	
	virtual void Print() = 0;  //��Ҫ��д�ĳ�����


protected:
	long m_nld;  //��ʾID��ʹ�ø�������Ψһ��ʶѧ���ͽ�ְԱ��
	string m_pszNo ;  //���
	string m_pszName;  //����
	int m_nAge;  //����
	char m_nGender;  //�Ա�


};
