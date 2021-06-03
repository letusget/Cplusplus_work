#define _CRT_SECURE_NO_WARNINGS 1


//template<typename T>
//T cube(T a)
//{
//	//cout << "函数模板" << endl;
//	return a*a;
//}
//
//template<typename S>
//S square(S a)
//{
//	return S();
//}
namespace util
{
	template<typename T>
	T cube(T a)
	{
		//cout << "函数模板" << endl;
		return a*a;
	}

	template<typename S>
	S square(S a)
	{
		return S();
	}
}
//名空间的使用，实现文件
//这里是对名空间的扩充，也是实现分离的作用

