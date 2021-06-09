#include "Poker.h"

CPoker::CPoker()
{
	//实例化 玩家类
	CDeck Deck;
	//CCard Card;
	cout << "CPoker 的构造函数调用" << endl;
}

void CPoker::Deal()
{
	CCard Card;  //实例化牌类,作为参数传递
	m_hDeckA.Add(&Card);
	m_hDeckB.Add(&Card);
	m_hDeckC.Add(&Card);

}

void CPoker::getA()
{
	cout << "玩家A的牌：" << endl;
	cout << endl;
	m_hDeckA.show();
	cout << endl;
	cout << endl;
}

void CPoker::getB()
{
	cout << "玩家B的牌：" << endl;
	cout << endl;
	m_hDeckB.show();
	cout << endl;
	cout << endl;
}

void CPoker::getC()
{
	cout << "玩家C的牌：" << endl;
	cout << endl;
	m_hDeckC.show();
	cout << endl;
	cout << endl;
}
