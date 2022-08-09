#include<stdio.h>
#define Maxsize 10 //定义最大长度 
//定义顺序表 
typedef struct
{
	int data[Maxsize];//用静态的"数组"存放数据元素 
	int length;//顺序表的当前长度 
}
SqList;//顺序表的类型定义 
//初始化顺序表 
void InitList(SqList &L)
{
	for(int i=0;i<Maxsize;i++)
	{
		L.data[i]=0;//将所有数据元素设置为默认初始值 
	}
	L.length=0;//顺序表的初始长度为0 
}
//建立顺序表
void List_Insert(SqList &L,int i,int e)
{
	L.data[i]=e;
	L.length++;
}
//插入操作(在表L的第i个位置上插入指定元素e) 
bool ListInsert(SqList &L,int i,int e)
{
	if(i<1||i>L.length+1)//判断i的范围是否有效 
	{
		return false;
	}
	if(L.length>=Maxsize)//判断存储空间是否已满，能否插入 
	{
		return false;
	}
	for(int j=L.length;j>=i;j--)//将第i个元素及之后的元素后移 
	{
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;//在位置i处放入e 
	L.length++;//长度加1 
	return true;
}
//删除操作(删除表L中第i个位置的元素，并用e返回删除元素的值) 
bool ListDelete(SqList &L,int i)
{
	if(i<1||i>L.length)//判断i的范围是否有效 
	{
		return false;
	} 
	for(int j=i;j<=L.length;j++)//将第i个元素及之后的元素前提
	{
		L.data[j-1]=L.data[j];
	} 
	L.length--;//长度减1
	return true;
}
//数据的输入及输出 
int main()
{
	SqList L;//声明一个顺序表 
	InitList(L);//初始化顺序表
	for(int i=0;i<Maxsize;i++)//建立顺序表 
	{
		int e;
		printf("请输入e:");
		scanf("%d",&e);
		List_Insert(L,i,e);
	}
	for(int i=0;i<Maxsize;i++)
	{
		printf("%d ",L.data[i]);
	}
	printf("\n");
	int c;
	printf("删除的位置:");
	scanf("%d",&c);
	ListDelete(L,c);//删除数据 
	for(int i=0;i<Maxsize-1;i++)
	{
		printf("%d ",L.data[i]);
	}
	printf("\n");
	int a,b;
	printf("插入的位置:");
	scanf("%d",&a);
	printf("插入的数值:");
	scanf("%d",&b);
	ListInsert(L,a,b);//插入数据 	
	for(int i=0;i<Maxsize;i++)
	{
		printf("%d ",L.data[i]);
	}
	return 0;
}
