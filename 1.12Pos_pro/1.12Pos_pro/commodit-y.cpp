#include "commodity.h"

CCommodity::CCommodity()
{
	//构造函数调用
}

//设置产品信息
void CCommodity::setInfo(long ld, string upc, string name, double price, string manu)
{
	m_nld = ld;
	m_pszUpc = upc;
	m_pszName = name;
	m_dPrice = price;
	m_pszManufacturer = manu;
}

// 获取用户输入的产品代码
void CCommodity::acquire(string upc)
{
	m_pszUpc = upc;
	if (m_pszUpc.length()!=0) {
		showInfo();
	}
}

// 展示产品信息
void CCommodity::showInfo()
{
	cout << "产品标识符：" << m_nld << endl;
	cout << "商品名称：" << m_pszName << endl; //outPut(m_pszName);
	//cout << "\n";
	cout << "单价：" << m_dPrice << endl;
	cout << "制造商信息：" << m_pszManufacturer << endl;
	//outPut(m_pszManufacturer);
	//cout << endl;
}

// 计算总价
void CCommodity::total(int num)
{
	double totalVal = m_dPrice * num;
	cout << "已选商品总价为：" << totalVal << endl;
	cout << endl;
	cout << endl;
}

void CCommodity::outPut(string ptr)
{
}

CCommodity::~CCommodity()
{
	//析构函数调用
}
