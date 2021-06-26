#pragma once
#include <iostream>
#include <vector>
#include "Card.h"
#include <stdbool.h>
#include <windows.h>
#define SIZE 18
#include <ctime>

using namespace std;

class CDeck
{
public:
	

	CDeck();
	//void show(); 

	//����������ƣ�����Ѿ�����18���ƣ��ͷ���false
	bool Add(CCard* pCard);
	bool Add(Flush nFluash, int nNumber);

	bool Contain(Flush nFlush, int nNumber);  //ȷ���Ƿ��������������ֽ��
	
	bool IsFull();  //�ж��Ѿ�������18����
	void Reset();  //�������ֽ��

	void show();
	//~CDeck();
	
private:

	vector<CCard*> m_hCards;
	string ischose[SIZE];  //�жϸ����Ƿ��Ѿ���ʹ��
	int card_num=0;
	string percard[SIZE];
	
};

