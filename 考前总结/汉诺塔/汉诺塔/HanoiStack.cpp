#include <iostream>
#include <stack>
#include "HanoiItem.h"

//输出形式
void Print(CHanoiItem* pItem)
{
	std::cout << "#" << pItem->GetNumber()
		<< ": from" << pItem->GetSource() << " to " << pItem->GetTarget() << "\n";
}
/*
要使用栈实现汉诺塔，无论多少圆盘，都只需要三步就可以完成，按照顺序的三步
就要保证把最先执行的放在栈顶，最后执行的放在栈低
所以在安排入栈的时候，就要把最后要指定的那不先入栈，最先执行的那步在最后入栈
这样就可以先 执行栈顶了
*/
void Hanoi(std::stack<CHanoiItem*>& hStack) {
	
	//遍历该容器
	while (!hStack.empty())
	{
		CHanoiItem* pTop = hStack.top();  //pTop 获取栈顶的圆盘
		hStack.pop();  //栈顶 出栈

		//如果只有一个圆盘
		if (pTop->GetStation()==CHanoiItem::E||pTop->GetNumber()==1)
		{
			Print(pTop);  //打印栈顶元素
			delete pTop;  //销毁栈顶元素
			continue;  //进入下一次while循环
		}

//第三步先入栈				将n-1 个圆盘从source通过source移动到target上
		// station : source : target
		CHanoiItem* pItem = new CHanoiItem(pTop->GetNumber() - 1, 
			pTop->GetStation(), pTop->GetSource(), pTop->GetTarget());
		hStack.push(pItem);   //入栈n-1

//一个圆盘		将 1 个圆盘从source  移动到 target上
		// Just one item											这里有E，就是if要判断的一个条件
		pItem = new CHanoiItem(pTop->GetNumber(), pTop->GetSource(), CHanoiItem::E, pTop->GetTarget());
		hStack.push(pItem);   //入栈1

//第一步最后入栈，先执行		将 1 个圆盘从source  移动到 target上
		// source : target : station
		pItem = new CHanoiItem(pTop->GetNumber() - 1, pTop->GetSource(), pTop->GetTarget(), pTop->GetStation());
		hStack.push(pItem);   //入栈n-1

		//通过这三步，就可以实现 n 个圆盘的汉诺塔问题，因为是栈先进后出的特性，只能让 最先执行的 最后入栈

	}
}


int main() {
	std::stack<CHanoiItem*> hStack;
	CHanoiItem* pItem = new CHanoiItem(3, CHanoiItem::A, CHanoiItem::B, CHanoiItem::C);
	hStack.push(pItem);  //将汉诺塔类 入栈
	
	Hanoi(hStack);  //相当于递归调用的函数

	return 0;

}