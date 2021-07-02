#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAXSIZE 10000

/* ��������ṹ */
typedef struct Node {
	int data;
	struct Node* next;
}NodeList;

/* ���볬����������������*/
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
	p = NULL; // ָ�����������������Ϊ�����������λ����βλ�����������λ

	while ((c = getchar()) != '\n') { // �������������ַ���������
		if (c >= '0' && c <= '9') { // ��Ϊ���������
			q = (struct number*)malloc(sizeof(struct number)); // ����ռ�
			q->num = c - '0'; // ����ASCII���ֵ����һλ����
			q->np = p; // ����ָ��
			p = q;
		}
	}

	s = (NodeList*)malloc(sizeof(NodeList));
	s->data = -1; // ��������泬��������ͷ��� -1
	ps = s;

	while (p != NULL) { // �����յ���ʱ���������е�����ת��Ϊ��Ҫ��ı�׼��ʽ
		sum = 0;
		i = 0;
		k = 1;
		while (i < 4 && p != NULL) { // ȡ������λ 
			sum = sum + k * (p->num);
			i++;
			p = p->np;
			k = k * 10;
		}

		qs = (NodeList*)malloc(sizeof(NodeList)); // ����ռ�
		qs->data = sum; //��ֵ����������
		ps->next = qs;
		ps = qs;
	}

	ps->next = s; // ָ��ͷ���
	return s;
}

/* ��u�������һ���µ�NodeList����ֵΪnum */
NodeList* InsertAfter(NodeList* u, int num) {
	NodeList* v;
	v = (NodeList*)malloc(sizeof(NodeList));
	v->data = num;
	u->next = v; // ��u�������һ��NodeList 
	return v;
}

/* ��ɼӷ������󷵻�ָ�� *p + *q �����ָ�� */
NodeList* Add(NodeList* p, NodeList* q) {
	NodeList* pp, * qq, * r, * s, * t;
	int total, number;
	int carry = 0; // ��λ

	pp = p->next;
	qq = q->next;
	s = (NodeList*)malloc(sizeof(NodeList)); // ������ź͵������ͷ�ڵ�
	s->data = -1;
	t = s;

	while (pp->data != -1 && qq->data != -1) { // �����Ǳ�ͷ
		total = pp->data + qq->data + carry; // ��Ӧλ��ǰһλ�Ľ�λ���
		number = total % MAXSIZE; // ������������в��ֵ���ֵ
		carry = total / MAXSIZE; // ���λ
		t = InsertAfter(t, number); // �����ֺʹ���sָ���������
		pp = pp->next; // �ֱ�ȡ����ļ���
		qq = qq->next;
	}

	r = (pp->data != -1) ? pp : qq; // ȡ��δ������ϵ���ָ��

	while (r->data != -1) { // ��������нϴ����
		total = r->data + carry; // ���λ���
		number = total % MAXSIZE; // ������������в��ֵ���ֵ
		carry = total / MAXSIZE; // �����λ
		t = InsertAfter(t, number); // �����ֺʹ���s
		r = r->next; // �ƶ�ָ��
	}
	
	if (carry) {
		t = InsertAfter(t, 1); // �������һ�ν�λ
	}

	t->next = s; // ָ��ͷ�ڵ�
	return s; // ����ָ��͵Ľṹָ��
}

int Compare(NodeList* p, NodeList* q) {
	NodeList* pt, * qt;
	int i = 1;
	int j = 1;
	int k;

	pt = p->next;
	qt = q->next;

	while (pt->next->data != -1) { // �����ж��ٸ����
		pt = pt->next;
		i++;
	}

	while (qt->next->data != -1) {
		qt = qt->next;
		j++;
	}

	if (i == j) { // �����������һ����
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

/* ��������������������ָ��|*p - *q|�����ָ�� */
NodeList* Sub(NodeList* p, NodeList* q) {
	NodeList* pr, * qr, * s, * t;
	pr = (NodeList*)malloc(sizeof(NodeList));
	qr = (NodeList*)malloc(sizeof(NodeList));
	t = (NodeList*)malloc(sizeof(NodeList));
	int total = 0;
	int borrow = 0;

	if (Compare(p, q)) { // prָ��ϴ��������qrָ���С������
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
		if (total < 0) { // ����н�λ
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
				t = InsertAfter(t, total); // ���λΪ0ʱ�������������
			}
		}

		pr = pr->next;
		qr = qr->next;
	}

	while (pr->data != -1) { // �������½��
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

	if (s->next->data == -1) { // ����λ��С�ڵ���4��������Ϊ0�����
		t = InsertAfter(t, total);
		t->next = s;
	}
	return s;
}

void Print(NodeList* s) {
	if (s->next->data != -1) { // ������ͷ�ڵ㣬�����
		Print(s->next); // �ݹ����

		if (s->next->next->data == -1) {
			printf("%d", s->next->data); // ��ӡ���λ
		}
		else {
			int i;
			int k = MAXSIZE;

			for (i = 1; i <= 4; i++, k /= 10) { // ���ַ��������4λ��0
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
	printf("======������Ӽ�!======\n");
	printf("=====���»س���ʼ!=====\n");

	while (c = getchar() == '\n')
	{
		printf("������ S1 = ");
		s1 = Input();
		printf("������ S2 = ");
		s2 = Input();

		printf("S1 = ");
		Print(s1);
		putchar('\n');

		printf("S2 = ");
		Print(s2);
		putchar('\n');

		printf("��ѡ����м����㻹�Ǽ�����?\n 1��+	\t 2��-\n");
		int x = 0;
		scanf("%d", &x);
		if (x == 1) {
			s = Add(s1, s2); // ���
			printf("S1 + S2 =");
			Print(s);
			putchar('\n');
			printf("����ͷ�ڵ��ŵ�Ϊ %d\n", s->data);
		}
		else if (x == 2) {
			f = Compare(s1, s2);
			g = Sub(s1, s2);
			printf("S1 - S2 = ");
			if (!f) { // �жϷ���
				printf("-");
			}
			Print(g);
			putchar('\n');
			printf("����ͷ�ڵ��ŵ�Ϊ %d\n", s->data);
		}

		
		printf("Enter key to continue or \\0 to Exit: \n");
		if (getchar() == "\0") {
			return 0;
		}
	}
}