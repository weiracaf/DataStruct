/*
关于单链表的各种操作的代码
*/
#include <stdio.h>
#include <stdlib.h>
#define bool char
#define true 1
#define false 0
typedef struct C
{
    int data;
    struct C *next;
}LNode,*LinkList;
LinkList InitList();//初始化一个单链表
bool ListInsert(LinkList a,int i,int e);//实现链表的插入操作（在a链表的第i位置上插入含e元素结构体）



int main(){
    
    LinkList a=InitList();
    ListInsert(a,1,1);
    ListInsert(a,2,2);
    ListInsert(a,3,3);
    printf("%d",a->next->data);
}
LinkList InitList(){//初始化一个单链表，带头结点版本
    LinkList a;
    a=(LinkList)malloc(sizeof(LNode));//为头节点分配空间，且头结点data不存放数据
    a->next=NULL;
    return a;
}
bool ListInsert(LinkList a,int i,int e){//实现链表的插入操作
    if(i<1)
    return false;
    LinkList p=a;
    int j=0;
    while (p!=NULL&&j<i-1)//这里应为要插在第i个位置所以要找第i-1的节点然后指向加入的数据，他就是第i个喽，且头结点不存放数据算第0个节点
    {
        p=p->next;
        j++;
    }
    if(p=NULL)
    return false;
    LinkList s=(LinkList)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;//先让新的接后的，然后前接新，不用创建第三个变量
    p->next=s;
    return true;
    

}
