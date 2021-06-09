#pragma once
#include <iostream>
#include <string>
//#include "Porker.h"  //这里不可以包含这个头文件，否则就会报错
using namespace std;
#define MAXSIZE 54

enum Flush  //表示花色
{
	HEART = 0,   //红桃
	SPADE,   //黑桃
	DIAMOND,  //方块
	CLUB,   //梅花
	JOKER,  //大小王
};


class CCard
{
public:
	CCard();  //初始化一个花色的，不含大小王的13 张牌
	void init(int pos);
	void show_Num();   //显示牌的信息
	string get_Num(int pos);  //获取牌的信息
	string deleNum(int pos);  //删除牌的信息
	int get_Size();  //获取m_nNumber 的长度
	int get_Dele(int pos);  //获取删除的信息
	int num_Size = MAXSIZE;  //数组最初的长度
	//string get_Fmum();

	

private:
	Flush m_nFlush;
	string m_nNumber[MAXSIZE];
	//将该成员定义为string类型，可以保证纸牌的数据可以保存10这样的两位数，而不是仅可以保存char类型
};
