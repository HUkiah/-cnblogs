#include <stdio.h>
#include <malloc.h>

typedef int DataType;

typedef struct node
{
	DataType value;
    struct node *next;

}Node;

//����һ������
Node * createList() {
	Node *h,*s,*r;
	int x, tag;
	printf("������������ı�ʶ:");
	scanf("%d", &tag);

	h = (Node *)malloc(sizeof(Node));
	h->value = 0;
	r = h;
	printf("��������x:");
	scanf("%d", &x);
	while (x!=tag)
	{
		s = (Node *)malloc(sizeof(Node));
		s->value = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;

	return h;
}

//����һ���̶���������
Node * createList1(int n) {
	Node *h, *s, *r;

	h = (Node *)malloc(sizeof(Node));
	h->value = 0;
	r = h;

	int tag = 0;
	while (++tag!=5)
	{
		s = (Node *)malloc(sizeof(Node));
		s->value = n+tag;
		r->next = s;
		r = s;
	}
	r->next = NULL;

	return h;
}

void insertList(Node *p, DataType x) {
	//�������p�ڵ�֮�󣬲���ڵ�ֵΪx�Ľڵ�
	Node *s;
	s = (Node *)malloc(sizeof(Node));
	s->value = x;
	s->next = p->next;
	p->next = s;
}

void deleteList(Node *p) {
	//ɾ��p�ڵ��ֱ�Ӻ�̽ڵ�
	Node *q;
	if (p->next!=NULL)
	{
		q = p->next;
		p->next = q->next;
		free(q);
	}

}
Node *searchList(Node *h,DataType x) {
	//��ͷָ��Ϊh�������У����ҽڵ�x
	Node *p;
	p = h;
	while (p!=NULL&&p->value!=x)
	{
		p = p->next;
		
	}
	return p;
}

//��ӡ������
void printList(Node *h) {
	if (h) {
		printf("%d->", h->value);
		printList(h->next);
	}
	else {
		printf("null\n");
	}
}


Node *ListMerge(Node *pa, Node *pb)
{
	if (!pa) return pb;
	if (!pb) return pa;
	Node *head = NULL;//�ϲ����ͷָ��  
	Node *p1 = pa->next;//p1����ɨ������1 ȥ����ͷ�ڵ�
	Node *p2 = pb->next;//p2����ɨ������2  
	if (pa->next->value < pb->next->value)
	{
		head = pa;
	}
	else
	{
		head = pb;
	}
	Node *p = head;//p��Զָ�����ºϲ��Ľ��  
	while (p1 && p2)//���ѭ��ֹͣ����p1��p2������һ��ΪNULL  
	{
		if (p1->value < p2->value)
		{
			p->next = p1;
			p1 = p1->next;
		}
		else
		{
			p->next = p2;
			//if (p1->value==p2->value)//ȥ��
			//{
			//	p1 = p1->next;
			//}
			p2 = p2->next;
		}
		p = p->next;
	}
	if (p1)//�����1��û����  
	{
		p->next = p1;
	}
	else if (p2)//�����2��û����  
	{
		p->next = p2;
	}
	return head;
}

//���õݹ�ķ���ʵ��  
Node *ListMerge1(Node *pa, Node *pb)
{
	if (pa == NULL)
		return pb;
	if (pb == NULL)
		return pa;
	Node *head = NULL;
	if (pa->value < pb->value)
	{
		head = pa;
		head->next = ListMerge1(pa->next, pb);
	}
	else
	{
		head = pb;
		if (pa->value == pb->value)
			head->next = ListMerge1(pa, pb->next);
	}
	return head;
}

//����ϲ�@1
Node *ListMerge2(Node *pa, Node *pb ,Node *pc)
{
	if (!pa&&!pb&&!pc)//������Ϊ�յ������Ϊ�쳣
		return NULL;

	Node *head = NULL;//�ϲ����ͷָ��  
	Node *p1 = pa->next;//p1����ɨ������1 ȥ����ͷ�ڵ�
	Node *p2 = pb->next;//p2����ɨ������2  
	Node *p3 = pc->next;//p3����ɨ������3

	if (pa->next->value < pb->next->value&&pa->next->value < pc->next->value)
	{
		head = pa;
	}
	else if (pb->next->value < pa->next->value&&pb->next->value < pc->next->value)
	{
		head = pb;
	}
	else
	{
		head = pc;
	}

	Node *p = head;//p��Զָ�����ºϲ��Ľ��  
	while (p1 && p2 && p3)//���ѭ��ֹͣ����p1��p2��p3������һ��ΪNULL  
	{
		if (p1->value < p2->value && p1->value < p3->value)
		{
			p->next = p1;
			p1 = p1->next;
		}
		else if (p2->value < p1->value && p2->value < p3->value)
		{
			p->next = p2;
			p2 = p2->next;
		}
		else if (p3->value < p1->value && p3->value < p2->value)//����ɸѡ����Сֵ�������������ȵ����ʱ
		{
			p->next = p3;
			p3 = p3->next;
		}
		else if (p1->value == p2->value && p1->value == p3->value)// p1=p2=p3
		{
			p->next = p1;
			p1 = p1->next;
			p2 = p2->next;
			p3 = p3->next;
		}
		else if (p1->value < p3->value && p1->value == p2->value)// (p1=p2)<p3
		{
			p->next = p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->value < p2->value && p1->value == p3->value)// (p1=p3)<p2
		{
			p->next = p1;
			p1 = p1->next;
			p3 = p3->next;
		}
		else if (p2->value < p1->value && p2->value == p3->value)// (p2=p3)<p1
		{
			p->next = p2;
			p2 = p2->next;
			p3 = p3->next;
		}
		p = p->next;
	}
	if (!p1)//�����1����  
	{
		while (p2 && p3)//���ѭ��ֹͣ����p2��p3������һ��ΪNULL  
		{
			if (p2->value < p3->value)
			{
				p->next = p2;
				p2 = p2->next;
			}
			else
			{
				p->next = p3;
				if (p2->value == p3->value)//ȥ��
				{
					p2 = p2->next;
				}
				p3 = p3->next;
			}
			p = p->next;
		}
		if (p2)//�����2��û����  
		{
			p->next = p2;
		}
		else if (p3)//�����3��û����  
		{
			p->next = p3;
		}
	}
	else if (!p2)//�����2����  
	{
		while (p1 && p3)//���ѭ��ֹͣ����p1��p3������һ��ΪNULL  
		{
			if (p1->value < p3->value)
			{
				p->next = p1;
				p1 = p1->next;
			}
			else
			{
				p->next = p3;
				if (p1->value == p3->value)//ȥ��
				{
					p1 = p1->next;
				}
				p3 = p3->next;
			}
			p = p->next;
		}
		if (p1)//�����1��û����  
		{
			p->next = p1;
		}
		else if (p3)//�����3��û����  
		{
			p->next = p3;
		}
	}
	else //��3����
	{
		while (p1 && p2)//���ѭ��ֹͣ����p1��p2������һ��ΪNULL  
		{
			if (p1->value < p2->value)
			{
				p->next = p1;
				p1 = p1->next;
			}
			else
			{
				p->next = p2;
				if (p1->value == p2->value)//ȥ��
				{
					p1 = p1->next;
				}
				p2 = p2->next;
			}
			p = p->next;
		}
		if (p1)//�����1��û����  
		{
			p->next = p1;
		}
		else if (p2)//�����2��û����  
		{
			p->next = p2;
		}
	}

	return head;
}

//����ϲ�@2
Node *ListMerge3(Node *pa, Node *pb, Node *pc)
{
	if (!pa && !pb && !pc)//������Ϊ�յ������Ϊ�쳣
		return NULL;

	Node *head = NULL;//�ϲ����ͷָ��  
	Node *p1 = pa->next;//p1����ɨ������1 ȥ����ͷ�ڵ�
	Node *p2 = pb->next;//p2����ɨ������2  
	Node *p3 = pc->next;//p3����ɨ������3

	if (pa->next->value < pb->next->value&&pa->next->value < pc->next->value)
	{
		head = pa;
	}
	else if (pb->next->value < pa->next->value&&pb->next->value < pc->next->value)
	{
		head = pb;
	}
	else
	{
		head = pc;
	}

	Node *p = head;//p��Զָ�����ºϲ��Ľ��  
	while (p1 && p2 && p3)//���ѭ��ֹͣ����p1��p2��p3������һ��ΪNULL  
	{
		if (p1->value < p2->value )
		{
			if (p1->value < p3->value)
			{
				p->next = p1;
				p1 = p1->next;
			}
			else
			{
				p->next = p3;
				if (p1->value == p3->value)//ȥ��
				{
					p1 = p1->next;
				}
				p3 = p3->next;
			}
		}
		else if(p1->value < p3->value)
		{
			if (p1->value < p2->value)
			{
				p->next = p1;
				p1 = p1->next;
			}
			else
			{
				p->next = p2;
				if (p1->value == p2->value)//ȥ��
				{
					p1 = p1->next;
				}
				p2 = p2->next;
			}
		}
		else if (p2->value < p3->value)
		{
			if (p2->value < p1->value)
			{
				p->next = p2;
				p2 = p2->next;
			}
			else
			{
				p->next = p1;
				if (p2->value == p1->value)//ȥ��
				{
					p2 = p2->next;
				}
				p1 = p1->next;
			}
		}
		else if (p1->value == p2->value && p1->value == p3->value)// p1=p2=p3
		{
			p->next = p1;
			p1 = p1->next;
			p2 = p2->next;
			p3 = p3->next;
		}
		p = p->next;
	}
	if (!p1)//�����1����  
	{
		while (p2 && p3)//���ѭ��ֹͣ����p2��p3������һ��ΪNULL  
		{
			if (p2->value < p3->value)
			{
				p->next = p2;
				p2 = p2->next;
			}
			else
			{
				p->next = p3;
				if (p2->value == p3->value)//ȥ��
				{
					p2 = p2->next;
				}
				p3 = p3->next;
			}
			p = p->next;
		}
		if (p2)//�����2��û����  
		{
			p->next = p2;
		}
		else if (p3)//�����3��û����  
		{
			p->next = p3;
		}
	}
	else if (!p2)//�����2����  
	{
		while (p1 && p3)//���ѭ��ֹͣ����p1��p3������һ��ΪNULL  
		{
			if (p1->value < p3->value)
			{
				p->next = p1;
				p1 = p1->next;
			}
			else
			{
				p->next = p3;
				if (p1->value == p3->value)//ȥ��
				{
					p1 = p1->next;
				}
				p3 = p3->next;
			}
			p = p->next;
		}
		if (p1)//�����1��û����  
		{
			p->next = p1;
		}
		else if (p3)//�����3��û����  
		{
			p->next = p3;
		}
	}
	else //��3����
	{
		while (p1 && p2)//���ѭ��ֹͣ����p1��p2������һ��ΪNULL  
		{
			if (p1->value < p2->value)
			{
				p->next = p1;
				p1 = p1->next;
			}
			else
			{
				p->next = p2;
				if (p1->value == p2->value)//ȥ��
				{
					p1 = p1->next;
				}
				p2 = p2->next;
			}
			p = p->next;
		}
		if (p1)//�����1��û����  
		{
			p->next = p1;
		}
		else if (p2)//�����2��û����  
		{
			p->next = p2;
		}
	}

	return head;
}


void freeList(Node *head) {
	if (head == NULL)
	{
		return;
	}
	else
	{
		Node *temp = head->next;
		free(head);
		head = temp;
		freeList(head);
	}
}

int main() {

	//createList1�����Ĺ̶���������
	Node *part1 = createList1(2);
	Node *part2 = createList1(5);
	Node *part3 = createList1(8);

	printf("�ϲ�ǰ:\n");
	printf("\n����part1��");
	printList(part1);
	printf("\n����part2��");
	printList(part2);
	printf("\n����part3��");
	printList(part3);

	printf("\n�ϲ��������");
	Node *head = ListMerge(part1, part2);

	head = ListMerge(head, part3);

	Node *p = head;
	head = p->next;
	free(p);

	printList(head);

	freeList(head);

	system("pause");
	return 0;
}