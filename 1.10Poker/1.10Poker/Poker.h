#pragma once
#include "Deck.h"
//�����ͷ�ļ���ʵ�������࣬Ȼ�󴫵��� ����

class CPoker
{
public:
	CPoker();
	void Deal();  //Ϊ��������������,�ڷ���֮ǰ��ȷ�����������Ѿ�����λ��

	void getA();
	void getB();
	void getC();

private:
	CDeck m_hDeckA;  //��ʾ����������ҵ���
	CDeck m_hDeckB;
	CDeck m_hDeckC;
	
};