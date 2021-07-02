#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAXSIZE 10000

/* 定义链表结构 */
typedef struct Node {
	int data;
	struct Node* next;
}NodeList;

/* 输入超长整数，存入链表*/
NodeList* Input() {
	NodeList* s, * ps, * qs;
	struct number
	{
		int num;
		struct number* np;
	}* p, * q;

	int i, k;
	long sum;
	char c = '\0';
	p = NULL; // 指向输入的整数，链首为长整数的最低位，链尾位长整数的最高位

	while ((c = getchar()) != '\n') { // 输入整数，按字符接收数字
		if (c >= '0' && c <= '9') { // 若为数字则存入
			q = (struct number*)malloc(sizeof(struct number)); // 申请空间
			q->num = c - '0'; // 利用ASCII码差值存入一位整数
			q->np = p; // 建立指针
			p = q;
		}
	}

	s = (NodeList*)malloc(sizeof(NodeList));
	s->data = -1; // 建立链表存超长整数的头结点 -1
	ps = s;

	while (p != NULL) { // 将接收的临时数据链表中的数据转换为所要求的标准形式
		sum = 0;
		i = 0;
		k = 1;
		while (i < 4 && p != NULL) { // 取出低四位 
			sum = sum + k * (p->num);
			i++;
			p = p->np;
			k = k * 10;
		}

		qs = (NodeList*)malloc(sizeof(NodeList)); // 申请空间
		qs->data = sum; //赋值，建立链表
		ps->next = qs;
		ps = qs;
	}

	ps->next = s; // 指向头结点
	return s;
}

/* 在u结点后插入一个新的NodeList，其值为num */
NodeList* InsertAfter(NodeList* u, int num) {
	NodeList* v;
	v = (NodeList*)malloc(sizeof(NodeList));
	v->data = num;
	u->next = v; // 在u结点后插入一个NodeList 
	return v;
}

/* 完成加法操作后返回指向 *p + *q 结果的指针 */
NodeList* Add(NodeList* p, NodeList* q) {
	NodeList* pp, * qq, * r, * s, * t;
	int total, number;
	int carry = 0; // 进位

	pp = p->next;
	qq = q->next;
	s = (NodeList*)malloc(sizeof(NodeList)); // 建立存放和的链表的头节点
	s->data = -1;
	t = s;

	while (pp->data != -1 && qq->data != -1) { // 均不是表头
		total = pp->data + qq->data + carry; // 对应位与前一位的进位求和
		number = total % MAXSIZE; // 求出存入链表中部分的数值
		carry = total / MAXSIZE; // 求进位
		t = InsertAfter(t, number); // 将部分和存入s指向的链表中
		pp = pp->next; // 分别取后面的加数
		qq = qq->next;
	}

	r = (pp->data != -1) ? pp : qq; // 取尚未自理完毕的链指针

	while (r->data != -1) { // 处理加数中较大的数
		total = r->data + carry; // 与进位相加
		number = total % MAXSIZE; // 求出存入链表中部分的数值
		carry = total / MAXSIZE; // 算出进位
		t = InsertAfter(t, number); // 将部分和存入s
		r = r->next; // 移动指针
	}
	
	if (carry) {
		t = InsertAfter(t, 1); // 处理最后一次进位
	}

	t->next = s; // 指向头节点
	return s; // 返回指向和的结构指针
}

int Compare(NodeList* p, NodeList* q) {
	NodeList* pt, * qt;
	int i = 1;
	int j = 1;
	int k;

	pt = p->next;
	qt = q->next;

	while (pt->next->data != -1) { // 计算有多少个结点
		pt = pt->next;
		i++;
	}

	while (qt->next->data != -1) {
		qt = qt->next;
		j++;
	}

	if (i == j) { // 如果两个链表一样长
		while (pt->data != -1) {
			if (pt->data >= qt->data) {
				return 1;
			}
			else {
				return 0;
			}

			for (k = 0; k < i; k++) {
				pt = pt->next;
				qt = qt->next;
			}
			
		}
		return 1;
	}
	else if (i > j) {
		return 1;
	}
	else {
		return 0;
	}
}

/* 完成两个链表减法并返回指向|*p - *q|结果的指针 */
NodeList* Sub(NodeList* p, NodeList* q) {
	NodeList* pr, * qr, * s, * t;
	pr = (NodeList*)malloc(sizeof(NodeList));
	qr = (NodeList*)malloc(sizeof(NodeList));
	t = (NodeList*)malloc(sizeof(NodeList));
	int total = 0;
	int borrow = 0;

	if (Compare(p, q)) { // pr指向较大的数链，qr指向较小的数链
		pr = p->next;
		qr = q->next;
	}
	else {
		pr = q->next;
		qr = p->next;
	}

	s = (NodeList*)malloc(sizeof(NodeList));
	s->data = -1;
	t = s;
	
	while (qr->data != -1) {
		total = pr->data - qr->data - borrow;
		if (total < 0) { // 如果有借位
			total = MAXSIZE + pr->data - qr->data - borrow;
			borrow = 1;
		}
		else {
			borrow = 0;
		}

		if (pr->next->data != -1) {
			t = InsertAfter(t, total);
		}
		else {
			if (total != 0) {
				t = InsertAfter(t, total); // 最高位为0时不存入求差链中
			}
		}

		pr = pr->next;
		qr = qr->next;
	}

	while (pr->data != -1) { // 处理余下结点
		total = pr->data - borrow;
		if (total < 0) {
			total = MAXSIZE + pr->data - borrow;
			borrow = 1;
		}
		else {
			borrow = 0;
		}

		if (pr->next->data != -1) {
			t = InsertAfter(t, total);
		}
		else if (total != 0) {
			t = InsertAfter(t, total);
		}
		pr = pr->next;
	}
	t->next = s;

	if (s->next->data == -1) { // 处理位数小于等于4且相减结果为0的情况
		t = InsertAfter(t, total);
		t->next = s;
	}
	return s;
}

void Print(NodeList* s) {
	if (s->next->data != -1) { // 若不是头节点，则输出
		Print(s->next); // 递归输出

		if (s->next->next->data == -1) {
			printf("%d", s->next->data); // 打印最高位
		}
		else {
			int i;
			int k = MAXSIZE;

			for (i = 1; i <= 4; i++, k /= 10) { // 按字符输出不足4位补0
				putchar('0' + (s->next->data) % (k) / (k / 10));
			}
		}
	}
}

int main() {
	NodeList* s1, * s2, * s, * g;
	int f;
	char c;
	NodeList* Input(), * Add(), * InsetAfter(), * Sub();

	char y = '\0';
	printf("======大数相加减!======\n");
	printf("=====按下回车开始!=====\n");

	while (c = getchar() == '\n')
	{
		printf("请输入 S1 = ");
		s1 = Input();
		printf("请输入 S2 = ");
		s2 = Input();

		printf("S1 = ");
		Print(s1);
		putchar('\n');

		printf("S2 = ");
		Print(s2);
		putchar('\n');

		printf("请选择进行加运算还是减运算?\n 1：+	\t 2：-\n");
		int x = 0;
		scanf("%d", &x);
		if (x == 1) {
			s = Add(s1, s2); // 求和
			printf("S1 + S2 =");
			Print(s);
			putchar('\n');
			printf("链表头节点存放的为 %d\n", s->data);
		}
		else if (x == 2) {
			f = Compare(s1, s2);
			g = Sub(s1, s2);
			printf("S1 - S2 = ");
			if (!f) { // 判断符号
				printf("-");
			}
			Print(g);
			putchar('\n');
			printf("链表头节点存放的为 %d\n", s->data);
		}

		
		printf("Enter key to continue or \\0 to Exit: \n");
		if (getchar() == "\0") {
			return 0;
		}
	}
}