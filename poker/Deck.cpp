#include "Deck.h"

CDeck::CDeck()
{
	//CCard card;
	//m_hCards.push_back(&card);  //��ʵ�����õ������������
	//card.show_Num();
	
}

//void CDeck::show()
//{
//	
//}

bool CDeck::Add(CCard* pCard)
{
	srand((int)time(NULL));  //���������������������
	Sleep(100);
	cout << "Ŀǰ�����Ƶ�����Ϊ��" << card_num << endl;	
	int choice = 0;  //����ѡ��
	int num = 0;  //��¼�õ����Ƶ�����
	int MSIZE = MAXSIZE;  //��������������ĸ���

	for (int i = 0; i < SIZE; i++)  //ȷ��ÿ������18����
	{
		srand((int)time(NULL));  //���������������������
		choice=(rand() % (MSIZE -1 - 0)) + 0;  //ѡ��һ���������

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
				//cout << "����ѡ���ƣ�" << endl;
				choice = (rand() % (MSIZE - 1 - 0)) + 0;  //����ѡ��һ���������

				cout << "choice2:  " << choice << endl;
			}
		}
		cout << "����Ҫ��:" << pCard->get_Num(choice) << "\t˳��Ϊ:"<<choice << endl;
		cout << endl;

		//�жϻ�ɫ
		if (choice==0)
		{
			percard[i] = "JOKER : " + pCard->get_Num(choice);
			pCard->deleNum(choice);  //���ƶ� ɾ���Ѿ�ʹ�õ���
			ischose[i] = pCard->get_Num(choice);  //����Ѿ�ʹ�õ��ƣ������´��жϸ����Ƿ��ܱ�ʹ��

			/*cout << endl;
			cout << "��ѡ�����Ϊ��" << ischose[i] << endl;
			cout << "λ��Ϊ��" << choice << endl;
			cout << endl;*/

			num++;
		}
		else if (choice==1)
		{
			percard[i] = "JOKER : " + pCard->get_Num(choice);
			pCard->deleNum(choice);  //���ƶ� ɾ���Ѿ�ʹ�õ���
			ischose[i] = pCard->get_Num(choice);  //����Ѿ�ʹ�õ��ƣ������´��жϸ����Ƿ��ܱ�ʹ��
			num++;

			/*cout << endl;
			cout << "��ѡ�����Ϊ��" << ischose[i] << endl;
			cout << "λ��Ϊ��" << choice << endl;
			cout << endl;*/

		}
		else if (choice>=2&&choice<=14)
		{
			percard[i] = "HEART : " + pCard->get_Num(choice);
			pCard->deleNum(choice);  //���ƶ� ɾ���Ѿ�ʹ�õ���
			ischose[i] = pCard->get_Num(choice);  //����Ѿ�ʹ�õ��ƣ������´��жϸ����Ƿ��ܱ�ʹ��
			num++;

			/*cout << endl;
			cout << "��ѡ�����Ϊ��" << ischose[i] << endl;
			cout << "λ��Ϊ��" << choice << endl;
			cout << endl;*/

		}
		else if (choice>=15&&choice<=27)
		{
			percard[i] = "SPADE : " + pCard->get_Num(choice);
			pCard->deleNum(choice);  //���ƶ� ɾ���Ѿ�ʹ�õ���
			ischose[i] = pCard->get_Num(choice);  //����Ѿ�ʹ�õ��ƣ������´��жϸ����Ƿ��ܱ�ʹ��
			num++;
		}
		else if (choice>=28&&choice<=40)
		{
			percard[i] = "DIAMOND : " + pCard->get_Num(choice);
			pCard->deleNum(choice);  //���ƶ� ɾ���Ѿ�ʹ�õ���
			ischose[i] = pCard->get_Num(choice);  //����Ѿ�ʹ�õ��ƣ������´��жϸ����Ƿ��ܱ�ʹ��
			num++;
		}
		else if (choice>=41&&choice<=53)
		{
			percard[i] = "CLUB : " + pCard->get_Num(choice);
			pCard->deleNum(choice);  //���ƶ� ɾ���Ѿ�ʹ�õ���
			ischose[i] = pCard->get_Num(choice);  //����Ѿ�ʹ�õ��ƣ������´��жϸ����Ƿ��ܱ�ʹ��
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

		cout << "�ѳɹ����18���ƣ�" << endl;
		cout << endl;
		return true;
	}
	else
	{
		cout << "δ�ܻ��18���ƣ�" << endl;
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
	cout << "show��������" << endl;
}

//CDeck::~CDeck()
//{
//	delete[] percard;
//}
