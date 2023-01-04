#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef struct a{
int data[MaxSize];//用静态数组存放数据元素
int front,rear;//队头指针和队尾指针
}*Queue,SqQueue;
void Iint(Queue a){//初始化
    a->front=a->rear=0;//队头刚开始指向0，队尾的一直让他作为插入元素存放的位置（已有元素后一个位置），刚开始0也没有元素正好=0
}
bool EnQuene(Queue Q,int e){//入队操作
	if((Q->rear+1)%MaxSize==Q->front)//浪费一个存储空间进行操作，判满操作
	return false;
	Q->data[Q->rear]=e;
	Q->rear=(Q->rear+1)%MaxSize;//rear+1后取余
	return true;
}

bool DeQueue(Queue Q,int *x){//出队操作
if(Q->rear==Q->front)//当队列为空时
	return false;
	*x=Q->data[Q->front];
	Q->front=(Q->front+1)%MaxSize;
	return true;	
}
bool GetHead(Queue Q,int *x){//读取队头元素
    if(Q->front==Q->rear)
    return false;
    *x=Q->data[Q->front];
    return true;
}
bool Dis(Queue Q){
    if(Q->front==Q->rear)
    return false;
    int x=Q->front;
    while(x!=Q->rear)
    {
        printf("|%d|\n",Q->data[x]);
        x=(x+1)%MaxSize;
    }
    return true;
}
int main(){
    SqQueue S;
    Queue a=NULL;
    a=&S;
    Iint(a);
    int n=0,shan=0,qu=0,ru=0;
    while(1)
    {
    printf("选择你想要进行的功能\n1:入队\n2:出队\n3:取队头元素\n4:输出队列\n其他:结束程序");
    scanf("%d",&n);

    switch (n)
    {
    case 1:
    printf("输入你想入队的数据\n");
    scanf("%d",&ru);
    EnQuene(a,ru);
    
        break;
    case 2:
    DeQueue(a,&shan);
    printf("出队的元素是%d\n",shan);

    break;
    case 3:
    GetHead(a,&qu);
    printf("队头的元素为%d\n",qu);
    break;
    case 4:
    Dis(a);
    break;
    default:
    exit(1);
    }
 
    }
}


