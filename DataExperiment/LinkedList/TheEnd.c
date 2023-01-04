/*
本代码主要是讲解
线性表的单链表（带头结点）的基本操作
*/
#include <stdio.h>
#include <stdlib.h>
#define bool char
#define true 1
#define false 0

typedef struct LNode{
    int data;
    struct LNode *next;
}LNOde,*Linklist;
Linklist InitList(Linklist L){//单链表的初始化，带头节点版本
    L=(Linklist)malloc(sizeof(LNOde));
    L->next=NULL;
    return L;
}
bool ListInsert(Linklist L,int i,int e){//在L链表的第i个位置，插入带有e元素的结构体
    if(i<1)
    return false;
    Linklist p=L;
    int j=0;
    while (p!=NULL&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if (p==NULL)
    return false;
    Linklist s=(Linklist)malloc(sizeof(LNOde));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

void OrderInsert(Linklist L,int e){//顺序插入，将含e的结构体，插入得到链表最后一个位置
    Linklist p=L;
    while(p->next!=NULL){
        p=p->next;
    }
    Linklist s=(Linklist)malloc(sizeof(LNOde));
    s->data=e;
    p->next=s;
    s->next=NULL;
}   
int ListLength(Linklist L)//获取链表长度
{
	int n = 0;
    Linklist p = L;
	while(p->next!=NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}
bool ListDelete(Linklist L,int i,int *e){//按位序删除，删除L链表的第i个位置上的元素，并赋值给*e返回
    if(i<1)
    return false;
    Linklist p=L;
    int j=0;
    while(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    if(p==NULL)
    return false;
    if(p->next==NULL)
    return false;
    Linklist s=p->next;
    *e=s->data;
    p->next=s->next;
    free(s);
    return true;
}
bool DeleteNode(Linklist L){//删除某个指定的节点
    if(L==NULL)
    return false;
    Linklist q=L->next;
    L->data=q->data;
    L->next=q->next;
    free(q);
    return true;
}
Linklist GetElem(Linklist L,int i){//按位查找，返回第i个节点指针
    if(i<0)
    return NULL;
    Linklist p=L;
    int j=0;
    while(p!=NULL&&j<i){
        p=p->next;
        j++;
    }
    return p;//这里直接return就可以，因为没有也是返回NULL

}
Linklist LocateElem(Linklist L,int e){//按值查找，返回对应节点
    Linklist p=L;
    while(p!=NULL&&p->data!=e)
    p=p->next;
    return p;
}
void DispList(Linklist L)
{
    Linklist p = L->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}
bool create(Linklist L){
    if(L==NULL)
    return false;
    int e;
    printf("输入你想要添加的个数");
    scanf("%d",&e);
    int a;
    for (int i = 0; i < e; i++)
    {
        scanf("%d",&a);
        OrderInsert(L,a);
    }
    return true;
}

int main(){
    Linklist L=InitList(L);
    create(L);
    DispList(L);
    printf("当前链表长度为%d\n",ListLength(L));
    ListInsert(L,2,5);
    DispList(L);
    printf("链表第三个位置上的元素是%d\n",GetElem(L,3)->data);
    DeleteNode(LocateElem(L,5));
    DispList(L);
    return 0;
}