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
			m_pInstance = new CHanoi;  //如果不存在该类，就创建该类，如果存在就返回该类
		}
		return m_pInstance;
	}
private:
	void Show(int n, char source, char target);
	static CHanoi* m_pInstance;  //指向实例的静态指针
	//如果这个指针是空的，就说明现在没有这个类，则创建，如果非空，则表明有这个类，直接返回这个类

};
CHanoi* CHanoi::m_pInstance = NULL;

int main()
{
	CHanoi* Han = CHanoi::GetInstance();  //以饥渴方式实现
	Han->Move(5, 'A', 'B', 'C');
	return 0;
}

void CHanoi::Move(int n, char source, char station, char target)
{
	if (n == 1)
	{//如果只有一个就把它直接放到目标座上
		Show(1, source, target);
	}
	else
	{//如果不是一个，就先把n-1个通过目标座放到中转座上，再把它放到目标座上
		Move(n - 1, source, target, station);
		Show(n, source, target);//展示信息
		Move(n - 1, station, source, target);
	}
}

void CHanoi::Show(int n, char source, char target)
{
	cout << "#" << n <<":" << source << "->" << target << endl;
}





