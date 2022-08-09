#include<stdio.h>
#include<stdlib.h>
//定义节点结构 
typedef struct LNode//定义单链表节点类型(节点) 
{
	int data;//每个结点存放一个数据元素(数据域)
	struct LNode *next;//指针指向下一个结点(指针域) 
}
LNode,*LinkList;
//初始化一个单链表(带头结点) 
bool InitList(LinkList &L)
{
	L=(LNode*)malloc(sizeof(LNode));//分配一个头结点 
	if(L==NULL)//内存不足，分配失败 
	{
		return false;
	}
	L->next=NULL;//头结点之后暂时还没有结点(把L这个指针指向的结点当中next这个指针域，把他设为NULL) 
	return true;
}
//判断单链表是否为空 
bool Empty(LinkList L)
{
	if(L->next==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
} 
//单链表的建立 
LinkList List_TailInsert(LinkList &L)//正向建立单链表 
{
	int x;
	L=(LinkList)malloc(sizeof(LNode));//建立头结点(初始化空表) 
	LNode *s,*r=L;//r为表尾指针
	scanf("%d",&x);//输入结点的值 
	while(x!=9999)//输入9999表示结束 
	{
		s=(LNode*)malloc(sizeof(LNode));//申请一个新结点，把s指针指向它 
		s->data=x;//把新结点数值设为x 
		r->next=s;//把r结点的next指针指向s结点 
		r=s;//r指向新的表尾结点(永远保持指向最后一个结点) 
		scanf("%d",&x);
	}
	r->next=NULL;//尾结点指针置空 
	return L;
}
//按位序插入 
bool ListInsert(LinkList &L,int i,int e)//插入操作，在表L中的第i个位置插入指定元素e 
{
	if(i<1)
	{
		return false;
	}
	LNode *p;//指针p指向当前扫描到的结点 
	int j=0;//当前p指向的是第几个结点 
	p=L;//L指向头结点，头结点是第0个结点(不存数据) 
	while(p!=NULL&&j<i-1)//循环找到第i-1个结点 
	{
		p=p->next;
		j++;
	}
	if(p==NULL)//内存分配失败[某些情况下有可能分配失败(如内存不足)]
	{ 
		return false;
	}
	LNode *s=(LNode*)malloc(sizeof(LNode));
	s->data=e;//用结点s保存数据元素e[时间复杂度=o(1)]
	s->next=p->next;
	p->next=s;//将结点s连到p之后 
	return true;
}
//遍历和打印单链表 
void ListPrint(LinkList &L)
{
	LNode*p=L;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void test()
{
	LinkList L;//声明一个指向单链表的指针(此处没有创建一个结点)
	InitList(L);//初始化一个空表
	Empty(L); 
	List_TailInsert(L);
	ListPrint(L);
	int a,b;
	printf("请输入插入的位置：");
	scanf("%d",&a);
	printf("请输入插入的数值：");
	scanf("%d",&b);
	ListInsert(L,a,b);
	ListPrint(L);
}

int main()
{
	test();
	return 0;
}
