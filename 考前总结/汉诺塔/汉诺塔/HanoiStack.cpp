#include <iostream>
#include <stack>
#include "HanoiItem.h"

//�����ʽ
void Print(CHanoiItem* pItem)
{
	std::cout << "#" << pItem->GetNumber()
		<< ": from" << pItem->GetSource() << " to " << pItem->GetTarget() << "\n";
}
/*
Ҫʹ��ջʵ�ֺ�ŵ�������۶���Բ�̣���ֻ��Ҫ�����Ϳ�����ɣ�����˳�������
��Ҫ��֤������ִ�еķ���ջ�������ִ�еķ���ջ��
�����ڰ�����ջ��ʱ�򣬾�Ҫ�����Ҫָ�����ǲ�����ջ������ִ�е��ǲ��������ջ
�����Ϳ����� ִ��ջ����
*/
void Hanoi(std::stack<CHanoiItem*>& hStack) {
	
	//����������
	while (!hStack.empty())
	{
		CHanoiItem* pTop = hStack.top();  //pTop ��ȡջ����Բ��
		hStack.pop();  //ջ�� ��ջ

		//���ֻ��һ��Բ��
		if (pTop->GetStation()==CHanoiItem::E||pTop->GetNumber()==1)
		{
			Print(pTop);  //��ӡջ��Ԫ��
			delete pTop;  //����ջ��Ԫ��
			continue;  //������һ��whileѭ��
		}

//����������ջ				��n-1 ��Բ�̴�sourceͨ��source�ƶ���target��
		// station : source : target
		CHanoiItem* pItem = new CHanoiItem(pTop->GetNumber() - 1, 
			pTop->GetStation(), pTop->GetSource(), pTop->GetTarget());
		hStack.push(pItem);   //��ջn-1

//һ��Բ��		�� 1 ��Բ�̴�source  �ƶ��� target��
		// Just one item											������E������ifҪ�жϵ�һ������
		pItem = new CHanoiItem(pTop->GetNumber(), pTop->GetSource(), CHanoiItem::E, pTop->GetTarget());
		hStack.push(pItem);   //��ջ1

//��һ�������ջ����ִ��		�� 1 ��Բ�̴�source  �ƶ��� target��
		// source : target : station
		pItem = new CHanoiItem(pTop->GetNumber() - 1, pTop->GetSource(), pTop->GetTarget(), pTop->GetStation());
		hStack.push(pItem);   //��ջn-1

		//ͨ�����������Ϳ���ʵ�� n ��Բ�̵ĺ�ŵ�����⣬��Ϊ��ջ�Ƚ���������ԣ�ֻ���� ����ִ�е� �����ջ

	}
}


int main() {
	std::stack<CHanoiItem*> hStack;
	CHanoiItem* pItem = new CHanoiItem(3, CHanoiItem::A, CHanoiItem::B, CHanoiItem::C);
	hStack.push(pItem);  //����ŵ���� ��ջ
	
	Hanoi(hStack);  //�൱�ڵݹ���õĺ���

	return 0;

}