#include "Random.h"



CRandom::CRandom(int nBound,int nLimit)
{
	m_nValue = nBound;
	m_nCount = nLimit;
	cout << "默认猜测整数范围：0-" << m_nValue << endl;
	cout << "默认猜测次数为：" << m_nCount << endl;
	cout << endl;

	srand((unsigned)time(NULL));  //种子数
	m_nValue = (rand() % (m_nCount - 0)) + 0;  //生成[0,10)的随机数
	cout << "生成的随机数为：" << m_nValue << endl;
}

Result CRandom::Judge(int nValue)
{
	cout << endl;
	//cout << "生成的随机数为:" << m_nValue << endl;
	//cout << "用户输入的数字为：" << nValue << endl;
	
	if (m_nCount==0)
	{
		return 4;
	}

	m_nCount--;
	cout << "猜测次数为：" << 10 - m_nCount << endl;


	while (nValue!=m_nValue)
	{
		if (nValue == m_nValue)
		{

			return 1;
		}
		else if (nValue < m_nValue)
		{
			//m_nCount--;
			return 2;
		}
		else if (nValue > m_nValue)
		{
			//m_nCount--;
			return 3;
		}
		//else if (m_nCount == 0)
		//{
		//	//m_nCount--;
		//	return 4;
		//}
		else
		{
			return -1;
		}
	}


	return 1;
	
	
	//return 1;
}

void CRandom::Start()
{
	
	m_nCount = 10;
	cout << "最多猜测次数为：" << m_nCount << endl;
	cout << endl;

}

int CRandom::getValue()
{
	return m_nValue;
}

int CRandom::getCount()
{
	return m_nCount;
}


//CRandom::~CRandom()
//{
//	delete ;
//}