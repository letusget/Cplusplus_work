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

	//向其中添加牌，如果已经有了18张牌，就返回false
	bool Add(CCard* pCard);
	bool Add(Flush nFluash, int nNumber);

	bool Contain(Flush nFlush, int nNumber);  //确定是否包含参数给定的纸牌
	
	bool IsFull();  //判断已经包含了18张牌
	void Reset();  //清空所有纸牌

	void show();
	//~CDeck();
	
private:

	vector<CCard*> m_hCards;
	string ischose[SIZE];  //判断该牌是否已经被使用
	int card_num=0;
	string percard[SIZE];
	
};

