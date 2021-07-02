#include <iostream>

using namespace std;

class CHanoi {
private:
	CHanoi() // 构造函数私有
	{
	}
	static CHanoi* m_pInstance; // 定义一个唯一指向实例的静态指针
	
	// n为第几号圆盘，source为源座，target为目标座；显示格式：#n：source->target
	void Show(int n, char source, char target) {
		cout << "#" << n << source << "->" << target << endl;
	}

public:
	// 单例模式，采用惰性方式创建全局唯一的实例，并获取唯一实例函数
	static CHanoi* GetInstance() {
		if (m_pInstance == NULL)
			m_pInstance = new CHanoi;
		return m_pInstance;
	}

	// n表示圆盘数量，source表示源座，即n个圆盘初始所在的座，station表示中转座，初始为空；target表示目标座，即n个圆盘应该被移动至的座；
	void Move(int n, char source, char station, char target) {
		if (n == 1) {
			Show(n, source, target);
		}
		else {
			Move(n - 1, source, target, station);
			Show(n, source, target);
			Move(n - 1, station, source, target);
		}
	}
};
CHanoi* CHanoi::m_pInstance = NULL;

int main() {
	CHanoi* p = CHanoi::GetInstance();
	p->Move(3, 'A', 'B', 'C');
	return 0;
}