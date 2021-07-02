#include "Random.h"

CRandom::CRandom(const int& nBound, const int& nLimit) {
	m_nBound = nBound;
	m_nLimit = nLimit;
	srand((unsigned)time(NULL));
}

void CRandom::Start() {
	m_nValue = (rand() % m_nBound + 0);
	//cout << "一共可猜测次数：" << m_nLimit << endl;
}

Result CRandom::Judge(int nValue) {
	if (m_nCount >= m_nLimit) {
		return EXCEED;
	}
	m_nCount++;

	while ((m_nCount < m_nLimit)) {
		if (nValue == m_nValue)
			return EQUAL;
		else if (m_nValue > nValue)
			return LESS;
		else if (m_nValue < nValue)
			return GREAT;
	}
}



int CRandom::getValue() {
	return m_nValue;
}

int CRandom::getCount() {
	return m_nLimit - m_nCount;
}
