#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include"Number.h"

std::string CNumber::ToBase(int nBase/*=10*/)
{
	//����ȡ�෨
	std::string  sResult;
	for (int nValue = m_nValue; nValue != 0; nValue /= nBase) 
	{
		if (!sResult.empty()) //��Ϊ��
		{
			sResult.insert(0, 1, '_');
		}
		sResult.insert(0, Digit2Alpha(nValue % nBase));  //�������
	}

	return sResult;
}

std::string CNumber::ToBin(){
	return ToBase(2);
};

std::string CNumber::ToHex() {
	return ToBase(16);
}

std::string CNumber::ToOct() {
	return ToBase(8);
}


std::string CNumber::Digit2Alpha(int nDigit) {
	int nCount = 0, nValue = nDigit;

	do {
		nCount++;
		nValue /= 10;
	} while (nValue);

	char* pCache = new char[nCount + 1];
	sprintf(pCache, "%d", nDigit);

	std::string sResult(pCache);
	delete[] pCache;

	return sResult;
}
