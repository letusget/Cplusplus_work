#include "Card.h"

CCard::CCard()
{
	int Flush = 0;  //Ĭ���Ǻ���

	m_nNumber[0] = "JOKER_m";
	m_nNumber[1] = "JOKER_M";
	
	init(2);  //���� [2,14]
	init(15);  //����  [15,27]
	init(28);  //����  [28,40]
	init(41);  //÷��  [41,53]


}



void CCard::init(int pos)
{
	//int Flush;

	//switch (Flush)
	//{
	//case HEART:  //����

	//	break;
	//case SPADE:   //����
	//	break;
	//case DIAMOND:   //����
	//	break;
	//case CLUB:
	//	break;
	//case JOKER:   //÷��
	//	break;
	//default:
	//	break;
	//}

	//������string���ͣ� "" ��ʾ�ڲ����ַ�����''��ʾ�ڲ����ַ�char
	m_nNumber[pos] = "A";
	int ch = 2;  //�������õ�ch �����������������
	for (int i = pos+1; i <= pos+8; i++)
	{
		m_nNumber[i] = ch + '0';  //ǿ������ת������int ��תΪ char �ͣ������ַ�����
		ch++;

	}
	m_nNumber[pos+9] = "10";  //���������"" ,��ʾ���ַ����������޷�char���޷��洢��λ��10 ��
	m_nNumber[pos+10] = 'J';
	m_nNumber[pos+11] = 'Q';
	m_nNumber[pos+12] = 'K';

	////������string���ͣ� "" ��ʾ�ڲ����ַ�����''��ʾ�ڲ����ַ�char
	//m_nMumber[2] = "A";
	//for (int i = 2; i <= 9; i++)
	//{
	//	m_nMumber[i] = i + '0';
	//}
	//m_nMumber[11] = "10";  //���������"" ,��ʾ���ַ����������޷�char���޷��洢��λ��10 ��
	//m_nMumber[12] = 'J';
	//m_nMumber[13] = 'Q';
	//m_nMumber[14] = 'K';


}

void CCard::show_Num()
{
	cout << m_nNumber[0] << endl;
	cout << m_nNumber[1] << endl;
	int count = 0;
	for (int i = 2; i <= MAXSIZE-1; i++)
	{
		count++;
		cout << m_nNumber[i] << "\t";
		if (count%13==0)
		{
			cout << endl;
		}

	}
}

string CCard::get_Num(int pos)
{
	//cout << "�������ȡ��" << endl;
	return m_nNumber[pos];
}

string CCard::deleNum(int pos)
{
	cout << "Ҫɾ����λ��Ϊ��" << pos << endl;
	//����ɾ��ʱ һ��Ҫע��λ�ã�������������з��ʳ�ͻ

	//for (int i = pos+1; i <num_Size; i++)
	//{
	//	m_nNumber[i-1] = m_nNumber[i];
	//	//����������Ը��� ����ɾ����ʹ�ã���Ϊ����ʱ �����ģ��޷��ı�
	//}
	//get_Size();  //ÿɾ��һ������Ҫ�����鳤���ֶ�ʹ֮����1

	//�����һ���Ʊ�ɾ������ô�洢�Ƶ�����ͽ����Ϊ -1����������ĳ��ȾͲ��䣬ֻ�ı����Ա
	if (m_nNumber[pos]== "-1")
	{
		cout << "deleNum���ַ��Ѿ���ɾ����" << endl;
		//return;
	}
	else
	{
		m_nNumber[pos] = "-1";
	}

	return string();
}

int CCard::get_Size()
{
	num_Size -= 1;
	return num_Size;
}

int CCard::get_Dele(int pos)
{
	if (m_nNumber[pos]=="-1")
	{
		cout << "get_Dele���ַ��Ѿ���ɾ����" << endl;
		return -1;
	}
	else
	{
		return 0;
	}
	
}

//string CCard::get_Fmum()
//{
//	return m_nMumber[MAXSIZE];
//}
