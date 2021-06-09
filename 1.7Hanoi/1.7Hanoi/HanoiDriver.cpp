#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class CHanoi
{
public: 
	void Move(int n, char source, char station, char target);
	static CHanoi* GetInstance()
	{
		if (m_pInstance==NULL)
		{
			m_pInstance = new CHanoi;  //��������ڸ��࣬�ʹ������࣬������ھͷ��ظ���
		}
		return m_pInstance;
	}
private:
	void Show(int n, char source, char target);
	static CHanoi* m_pInstance;  //ָ��ʵ���ľ�ָ̬��
	//������ָ���ǿյģ���˵������û������࣬�򴴽�������ǿգ������������ֱ࣬�ӷ��������

};
CHanoi* CHanoi::m_pInstance = NULL;

int main()
{
	CHanoi* Han = CHanoi::GetInstance();  //�Լ��ʷ�ʽʵ��
	Han->Move(5, 'A', 'B', 'C');
	return 0;
}

void CHanoi::Move(int n, char source, char station, char target)
{
	if (n == 1)
	{//���ֻ��һ���Ͱ���ֱ�ӷŵ�Ŀ������
		Show(1, source, target);
	}
	else
	{//�������һ�������Ȱ�n-1��ͨ��Ŀ�����ŵ���ת���ϣ��ٰ����ŵ�Ŀ������
		Move(n - 1, source, target, station);
		Show(n, source, target);//չʾ��Ϣ
		Move(n - 1, station, source, target);
	}
}

void CHanoi::Show(int n, char source, char target)
{
	cout << "#" << n <<":" << source << "->" << target << endl;
}





