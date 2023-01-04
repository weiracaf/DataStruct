#include <stdio.h>
#define MaxSize 10
#define bool char
#define true 1
#define false 0
typedef struct a{
int a[MaxSize];//用静态数组存放数据元素
int front,rear;//队头指针和队尾指针
}*Queue,SqQueue;

    void Iint(Queue a){//初始化
        a->front=a->rear=0;//队头一直指向0，队尾的一直让他作为插入元素存放的位置（已有元素后一个位置），刚开始0也没有元素正好=0
    }


int main(){

}