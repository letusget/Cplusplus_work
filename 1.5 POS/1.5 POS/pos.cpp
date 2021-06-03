#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

#include "commodity.h"
using namespace std;



int main()
{
	//long m_nld;  //商品唯一标识

	//char * m_pszUpc;  //通用产品代码
	//m_pszUpc = (char *)malloc(20 * sizeof(char));
	//
	////char pszName;
	//char * m_pszName;  //商品名称 可以重复
	//m_pszName = (char *)malloc(20 * sizeof(char));

	//int m_dPrice;  //商品价格

	////char pszManufacturer;
	//char * m_pszManufacturer;  //商品制造商
	//m_pszManufacturer = (char *)malloc(20 * sizeof(char));

	//CCommodity product;
	////product print_nld();
	//string input_nld = "请输入商品标识：";
	//string input_pszUpc = "请输入产品代码：";
	//string input_pszName = "请输入商品名称：";
	//string input_dprice = "请输入商品价格：";
	//string input_pszManufacturer = "请输入商品制造商：";

	//cout << input_nld;
	//cin >> m_nld;
	//
	//cout << input_pszUpc;
	//cin >> *m_pszUpc;

	//cout << input_pszName;
	//cin >> *m_pszName;
	//
	//cout << input_dprice;
	//cin >> m_dPrice;
	//
	//cout << input_pszManufacturer;
	//cin >> *m_pszManufacturer;
	//
	//product.print_nld(m_nld);
	//product.print_pszUpc(m_pszUpc);
	//product.print_pszName(m_pszName);
	//product.print_dPrice(m_dPrice);
	//product.print_pszManufacturer(m_pszManufacturer);

	//free(m_pszUpc);
	//free(m_pszName);
	//free(m_pszManufacturer);

	CCommodity psz;
	while (1)
	{
		psz.showmenu();
		int choice = 0;
		char* psz_Id = new char[50];
		cout << "请选择要实现的功能：";
		cin >> choice;
		while (choice != 0 && choice != 1 && choice != 2)
		{
			cout << "输入错误，请重新输入" << endl;
			cin >> choice;
		}
		switch (choice)
		{
		default:
			cout << "输入错误信息，错误！！" << endl;
			break;
		case 0: //退出
			psz.exitsys();
			break;
		case 1:  //录入信息
			psz.addPsz();
			break;
		case 2:  //查找产品
			cout << "请输入要查找产品的通用产品代码（UPC）：" << endl;
			cin >> *psz_Id;
			
			//cout << "字符串比较结果："<< strcmp(psz_Id, psz.m_pszUpc)<< endl;
			psz.psz_Find(psz_Id);
			break;
		}

	}
	


	return 0;
}