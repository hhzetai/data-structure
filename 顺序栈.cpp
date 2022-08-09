#include<stdio.h>
#define MaxSize 10//定义栈中元素的最大个数 
//顺序栈的定义 
typedef struct
{
	int data[MaxSize];//静态数组存放栈中元素 
	int top;//栈顶指针 
}
SqStack;//Sq:sequence-顺序 
//初始化操作 
void InitStack(SqStack &S)//初始化栈 
{
	S.top=-1;//初始化栈顶操作 
}
//进栈操作 
bool Push(SqStack &S,int x)//新元素入栈 
{
	if(S.top==MaxSize-1)//栈满，报错 
	{
		return false;
	}
	S.top=S.top+1;//指针先加1 
	S.data[S.top]=x;//新元素入栈
	return false;
}
//出栈操作 
bool Pop(SqStack &S)
{
	if(S.top==-1)//栈空、报错 
	{
		return false;
	}
	S.top=S.top-1;//栈顶元素先出栈 
	return true;//指针减1 
}

int main()
{
	SqStack S;//声明一个顺序栈(分配空间) 
	InitStack(S);
	int x; 
	for(int i=0;i<MaxSize;i++)
	{
		printf("输入进栈的数值："); 
		scanf("%d",&x);
		Push(S,x);
	}
	for(int i=0;i<MaxSize;i++)
	{
		printf("%d ",S.data[i]);
	}
	printf("\n");
	int n;
	printf("输入出栈的个数："); 
	scanf("%d",&n);
	printf("\n");
	for(int i=0;i<n;i++)
	{
		Pop(S);
	}
	for(int i=0;i<MaxSize-n;i++)
	{
		printf("%d ",S.data[i]);
	}
	return 0;
}
