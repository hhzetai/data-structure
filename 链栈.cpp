//栈的链式存储
#include <stdlib.h>
#include <stdio.h>


typedef struct Node //栈的结点结构
{
    int data;
    struct Node *next;
}Node,*PNode;

typedef struct LinkStack //栈的结构
{
    PNode top; //栈顶
    int count; 
}LinkStack;

bool InitStack(LinkStack *S)
{ 
        S->top = (PNode)malloc(sizeof(Node));
        if(!S->top)  //有无可分配的内存
                return false;
        S->top=NULL;
        S->count=0;
        return true;
}


LinkStack* push( LinkStack * stack,int n )
{
    PNode s;
    s=(PNode)malloc(sizeof(Node));
    s->data=n;
    s->next=stack->top;
    stack->top=s;
    stack->count++;

    return stack;
}
bool pop( LinkStack *stack,int & n )
{
    if( stack->count==0 )
        return false;
    n=stack->top->data;
    PNode s=stack->top;
    stack->top=s->next;

    free(s);
    stack->count--;
    return true;
}



int main()
{
    LinkStack stack; //栈必须初始化
    int i=10;
    if(InitStack(&stack))
        while( i-- )
            push(&stack,i);
    int t=0;
    while( stack.count ){
        if(pop(&stack,t))
            printf( "%d pop\n",t );
    }
    return 0;
}


