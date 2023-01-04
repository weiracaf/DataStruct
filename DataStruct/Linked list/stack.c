#include <stdio.h>
#define MaxSize 10
#define bool char
#define true 1
#define false 0
bool Push(Lstack S,int a);
typedef struct {
    int data[MaxSize]; //存放栈中的元素
    int top; //栈顶指针（数组下标）
}stack,*Lstack;


int mian(){
    stack S;//声明一个栈，分配空间

}

bool Push(Lstack S,int a){//入栈操作
    if(S->top=MaxSize-1)
    return false;
    S->top=S->top+1;
    S->data[S->top]=a;
    return true;
}