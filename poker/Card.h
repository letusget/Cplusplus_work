#pragma once
#include <iostream>
#include <string>
//#include "Porker.h"  //���ﲻ���԰������ͷ�ļ�������ͻᱨ��
using namespace std;
#define MAXSIZE 54

enum Flush  //��ʾ��ɫ
{
	HEART = 0,   //����
	SPADE,   //����
	DIAMOND,  //����
	CLUB,   //÷��
	JOKER,  //��С��
};


class CCard
{
public:
	CCard();  //��ʼ��һ����ɫ�ģ�������С����13 ����
	void init(int pos);
	void show_Num();   //��ʾ�Ƶ���Ϣ
	string get_Num(int pos);  //��ȡ�Ƶ���Ϣ
	string deleNum(int pos);  //ɾ���Ƶ���Ϣ
	int get_Size();  //��ȡm_nNumber �ĳ���
	int get_Dele(int pos);  //��ȡɾ������Ϣ
	int num_Size = MAXSIZE;  //��������ĳ���
	//string get_Fmum();

	

private:
	Flush m_nFlush;
	string m_nNumber[MAXSIZE];
	//���ó�Ա����Ϊstring���ͣ����Ա�ֽ֤�Ƶ����ݿ��Ա���10��������λ���������ǽ����Ա���char����
};
