#define _CRT_SECURE_NO_WARNINGS 1
#include "commodity.h"

CCommodity::CCommodity(long m_nld,
	char * m_pszUpc,
	char * m_pszName,
	int m_dPrice,
	char * m_pszManufacturer)
{
	cout << "CCommodity的构造函数调用" << endl;
	this->m_nld = m_nld;
	this->m_pszUpc = m_pszUpc;
	this->m_pszName = m_pszName;
	this->m_dPrice = m_dPrice;
	this->m_pszManufacturer = m_pszManufacturer;

}
CCommodity::CCommodity()
{

}

void CCommodity::showmenu()
{
	cout <<"=========================================" << endl;
	cout <<"\t1. 录入产品信息" << endl;
	cout <<"\t2. 查找产品" << endl;
	cout <<"\t0. 退出系统" << endl;
	cout << "=========================================" << endl;
}

void CCommodity::print_nld(long nld)
{
	m_nld = nld;
	cout << "商品的价格为：" << m_nld<< endl;

}

void CCommodity::print_pszUpc(char * pszUpc)
{
	m_pszUpc = pszUpc;
	cout << "商品的通用产品代码：" << m_pszUpc << endl;

}

void CCommodity::print_pszName(char * pszName)
{
	m_pszName = pszName;
}

void CCommodity::print_dPrice(int dPrice)
{
	m_dPrice = dPrice;
	cout << "商品的价格为：" << m_dPrice << endl;
}

void CCommodity::print_pszManufacturer(char * pszManufacturer)
{
	m_pszManufacturer = pszManufacturer;
	cout << "商品的制造商为：" << m_pszManufacturer << endl;
}

void CCommodity::exitsys()  //退出系统
{
	cout << "成功退出系统" << endl;
	cout << "欢迎下次使用" << endl;
	exit(0);
}

void CCommodity::addPsz()  //添加产品信息
{
	cout << "请在下方输入产品信息" << endl;
	int addNum = 0;  //初始时为0
	cout << "即将录入几条产品信息：" << endl;
	cin >> addNum;
	while (addNum<0)  //输入检查
	{
		cout << "输入数据有误！请重新输入：" << endl;
		cin >> addNum;
	}
	cout << "已确认添加" << addNum << "条产品信息" << endl;
	int newSize = addNum + pszNum;
	CCommodity * newspace = new CCommodity[newSize];

	//如果原来有数据，就需要把原来空间下的数据拷贝到新空间下
	if (this->pszArray != NULL)  //只要有数据，则该指针就不空
	{
		for (int i = 0; i < this->pszNum; i++)
		{
			newspace[i] = this->pszArray[i];
		}
	}
	for (int i = 0; i < addNum; i++)
	{
		long m_nld;  //商品唯一标识
		char  m_pszUpc[50] = {};  //通用产品代码
		char * m_pszName=new char[50];  //商品名称 可以重复
		int m_dPrice;  //商品价格
		char * m_pszManufacturer=new char[80];  //商品制造商

		string input_nld = "请输入商品标识：";
		string input_pszUpc = "请输入通用产品代码（UPC）：";
		string input_pszName = "请输入商品名称：";
		string input_dprice = "请输入商品价格：";
		string input_pszManufacturer = "请输入商品制造商：";

		cout << "第"<< i+1<< "条: "<<input_nld;
		cin >> m_nld;
		
		cout << "第" << i + 1 << "条: "<<input_pszUpc;
		cin >> m_pszUpc;

		cout << "第" << i + 1 << "条: " << input_pszName;
		cin >> m_pszName;
		
		cout << "第" << i + 1 << "条: " << input_dprice;
		cin >> m_dPrice;
		
		cout << "第" << i + 1 << "条: " << input_pszManufacturer;
		cin >> m_pszManufacturer;

		CCommodity* Commodity = NULL;

		Commodity = new CCommodity(m_nld,m_pszUpc,m_pszName,m_dPrice,m_pszManufacturer);

	}
	/*cout << endl;
	cout << endl;
	for (int i = 0; i <this->pszNum; i++)
	{
		cout << "产品标识码为：" << this->pszArray[i].m_nld << endl;
	}*/

	//释放原有空间
	delete[] this->pszArray;
	//更改新空间的指向
	this->pszArray = newspace;
	//更新新的职工人数
	this->pszNum = newSize;

	//提示添加成功
	cout << "成功添加" << addNum << "条新产品信息" << endl;
	cout << "一共" << this->pszNum << "条产品信息" << endl;
	
	
}

void CCommodity::psz_Find(char *id)  //查找产品信息并输出信息
{
	cout << "您要查找的通用产品代码（UPC）为：" << *id << endl;

	for (int i = 0; i < this->pszNum; i++)
	{
		//int temp = strcmp(id, this->m_pszUpc);
		//cout << "temp= " << temp << endl;
		cout << "10" << endl;
		if(strcmp(id,m_pszUpc)==0)  //判断两个字符串相等，如果相等则返回0
		{
			cout << "输出2" << endl;

			cout << "成功找到产品信息" << endl;
			cout << "产品标识符：" << this->m_nld << endl;
			cout << "通用产品代码：" << this->m_pszUpc << endl;
			cout << "商品名称：" << this->m_pszName << endl;
			cout << "商品价格：" << this->m_dPrice << endl;
			cout << "商品制造商：" << this->m_pszManufacturer << endl;
		}
		else
		{
			cout << "输出3" << endl;

			cout << "无法找到该数据，请提前录入数据！！" << endl;
		}
	}

}

CCommodity::~CCommodity()
{
	cout << "CCommodity 的析构函数调用" << endl;
	if (m_pszName!=NULL)
	{
		delete m_pszName;
	}
	if (m_pszName!=NULL)
	{
		delete m_pszName;
	}
	if (m_pszManufacturer!=NULL)
	{
		delete m_pszManufacturer;
	}

}