/*
本代码主要写的是线性表的顺序表实现交集
*/

#define MaxSize 10
#include <stdio.h>
#include <stdlib.h>
#define bool char
#define true 1
#define false 0
typedef struct{
    int data[MaxSize];
    int length;
}SqList,*LNode;

void InitList(LNode L){//初始化操作
for(int i=0;i<MaxSize;i++){
	L->data[i]=i;
	}//数据的初始化
	L->length=0;//length用来记录我们存储的数据，便于循环操作有价值的（我们定义的）数据	
}
bool ListInsert(LNode L,int i,int e){//将e元素插入到L顺序表的第i个（从1开始）位置
    if(i<1||i>L->length+1)//判断i范围是否有效
    return false;
    if(L->length>=MaxSize)//当前存储空间已满，不能插入
    return false;
    for (int j=L->length;j>=i;j--)
    L->data[j]=L->data[j-1];
    L->data[i-1]=e;
    L->length++;
    return true;
}
bool OrderInsert(LNode L,int i){//由于c语言没有重载，换个名称，向当前位置紧接着后一个添加i元素
    if(L->length>=MaxSize)
    return false;
    L->data[L->length]=i;
    L->length++;
    return true;
}
bool ListDelete(LNode L,int i,int *e)//将L线性表第i位置（从1开始）上的元素删除，并返回给e
{
    if(i<1||i>L->length)
    return false;
    *e=L->data[i-1];
    for (int j = i; j < L->length; j++)
        L->data[j-1]=L->data[j];
        L->length--;
    return true;    
}
int GetElem(int i,LNode L)//按位查找，查找L链表的第i个元素
{
    return L->data[i-1];
}
int LocateElem(int e,LNode L)//通过值来查找返回对应的第一个查找到的次序,（第几个元素的次序）
{
    for (int i = 0; i < L->length; i++)
    if(L->data[i]==e)
    return i+1;
    return 0;//如果没有返回0
}



int main(){
    SqList a;SqList b;SqList c;
    LNode L=&a;LNode L1=&b;LNode L2=&c;
    int d=0;
    InitList(L);
    OrderInsert(L,1);
    OrderInsert(L,2);
    OrderInsert(L,3);
    OrderInsert(L,4);
    ListInsert(L,3,5);
    InitList(L1);
    OrderInsert(L1,1);
    OrderInsert(L1,2);
    OrderInsert(L1,3);
    OrderInsert(L1,4);
    ListInsert(L1,3,5);
    InitList(L2);
    for (int i = 0; i < L->length; i++)
    {
        printf("%d\n",L->data[i]);
    }

    printf("========================\n");
    printf("%d\n",GetElem(3,L));

    printf("%d\n",LocateElem(1,L));

    printf("========================\n");
    ListDelete(L,3,&d);
    for (int i = 0; i < L->length; i++)
    {
        printf("%d\n",L->data[i]);
    }
    

}








