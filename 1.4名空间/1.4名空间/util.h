#pragma once  //��������������һ�Σ���ֹ�ظ�����ʹ��#ifndef ��� #endifЧ��һ��
#include <iostream>
namespace util  //�������ռ�
{
	template<typename T>  //ģ�庯��������
	T cube(T a);
	//T cube(T a)
	//{
	//	//cout << "����ģ��" << endl;
	//	return a*a;
	//}

	template<typename S>
	S square(S a);
	/*S square(S a)
	{
		return S();
	}*/
	/*
	��C++ �����޷���ģ�庯����������ʵ�ַ���ģ���Ϊ�������� ��ҪC++ Ҫȷ��ģ�庯���Ĵ�С
	����������޷�ȷ����С�ģ����о���Ҫ������ʵ����һ����������ʵ��ʱ�Ϳ�������ռ�
	�ο���https://blog.csdn.net/u010168781/article/details/90519128?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-3.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-3.control
	*/

}
#include "util.cpp"
//�������ø�ʵ�ֺ������Ϳ���ʵ�ֽ������Ͷ�����룬���������߼����룬��������Ҳ�Ƿ����

