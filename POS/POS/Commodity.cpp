#include <iostream>
#include "Commodity.h"

// CCommodity类实现

#define N 10

using namespace std;

CCommodity::CCommodity() {
	//cout << "CommodityInfo is being created!" << endl;
}

void CCommodity::setInfo(long ld, char upc[], char name[], double price, char manu[]) {
	m_nld = ld;
	m_pszUpc = upc;
	m_pszName = name;
	m_dPrice = price;
	m_pszManufacturer = manu;
}

// 获取用户输入的产品代码
void CCommodity::acquire(char upc[]) {
	m_pszUpc = upc;
	if (*m_pszUpc) {
		showInfo();
	}
}

// 展示产品信息
void CCommodity::showInfo() {
	cout << "商品名称："; outPut(m_pszName);
	cout << "\n";
	cout << "单价：" << m_dPrice << "\n";
	cout << "制造商信息："; outPut(m_pszManufacturer);
	cout << endl;
}

// 计算总价
void CCommodity::total(int num) {
	double totalVal = m_dPrice * num;
	cout << "已选商品总价为：" << totalVal << endl;
}

// 为能输出char*型类成员变量
void CCommodity::outPut(char* ptr) {
	for (int i = 0; i < N; i++) {
		cout << *(ptr + i);
	}
}


CCommodity::~CCommodity()
{
	//cout << "It has been deleted." << endl;
}