#include "Random.h"



CRandom::CRandom(int nBound,int nLimit)
{
	m_nValue = nBound;
	m_nCount = nLimit;
	cout << "Ĭ�ϲ²�������Χ��0-" << m_nValue << endl;
	cout << "Ĭ�ϲ²����Ϊ��" << m_nCount << endl;
	cout << endl;

	srand((unsigned)time(NULL));  //������
	m_nValue = (rand() % (m_nCount - 0)) + 0;  //����[0,10)�������
	cout << "���ɵ������Ϊ��" << m_nValue << endl;
}

Result CRandom::Judge(int nValue)
{
	cout << endl;
	//cout << "���ɵ������Ϊ:" << m_nValue << endl;
	//cout << "�û����������Ϊ��" << nValue << endl;
	
	if (m_nCount==0)
	{
		return 4;
	}

	m_nCount--;
	cout << "�²����Ϊ��" << 10 - m_nCount << endl;


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
	cout << "���²����Ϊ��" << m_nCount << endl;
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