#pragma once
#include "Deck.h"
//在这个头文件里实例化牌类，然后传递类 参数

class CPoker
{
public:
	CPoker();
	void Deal();  //为三个玩家随机发牌,在发牌之前，确保三个人是已经被复位的

	void getA();
	void getB();
	void getC();

private:
	CDeck m_hDeckA;  //表示发给三个玩家的牌
	CDeck m_hDeckB;
	CDeck m_hDeckC;
	
};