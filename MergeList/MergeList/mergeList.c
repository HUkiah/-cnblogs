#include <stdio.h>
#include <malloc.h>

typedef int DataType;

typedef struct node
{
	DataType value;
    struct node *next;

}Node;

//创建一个链表
Node * createList() {
	Node *h,*s,*r;
	int x, tag;
	printf("结束构建链表的标识:");
	scanf("%d", &tag);

	h = (Node *)malloc(sizeof(Node));
	h->value = 0;
	r = h;
	printf("输入数据x:");
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

//创建一个固定测试链表
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
	//在链表的p节点之后，插入节点值为x的节点
	Node *s;
	s = (Node *)malloc(sizeof(Node));
	s->value = x;
	s->next = p->next;
	p->next = s;
}

void deleteList(Node *p) {
	//删除p节点的直接后继节点
	Node *q;
	if (p->next!=NULL)
	{
		q = p->next;
		p->next = q->next;
		free(q);
	}

}
Node *searchList(Node *h,DataType x) {
	//在头指针为h的链表中，查找节点x
	Node *p;
	p = h;
	while (p!=NULL&&p->value!=x)
	{
		p = p->next;
		
	}
	return p;
}

//打印出链表
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
	Node *head = NULL;//合并后的头指针  
	Node *p1 = pa->next;//p1用于扫描链表1 去除表头节点
	Node *p2 = pb->next;//p2用于扫描链表2  
	if (pa->next->value < pb->next->value)
	{
		head = pa;
	}
	else
	{
		head = pb;
	}
	Node *p = head;//p永远指向最新合并的结点  
	while (p1 && p2)//如果循环停止，则p1或p2至少有一个为NULL  
	{
		if (p1->value < p2->value)
		{
			p->next = p1;
			p1 = p1->next;
		}
		else
		{
			p->next = p2;
			//if (p1->value==p2->value)//去重
			//{
			//	p1 = p1->next;
			//}
			p2 = p2->next;
		}
		p = p->next;
	}
	if (p1)//如果链1还没走完  
	{
		p->next = p1;
	}
	else if (p2)//如果链2还没走完  
	{
		p->next = p2;
	}
	return head;
}

//采用递归的方法实现  
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

//三项合并@1
Node *ListMerge2(Node *pa, Node *pb ,Node *pc)
{
	if (!pa&&!pb&&!pc)//视链表为空的情况，为异常
		return NULL;

	Node *head = NULL;//合并后的头指针  
	Node *p1 = pa->next;//p1用于扫描链表1 去除表头节点
	Node *p2 = pb->next;//p2用于扫描链表2  
	Node *p3 = pc->next;//p3用于扫描链表3

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

	Node *p = head;//p永远指向最新合并的结点  
	while (p1 && p2 && p3)//如果循环停止，则p1或p2或p3至少有一个为NULL  
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
		else if (p3->value < p1->value && p3->value < p2->value)//至此筛选出最小值，如果不存在相等的情况时
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
	if (!p1)//如果链1走完  
	{
		while (p2 && p3)//如果循环停止，则p2或p3至少有一个为NULL  
		{
			if (p2->value < p3->value)
			{
				p->next = p2;
				p2 = p2->next;
			}
			else
			{
				p->next = p3;
				if (p2->value == p3->value)//去重
				{
					p2 = p2->next;
				}
				p3 = p3->next;
			}
			p = p->next;
		}
		if (p2)//如果链2还没走完  
		{
			p->next = p2;
		}
		else if (p3)//如果链3还没走完  
		{
			p->next = p3;
		}
	}
	else if (!p2)//如果链2走完  
	{
		while (p1 && p3)//如果循环停止，则p1或p3至少有一个为NULL  
		{
			if (p1->value < p3->value)
			{
				p->next = p1;
				p1 = p1->next;
			}
			else
			{
				p->next = p3;
				if (p1->value == p3->value)//去重
				{
					p1 = p1->next;
				}
				p3 = p3->next;
			}
			p = p->next;
		}
		if (p1)//如果链1还没走完  
		{
			p->next = p1;
		}
		else if (p3)//如果链3还没走完  
		{
			p->next = p3;
		}
	}
	else //链3走完
	{
		while (p1 && p2)//如果循环停止，则p1或p2至少有一个为NULL  
		{
			if (p1->value < p2->value)
			{
				p->next = p1;
				p1 = p1->next;
			}
			else
			{
				p->next = p2;
				if (p1->value == p2->value)//去重
				{
					p1 = p1->next;
				}
				p2 = p2->next;
			}
			p = p->next;
		}
		if (p1)//如果链1还没走完  
		{
			p->next = p1;
		}
		else if (p2)//如果链2还没走完  
		{
			p->next = p2;
		}
	}

	return head;
}

//三项合并@2
Node *ListMerge3(Node *pa, Node *pb, Node *pc)
{
	if (!pa && !pb && !pc)//视链表为空的情况，为异常
		return NULL;

	Node *head = NULL;//合并后的头指针  
	Node *p1 = pa->next;//p1用于扫描链表1 去除表头节点
	Node *p2 = pb->next;//p2用于扫描链表2  
	Node *p3 = pc->next;//p3用于扫描链表3

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

	Node *p = head;//p永远指向最新合并的结点  
	while (p1 && p2 && p3)//如果循环停止，则p1或p2或p3至少有一个为NULL  
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
				if (p1->value == p3->value)//去重
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
				if (p1->value == p2->value)//去重
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
				if (p2->value == p1->value)//去重
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
	if (!p1)//如果链1走完  
	{
		while (p2 && p3)//如果循环停止，则p2或p3至少有一个为NULL  
		{
			if (p2->value < p3->value)
			{
				p->next = p2;
				p2 = p2->next;
			}
			else
			{
				p->next = p3;
				if (p2->value == p3->value)//去重
				{
					p2 = p2->next;
				}
				p3 = p3->next;
			}
			p = p->next;
		}
		if (p2)//如果链2还没走完  
		{
			p->next = p2;
		}
		else if (p3)//如果链3还没走完  
		{
			p->next = p3;
		}
	}
	else if (!p2)//如果链2走完  
	{
		while (p1 && p3)//如果循环停止，则p1或p3至少有一个为NULL  
		{
			if (p1->value < p3->value)
			{
				p->next = p1;
				p1 = p1->next;
			}
			else
			{
				p->next = p3;
				if (p1->value == p3->value)//去重
				{
					p1 = p1->next;
				}
				p3 = p3->next;
			}
			p = p->next;
		}
		if (p1)//如果链1还没走完  
		{
			p->next = p1;
		}
		else if (p3)//如果链3还没走完  
		{
			p->next = p3;
		}
	}
	else //链3走完
	{
		while (p1 && p2)//如果循环停止，则p1或p2至少有一个为NULL  
		{
			if (p1->value < p2->value)
			{
				p->next = p1;
				p1 = p1->next;
			}
			else
			{
				p->next = p2;
				if (p1->value == p2->value)//去重
				{
					p1 = p1->next;
				}
				p2 = p2->next;
			}
			p = p->next;
		}
		if (p1)//如果链1还没走完  
		{
			p->next = p1;
		}
		else if (p2)//如果链2还没走完  
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

	//createList1构建的固定有序链表
	Node *part1 = createList1(2);
	Node *part2 = createList1(5);
	Node *part3 = createList1(8);

	printf("合并前:\n");
	printf("\n链表part1：");
	printList(part1);
	printf("\n链表part2：");
	printList(part2);
	printf("\n链表part3：");
	printList(part3);

	printf("\n合并后的链表：");
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