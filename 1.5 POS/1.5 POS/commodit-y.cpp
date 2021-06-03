#define _CRT_SECURE_NO_WARNINGS 1
#include "commodity.h"

CCommodity::CCommodity(long m_nld,
	char * m_pszUpc,
	char * m_pszName,
	int m_dPrice,
	char * m_pszManufacturer)
{
	cout << "CCommodity�Ĺ��캯������" << endl;
	this->m_nld = m_nld;
	this->m_pszUpc = m_pszUpc;
	this->m_pszName = m_pszName;
	this->m_dPrice = m_dPrice;
	this->m_pszManufacturer = m_pszManufacturer;

}
CCommodity::CCommodity()
{

}

void CCommodity::showmenu()
{
	cout <<"=========================================" << endl;
	cout <<"\t1. ¼���Ʒ��Ϣ" << endl;
	cout <<"\t2. ���Ҳ�Ʒ" << endl;
	cout <<"\t0. �˳�ϵͳ" << endl;
	cout << "=========================================" << endl;
}

void CCommodity::print_nld(long nld)
{
	m_nld = nld;
	cout << "��Ʒ�ļ۸�Ϊ��" << m_nld<< endl;

}

void CCommodity::print_pszUpc(char * pszUpc)
{
	m_pszUpc = pszUpc;
	cout << "��Ʒ��ͨ�ò�Ʒ���룺" << m_pszUpc << endl;

}

void CCommodity::print_pszName(char * pszName)
{
	m_pszName = pszName;
}

void CCommodity::print_dPrice(int dPrice)
{
	m_dPrice = dPrice;
	cout << "��Ʒ�ļ۸�Ϊ��" << m_dPrice << endl;
}

void CCommodity::print_pszManufacturer(char * pszManufacturer)
{
	m_pszManufacturer = pszManufacturer;
	cout << "��Ʒ��������Ϊ��" << m_pszManufacturer << endl;
}

void CCommodity::exitsys()  //�˳�ϵͳ
{
	cout << "�ɹ��˳�ϵͳ" << endl;
	cout << "��ӭ�´�ʹ��" << endl;
	exit(0);
}

void CCommodity::addPsz()  //��Ӳ�Ʒ��Ϣ
{
	cout << "�����·������Ʒ��Ϣ" << endl;
	int addNum = 0;  //��ʼʱΪ0
	cout << "����¼�뼸����Ʒ��Ϣ��" << endl;
	cin >> addNum;
	while (addNum<0)  //������
	{
		cout << "���������������������룺" << endl;
		cin >> addNum;
	}
	cout << "��ȷ�����" << addNum << "����Ʒ��Ϣ" << endl;
	int newSize = addNum + pszNum;
	CCommodity * newspace = new CCommodity[newSize];

	//���ԭ�������ݣ�����Ҫ��ԭ���ռ��µ����ݿ������¿ռ���
	if (this->pszArray != NULL)  //ֻҪ�����ݣ����ָ��Ͳ���
	{
		for (int i = 0; i < this->pszNum; i++)
		{
			newspace[i] = this->pszArray[i];
		}
	}
	for (int i = 0; i < addNum; i++)
	{
		long m_nld;  //��ƷΨһ��ʶ
		char  m_pszUpc[50] = {};  //ͨ�ò�Ʒ����
		char * m_pszName=new char[50];  //��Ʒ���� �����ظ�
		int m_dPrice;  //��Ʒ�۸�
		char * m_pszManufacturer=new char[80];  //��Ʒ������

		string input_nld = "��������Ʒ��ʶ��";
		string input_pszUpc = "������ͨ�ò�Ʒ���루UPC����";
		string input_pszName = "��������Ʒ���ƣ�";
		string input_dprice = "��������Ʒ�۸�";
		string input_pszManufacturer = "��������Ʒ�����̣�";

		cout << "��"<< i+1<< "��: "<<input_nld;
		cin >> m_nld;
		
		cout << "��" << i + 1 << "��: "<<input_pszUpc;
		cin >> m_pszUpc;

		cout << "��" << i + 1 << "��: " << input_pszName;
		cin >> m_pszName;
		
		cout << "��" << i + 1 << "��: " << input_dprice;
		cin >> m_dPrice;
		
		cout << "��" << i + 1 << "��: " << input_pszManufacturer;
		cin >> m_pszManufacturer;

		CCommodity* Commodity = NULL;

		Commodity = new CCommodity(m_nld,m_pszUpc,m_pszName,m_dPrice,m_pszManufacturer);

	}
	/*cout << endl;
	cout << endl;
	for (int i = 0; i <this->pszNum; i++)
	{
		cout << "��Ʒ��ʶ��Ϊ��" << this->pszArray[i].m_nld << endl;
	}*/

	//�ͷ�ԭ�пռ�
	delete[] this->pszArray;
	//�����¿ռ��ָ��
	this->pszArray = newspace;
	//�����µ�ְ������
	this->pszNum = newSize;

	//��ʾ��ӳɹ�
	cout << "�ɹ����" << addNum << "���²�Ʒ��Ϣ" << endl;
	cout << "һ��" << this->pszNum << "����Ʒ��Ϣ" << endl;
	
	
}

void CCommodity::psz_Find(char *id)  //���Ҳ�Ʒ��Ϣ�������Ϣ
{
	cout << "��Ҫ���ҵ�ͨ�ò�Ʒ���루UPC��Ϊ��" << *id << endl;

	for (int i = 0; i < this->pszNum; i++)
	{
		//int temp = strcmp(id, this->m_pszUpc);
		//cout << "temp= " << temp << endl;
		cout << "10" << endl;
		if(strcmp(id,m_pszUpc)==0)  //�ж������ַ�����ȣ��������򷵻�0
		{
			cout << "���2" << endl;

			cout << "�ɹ��ҵ���Ʒ��Ϣ" << endl;
			cout << "��Ʒ��ʶ����" << this->m_nld << endl;
			cout << "ͨ�ò�Ʒ���룺" << this->m_pszUpc << endl;
			cout << "��Ʒ���ƣ�" << this->m_pszName << endl;
			cout << "��Ʒ�۸�" << this->m_dPrice << endl;
			cout << "��Ʒ�����̣�" << this->m_pszManufacturer << endl;
		}
		else
		{
			cout << "���3" << endl;

			cout << "�޷��ҵ������ݣ�����ǰ¼�����ݣ���" << endl;
		}
	}

}

CCommodity::~CCommodity()
{
	cout << "CCommodity ��������������" << endl;
	if (m_pszName!=NULL)
	{
		delete m_pszName;
	}
	if (m_pszName!=NULL)
	{
		delete m_pszName;
	}
	if (m_pszManufacturer!=NULL)
	{
		delete m_pszManufacturer;
	}

}