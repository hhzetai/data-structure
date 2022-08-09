#include<stdio.h>
#define MaxSize 10 //���������Ԫ�ص����ֵ 
typedef struct
{
	int data[MaxSize];//�þ�̬�����Ŷ���Ԫ�� 
	int front,rear;//��ͷָ��Ͷ�βָ��
	int size;//���е�ǰ���� 
}
SqQueue;
//��ʼ������ 
void InitQueue(SqQueue &Q)//��ʼ������ 
{
	Q.rear=Q.front=0;//��ʼʱ����ͷ����βָ��ָ��0
	Q.size=0; 
}
//�п�
bool QueueEmpty(SqQueue &Q)//�п� 
{
	if(Q.size==0)//�ӿ����� 
	{
		return true;
	}
	else
	{
		return false;
	}
}
//��Ӳ���(ֻ�ܴӶ�β���) 
bool EnQueue(SqQueue &Q,int x)
{
	if(Q.size==MaxSize)
	{
		return false;//�����򱨴� 
	}
	Q.data[Q.rear]=x;//��x�����β 
	Q.rear=(Q.rear+1)%MaxSize;//��βָ�����(��βָ���1ȡ��)
	Q.size++;
	return true;
}
//���Ӳ���(ֻ���ö�ͷԪ�س���)
bool Dequeue(SqQueue &Q,int &x)
{
	if(Q.size==0)//�ж϶ӿ� 
	{
		return false;//�ӿ��򱨴� 
	}
	x=Q.data[Q.front];
	Q.front=(Q.rear+1)%MaxSize;//��ͷָ����� 
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
