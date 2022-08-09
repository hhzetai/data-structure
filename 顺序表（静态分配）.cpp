#include<stdio.h>
#define Maxsize 10 //������󳤶� 
//����˳��� 
typedef struct
{
	int data[Maxsize];//�þ�̬��"����"�������Ԫ�� 
	int length;//˳���ĵ�ǰ���� 
}
SqList;//˳�������Ͷ��� 
//��ʼ��˳��� 
void InitList(SqList &L)
{
	for(int i=0;i<Maxsize;i++)
	{
		L.data[i]=0;//����������Ԫ������ΪĬ�ϳ�ʼֵ 
	}
	L.length=0;//˳���ĳ�ʼ����Ϊ0 
}
//����˳���
void List_Insert(SqList &L,int i,int e)
{
	L.data[i]=e;
	L.length++;
}
//�������(�ڱ�L�ĵ�i��λ���ϲ���ָ��Ԫ��e) 
bool ListInsert(SqList &L,int i,int e)
{
	if(i<1||i>L.length+1)//�ж�i�ķ�Χ�Ƿ���Ч 
	{
		return false;
	}
	if(L.length>=Maxsize)//�жϴ洢�ռ��Ƿ��������ܷ���� 
	{
		return false;
	}
	for(int j=L.length;j>=i;j--)//����i��Ԫ�ؼ�֮���Ԫ�غ��� 
	{
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;//��λ��i������e 
	L.length++;//���ȼ�1 
	return true;
}
//ɾ������(ɾ����L�е�i��λ�õ�Ԫ�أ�����e����ɾ��Ԫ�ص�ֵ) 
bool ListDelete(SqList &L,int i)
{
	if(i<1||i>L.length)//�ж�i�ķ�Χ�Ƿ���Ч 
	{
		return false;
	} 
	for(int j=i;j<=L.length;j++)//����i��Ԫ�ؼ�֮���Ԫ��ǰ��
	{
		L.data[j-1]=L.data[j];
	} 
	L.length--;//���ȼ�1
	return true;
}
//���ݵ����뼰��� 
int main()
{
	SqList L;//����һ��˳��� 
	InitList(L);//��ʼ��˳���
	for(int i=0;i<Maxsize;i++)//����˳��� 
	{
		int e;
		printf("������e:");
		scanf("%d",&e);
		List_Insert(L,i,e);
	}
	for(int i=0;i<Maxsize;i++)
	{
		printf("%d ",L.data[i]);
	}
	printf("\n");
	int c;
	printf("ɾ����λ��:");
	scanf("%d",&c);
	ListDelete(L,c);//ɾ������ 
	for(int i=0;i<Maxsize-1;i++)
	{
		printf("%d ",L.data[i]);
	}
	printf("\n");
	int a,b;
	printf("�����λ��:");
	scanf("%d",&a);
	printf("�������ֵ:");
	scanf("%d",&b);
	ListInsert(L,a,b);//�������� 	
	for(int i=0;i<Maxsize;i++)
	{
		printf("%d ",L.data[i]);
	}
	return 0;
}
