#pragma once
class CHanoiItem
{
public:
	/*使用初始化列表 构造类，下面是语法：
	构造函数（）：属性1（值1），属性2（值2）...{}
	相当于构造函数的使用
	*/
	CHanoiItem(int nNumber,char nSource,char nStation,char nTarget)
		:m_nNumber(nNumber),m_nSource(nSource),m_nStation(nStation),m_nTarget(nTarget){}

	//重载版本的构造函数
	CHanoiItem(const CHanoiItem& hSource)
		:m_nNumber(hSource.m_nNumber),m_nSource(hSource.m_nSource),
		m_nStation(hSource.m_nStation),m_nTarget(hSource.m_nTarget){}

	//重载 = 操作符
	CHanoiItem& operator=(const CHanoiItem& hSource) {
		m_nNumber = hSource.m_nNumber;
		m_nSource = hSource.m_nSource;
		m_nStation = hSource.m_nStation;
		m_nTarget = hSource.m_nTarget;
		return *this;
	}

	//纯虚析构函数
	virtual ~CHanoiItem(){}

	//获取私有成员变量
	int GetNumber() { return m_nNumber; }  //获取圆盘数
	char GetSource() { return m_nSource; }  //获取 底座
	char GetStation() { return m_nStation; }  //获取 中转座
	char GetTarget() { return m_nTarget; }  //获取目标座

	//全局变量
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
