#pragma once
class CHanoiItem
{
public:
	/*ʹ�ó�ʼ���б� �����࣬�������﷨��
	���캯������������1��ֵ1��������2��ֵ2��...{}
	�൱�ڹ��캯����ʹ��
	*/
	CHanoiItem(int nNumber,char nSource,char nStation,char nTarget)
		:m_nNumber(nNumber),m_nSource(nSource),m_nStation(nStation),m_nTarget(nTarget){}

	//���ذ汾�Ĺ��캯��
	CHanoiItem(const CHanoiItem& hSource)
		:m_nNumber(hSource.m_nNumber),m_nSource(hSource.m_nSource),
		m_nStation(hSource.m_nStation),m_nTarget(hSource.m_nTarget){}

	//���� = ������
	CHanoiItem& operator=(const CHanoiItem& hSource) {
		m_nNumber = hSource.m_nNumber;
		m_nSource = hSource.m_nSource;
		m_nStation = hSource.m_nStation;
		m_nTarget = hSource.m_nTarget;
		return *this;
	}

	//������������
	virtual ~CHanoiItem(){}

	//��ȡ˽�г�Ա����
	int GetNumber() { return m_nNumber; }  //��ȡԲ����
	char GetSource() { return m_nSource; }  //��ȡ ����
	char GetStation() { return m_nStation; }  //��ȡ ��ת��
	char GetTarget() { return m_nTarget; }  //��ȡĿ����

	//ȫ�ֱ���
	static const char A = 'A';
	static const char B = 'B';
	static const char C = 'C';
	static const char E = 'E';

private:
	int m_nNumber;
	char m_nSource;
	char m_nStation;
	char m_nTarget;


};
