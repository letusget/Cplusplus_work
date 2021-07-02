#pragma once
#ifndef Commodity_H_ // 确保头文件不会被重复引用
#define Commodity_H_

// 创建商品类
class CCommodity
{
public:
	void setInfo(long ld, char upc[], char name[], double price, char manu[]);
	void acquire(char upc[]);
	void showInfo();
	void total(int num);
	void outPut(char* ptr);
	CCommodity();
	~CCommodity();

private:
	long m_nld = 0; // 商品唯一标识
	char* m_pszUpc = NULL; // 通用产品代码
	char* m_pszName = NULL; // 商品名称
	double m_dPrice = 0; // 商品价格
	char* m_pszManufacturer = NULL; // 商品制造商

};

#endif