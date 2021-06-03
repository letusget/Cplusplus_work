#pragma once  //声明，仅仅调用一次，防止重复调用使用#ifndef 配合 #endif效果一样
#include <iostream>
namespace util  //定义名空间
{
	template<typename T>  //模板函数的声明
	T cube(T a);
	//T cube(T a)
	//{
	//	//cout << "函数模板" << endl;
	//	return a*a;
	//}

	template<typename S>
	S square(S a);
	/*S square(S a)
	{
		return S();
	}*/
	/*
	在C++ 中是无法将模板函数的声明和实现分离的，因为在声明后 需要C++ 要确定模板函数的大小
	而分离的是无法确定大小的，所有就需要声明和实现在一起，在声明后实现时就可以申请空间
	参考：https://blog.csdn.net/u010168781/article/details/90519128?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-3.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-3.control
	*/

}
#include "util.cpp"
//单独调用该实现函数，就可以实现将声明和定义分离，不仅仅是逻辑分离，在物理上也是分离的

