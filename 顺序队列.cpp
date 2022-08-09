#include<stdio.h>
#define MaxSize 10 //定义队列中元素的最大值 
typedef struct
{
	int data[MaxSize];//用静态数组存放队列元素 
	int front,rear;//队头指针和队尾指针
	int size;//队列当前长度 
}
SqQueue;
//初始化操作 
void InitQueue(SqQueue &Q)//初始化队列 
{
	Q.rear=Q.front=0;//初始时，队头、队尾指针指向0
	Q.size=0; 
}
//判空
bool QueueEmpty(SqQueue &Q)//判空 
{
	if(Q.size==0)//队空条件 
	{
		return true;
	}
	else
	{
		return false;
	}
}
//入队操作(只能从队尾入队) 
bool EnQueue(SqQueue &Q,int x)
{
	if(Q.size==MaxSize)
	{
		return false;//队满则报错 
	}
	Q.data[Q.rear]=x;//将x插入队尾 
	Q.rear=(Q.rear+1)%MaxSize;//队尾指针后移(队尾指针加1取余)
	Q.size++;
	return true;
}
//出队操作(只能让队头元素出队)
bool Dequeue(SqQueue &Q,int &x)
{
	if(Q.size==0)//判断队空 
	{
		return false;//队空则报错 
	}
	x=Q.data[Q.front];
	Q.front=(Q.rear+1)%MaxSize;//队头指针后移 
	Q.size--;
	return true;
}
int main()
{
	SqQueue Q;
	InitQueue(Q);
	QueueEmpty(Q);
	for(int i=0;i<MaxSize;i++)
	{
		EnQueue(Q,i+1);
		printf("%d ",Q.data[i]);
	}
	printf("\n%d\n",Q.rear);
	int t1,t2;
	Dequeue(Q,t1);
	Dequeue(Q,t2);
	printf("%d %d %d",t1,t2,Q.size);
	return 0;
} 
