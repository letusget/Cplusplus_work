#pragma once
#include <iostream>
#include <string>
#define N 10 

using namespace std;


class CCommodity
{
public:
	CCommodity();
	//设置产品信息
	void setInfo(long ld, string upc, string name, double price, string manu);
	// 获取用户输入的产品代码
	void acquire(string upc);
	// 展示产品信息
	void showInfo();
	// 计算总价
	void total(int num);
	void outPut(string ptr);

	~CCommodity();

private:
	long m_nld;  //商品唯一标识
	string m_pszUpc;  //通用产品代码
	string m_pszName;  //商品名称 可以重复
	int m_dPrice;  //商品价格
	string m_pszManufacturer;  //商品制造商  

};
