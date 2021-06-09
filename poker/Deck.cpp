#include "Deck.h"

CDeck::CDeck()
{
	//CCard card;
	//m_hCards.push_back(&card);  //将实例化好的类放入容器中
	//card.show_Num();
	
}

//void CDeck::show()
//{
//	
//}

bool CDeck::Add(CCard* pCard)
{
	srand((int)time(NULL));  //种子数，用来生成随机数
	Sleep(100);
	cout << "目前手中牌的数量为：" << card_num << endl;	
	int choice = 0;  //发牌选择
	int num = 0;  //记录得到的牌的数量
	int MSIZE = MAXSIZE;  //用来减少随机数的个数

	for (int i = 0; i < SIZE; i++)  //确保每个人有18张牌
	{
		srand((int)time(NULL));  //种子数，用来生成随机数
		choice=(rand() % (MSIZE -1 - 0)) + 0;  //选择一张随机的牌

		/*if (i==0)
		{
			while (-1 == pCard->get_Dele(choice))
			{
				choice = (rand() % (MSIZE - 1 - 0)) + 0;
				cout << "choice1:  " << choice << endl;

			}
		}*/

		/*while (-1 == pCard->get_Dele(choice))
		{
			choice = (rand() % (MSIZE - 1 - 0)) + 0;
			cout << "choice1:  " << choice << endl;

		}*/

		if (-1 == pCard->get_Dele(choice))
		{
			choice = (rand() % (MSIZE - 1 - 0)) + 0;
			cout << "choice1:  " << choice << endl;
		}

		for (int j = 0; j <= i; j++)
		{
			while(ischose[j]== pCard->get_Num(choice))
			{
				//cout << "重新选择牌！" << endl;
				choice = (rand() % (MSIZE - 1 - 0)) + 0;  //重新选择一张随机的牌

				cout << "choice2:  " << choice << endl;
			}
		}
		cout << "此牌要用:" << pCard->get_Num(choice) << "\t顺序为:"<<choice << endl;
		cout << endl;

		//判断花色
		if (choice==0)
		{
			percard[i] = "JOKER : " + pCard->get_Num(choice);
			pCard->deleNum(choice);  //从牌堆 删除已经使用的牌
			ischose[i] = pCard->get_Num(choice);  //存放已经使用的牌，用于下次判断该牌是否还能被使用

			/*cout << endl;
			cout << "被选择的牌为：" << ischose[i] << endl;
			cout << "位置为：" << choice << endl;
			cout << endl;*/

			num++;
		}
		else if (choice==1)
		{
			percard[i] = "JOKER : " + pCard->get_Num(choice);
			pCard->deleNum(choice);  //从牌堆 删除已经使用的牌
			ischose[i] = pCard->get_Num(choice);  //存放已经使用的牌，用于下次判断该牌是否还能被使用
			num++;

			/*cout << endl;
			cout << "被选择的牌为：" << ischose[i] << endl;
			cout << "位置为：" << choice << endl;
			cout << endl;*/

		}
		else if (choice>=2&&choice<=14)
		{
			percard[i] = "HEART : " + pCard->get_Num(choice);
			pCard->deleNum(choice);  //从牌堆 删除已经使用的牌
			ischose[i] = pCard->get_Num(choice);  //存放已经使用的牌，用于下次判断该牌是否还能被使用
			num++;

			/*cout << endl;
			cout << "被选择的牌为：" << ischose[i] << endl;
			cout << "位置为：" << choice << endl;
			cout << endl;*/

		}
		else if (choice>=15&&choice<=27)
		{
			percard[i] = "SPADE : " + pCard->get_Num(choice);
			pCard->deleNum(choice);  //从牌堆 删除已经使用的牌
			ischose[i] = pCard->get_Num(choice);  //存放已经使用的牌，用于下次判断该牌是否还能被使用
			num++;
		}
		else if (choice>=28&&choice<=40)
		{
			percard[i] = "DIAMOND : " + pCard->get_Num(choice);
			pCard->deleNum(choice);  //从牌堆 删除已经使用的牌
			ischose[i] = pCard->get_Num(choice);  //存放已经使用的牌，用于下次判断该牌是否还能被使用
			num++;
		}
		else if (choice>=41&&choice<=53)
		{
			percard[i] = "CLUB : " + pCard->get_Num(choice);
			pCard->deleNum(choice);  //从牌堆 删除已经使用的牌
			ischose[i] = pCard->get_Num(choice);  //存放已经使用的牌，用于下次判断该牌是否还能被使用
			num++;
		}
		else
		{
			cout << "Error!!!" << endl;
			cout << endl;
		}		
		
	}

	/*for (int i = 0; i < SIZE; i++)
	{
		cout << " " << percard[i] << " ";
	}*/
	if (num==18)
	{

		cout << "已成功获得18张牌！" << endl;
		cout << endl;
		return true;
	}
	else
	{
		cout << "未能获得18张牌！" << endl;
		cout << endl;
		return false;
	}

	MSIZE--;

}

bool CDeck::Add(Flush nFluash, int nNumber)
{
	//card_num = 0;
	for (int i = 0; i < nNumber; i++)
	{
		
	}

	return false;
}

bool CDeck::Contain(Flush nFlush, int nNumber)
{
	if (nFlush==0)
	{

	}
	else if (nFlush==1)
	{

	}
	else if (nFlush==2)
	{

	}
	else if (nFlush==3)
	{

	}
	else if (nFlush==4)
	{

	}
	else
	{
		cout << "Contain Error!!!" << endl;
	}
	return false;
}

bool CDeck::IsFull()
{
	return false;
}

void CDeck::Reset()
{
}

void CDeck::show()
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "  " << percard[i] << "\t";
	}
	cout << endl;
	cout << "show函数调用" << endl;
}

//CDeck::~CDeck()
//{
//	delete[] percard;
//}
