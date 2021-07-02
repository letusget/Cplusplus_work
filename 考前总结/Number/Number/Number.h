#pragma once
#ifndef _NUMBER_H_
#define _NUMBER_H_
#include <string>

class CNumber {
public:
	//参数列表
	CNumber(int nValue = 0): m_nValue(nValue) {};
	std::string ToBase(int nBase = 10);
	std::string ToBin();
	std::string ToOct();
	std::string ToHex();
	int GetValue()const { return m_nValue; }
private:
	std::string Digit2Alpha(int nDigit);
	int m_nValue;
};

#endif//_NUMBER_H_