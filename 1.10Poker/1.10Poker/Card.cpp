#include "Card.h"

CCard::CCard()
{
	int Flush = 0;  //默认是红桃

	m_nNumber[0] = "JOKER_m";
	m_nNumber[1] = "JOKER_M";
	
	init(2);  //红桃 [2,14]
	init(15);  //黑桃  [15,27]
	init(28);  //方块  [28,40]
	init(41);  //梅花  [41,53]


}



void CCard::init(int pos)
{
	//int Flush;

	//switch (Flush)
	//{
	//case HEART:  //红桃

	//	break;
	//case SPADE:   //黑桃
	//	break;
	//case DIAMOND:   //方块
	//	break;
	//case CLUB:
	//	break;
	//case JOKER:   //梅花
	//	break;
	//default:
	//	break;
	//}

	//由于是string类型， "" 表示内部是字符串，''表示内部是字符char
	m_nNumber[pos] = "A";
	int ch = 2;  //这是设置的ch 就是用于设置牌面的
	for (int i = pos+1; i <= pos+8; i++)
	{
		m_nNumber[i] = ch + '0';  //强制类型转换，将int 型转为 char 型，存入字符数组
		ch++;

	}
	m_nNumber[pos+9] = "10";  //这里必须是"" ,表示是字符串，否则无法char是无法存储两位数10 的
	m_nNumber[pos+10] = 'J';
	m_nNumber[pos+11] = 'Q';
	m_nNumber[pos+12] = 'K';

	////由于是string类型， "" 表示内部是字符串，''表示内部是字符char
	//m_nMumber[2] = "A";
	//for (int i = 2; i <= 9; i++)
	//{
	//	m_nMumber[i] = i + '0';
	//}
	//m_nMumber[11] = "10";  //这里必须是"" ,表示是字符串，否则无法char是无法存储两位数10 的
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
	//cout << "在这里获取牌" << endl;
	return m_nNumber[pos];
}

string CCard::deleNum(int pos)
{
	cout << "要删除的位置为：" << pos << endl;
	//这里删除时 一定要注意位置！！！，否则会有访问冲突

	//for (int i = pos+1; i <num_Size; i++)
	//{
	//	m_nNumber[i-1] = m_nNumber[i];
	//	//数组仅仅可以覆盖 代替删除的使用，因为数组时 定长的，无法改变
	//}
	//get_Size();  //每删除一个，就要将数组长度手动使之减少1

	//如果有一张牌被删除，那么存储牌的数组就将其变为 -1，这样数组的长度就不变，只改变其成员
	if (m_nNumber[pos]== "-1")
	{
		cout << "deleNum该字符已经被删除！" << endl;
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
		cout << "get_Dele该字符已经被删除！" << endl;
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
