#include<stdio.h>
#define MaxSize 10//����ջ��Ԫ�ص������� 
//˳��ջ�Ķ��� 
typedef struct
{
	int data[MaxSize];//��̬������ջ��Ԫ�� 
	int top;//ջ��ָ�� 
}
SqStack;//Sq:sequence-˳�� 
//��ʼ������ 
void InitStack(SqStack &S)//��ʼ��ջ 
{
	S.top=-1;//��ʼ��ջ������ 
}
//��ջ���� 
bool Push(SqStack &S,int x)//��Ԫ����ջ 
{
	if(S.top==MaxSize-1)//ջ�������� 
	{
		return false;
	}
	S.top=S.top+1;//ָ���ȼ�1 
	S.data[S.top]=x;//��Ԫ����ջ
	return false;
}
//��ջ���� 
bool Pop(SqStack &S)
{
	if(S.top==-1)//ջ�ա����� 
	{
		return false;
	}
	S.top=S.top-1;//ջ��Ԫ���ȳ�ջ 
	return true;//ָ���1 
}

int main()
{
	SqStack S;//����һ��˳��ջ(����ռ�) 
	InitStack(S);
	int x; 
	for(int i=0;i<MaxSize;i++)
	{
		printf("�����ջ����ֵ��"); 
		scanf("%d",&x);
		Push(S,x);
	}
	for(int i=0;i<MaxSize;i++)
	{
		printf("%d ",S.data[i]);
	}
	printf("\n");
	int n;
	printf("�����ջ�ĸ�����"); 
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
