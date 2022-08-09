#include<stdio.h>
#include<stdlib.h>
//����ڵ�ṹ 
typedef struct LNode//���嵥����ڵ�����(�ڵ�) 
{
	int data;//ÿ�������һ������Ԫ��(������)
	struct LNode *next;//ָ��ָ����һ�����(ָ����) 
}
LNode,*LinkList;
//��ʼ��һ��������(��ͷ���) 
bool InitList(LinkList &L)
{
	L=(LNode*)malloc(sizeof(LNode));//����һ��ͷ��� 
	if(L==NULL)//�ڴ治�㣬����ʧ�� 
	{
		return false;
	}
	L->next=NULL;//ͷ���֮����ʱ��û�н��(��L���ָ��ָ��Ľ�㵱��next���ָ���򣬰�����ΪNULL) 
	return true;
}
//�жϵ������Ƿ�Ϊ�� 
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
//������Ľ��� 
LinkList List_TailInsert(LinkList &L)//������������ 
{
	int x;
	L=(LinkList)malloc(sizeof(LNode));//����ͷ���(��ʼ���ձ�) 
	LNode *s,*r=L;//rΪ��βָ��
	scanf("%d",&x);//�������ֵ 
	while(x!=9999)//����9999��ʾ���� 
	{
		s=(LNode*)malloc(sizeof(LNode));//����һ���½�㣬��sָ��ָ���� 
		s->data=x;//���½����ֵ��Ϊx 
		r->next=s;//��r����nextָ��ָ��s��� 
		r=s;//rָ���µı�β���(��Զ����ָ�����һ�����) 
		scanf("%d",&x);
	}
	r->next=NULL;//β���ָ���ÿ� 
	return L;
}
//��λ����� 
bool ListInsert(LinkList &L,int i,int e)//����������ڱ�L�еĵ�i��λ�ò���ָ��Ԫ��e 
{
	if(i<1)
	{
		return false;
	}
	LNode *p;//ָ��pָ��ǰɨ�赽�Ľ�� 
	int j=0;//��ǰpָ����ǵڼ������ 
	p=L;//Lָ��ͷ��㣬ͷ����ǵ�0�����(��������) 
	while(p!=NULL&&j<i-1)//ѭ���ҵ���i-1����� 
	{
		p=p->next;
		j++;
	}
	if(p==NULL)//�ڴ����ʧ��[ĳЩ������п��ܷ���ʧ��(���ڴ治��)]
	{ 
		return false;
	}
	LNode *s=(LNode*)malloc(sizeof(LNode));
	s->data=e;//�ý��s��������Ԫ��e[ʱ�临�Ӷ�=o(1)]
	s->next=p->next;
	p->next=s;//�����s����p֮�� 
	return true;
}
//�����ʹ�ӡ������ 
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
	LinkList L;//����һ��ָ�������ָ��(�˴�û�д���һ�����)
	InitList(L);//��ʼ��һ���ձ�
	Empty(L); 
	List_TailInsert(L);
	ListPrint(L);
	int a,b;
	printf("����������λ�ã�");
	scanf("%d",&a);
	printf("������������ֵ��");
	scanf("%d",&b);
	ListInsert(L,a,b);
	ListPrint(L);
}

int main()
{
	test();
	return 0;
}
