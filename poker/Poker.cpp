#include "Poker.h"

CPoker::CPoker()
{
	//ʵ���� �����
	CDeck Deck;
	//CCard Card;
	cout << "CPoker �Ĺ��캯������" << endl;
}

void CPoker::Deal()
{
	CCard Card;  //ʵ��������,��Ϊ��������
	m_hDeckA.Add(&Card);
	m_hDeckB.Add(&Card);
	m_hDeckC.Add(&Card);

}

void CPoker::getA()
{
	cout << "���A���ƣ�" << endl;
	cout << endl;
	m_hDeckA.show();
	cout << endl;
	cout << endl;
}

void CPoker::getB()
{
	cout << "���B���ƣ�" << endl;
	cout << endl;
	m_hDeckB.show();
	cout << endl;
	cout << endl;
}

void CPoker::getC()
{
	cout << "���C���ƣ�" << endl;
	cout << endl;
	m_hDeckC.show();
	cout << endl;
	cout << endl;
}
