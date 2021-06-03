#pragma once
#include <iostream>
#include <string>
using namespace std;

class CCommodity
{
public:
	CCommodity(long m_nld, 
	char * m_pszUpc,
	char * m_pszName,
	int m_dPrice,
	char * m_pszManufacturer);

	CCommodity();

	void showmenu();  //展示菜单信息
	void exitsys();  //退出系统
	void addPsz();  //添加产品信息
	int pszNum;  //记录产品个数
	CCommodity * pszArray;
	void psz_Find(char *id);  //查找产品信息
	//void psz_Print(char *id);

	void print_nld(long nld);

	void print_pszUpc(char * pszUpc);
	
	void print_pszName(char * pszName);
	
	void print_dPrice(int dPrice);
	
	void print_pszManufacturer(char * pszManufactruer);
	
	
	~CCommodity();

private:
	long m_nld;  //商品唯一标识
	char * m_pszUpc;  //通用产品代码
	char * m_pszName;  //商品名称 可以重复
	int m_dPrice;  //商品价格
	char * m_pszManufacturer;  //商品制造商

};


