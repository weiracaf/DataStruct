#include <stdio.h>
#include <stdlib.h>
typedef struct ListStack
{
    int e;
    struct ListStack *next;

}*LiStcak,LStack;

 LiStcak Init(){
    LiStcak a;
    a=(LiStcak)malloc(sizeof(LStack));
    a->next=NULL;
    return a;
}

/*无头节点写法
Listcak Init(){
    Listack a;
    a=NULL;
    return a;
}
对应的插入操作

void INsert(int a,Listcak L){
    LiStcak E=(LiStcak)malloc(sizeof(LStack));
    E->e=a;
    E->next=L;
    L=E;
}
*/
//这种直接赋不带头结点的就是直接赋值！！！，把对应的指针赋值到对应的malloc的节点（第一个），头插法的话，一直赋值到新malloc1的节点
//尾插法就直接从头结点往后找就行
void Insert(int a,LiStcak L){
    LiStcak E=(LiStcak)malloc(sizeof(LStack));
    E->e=a;
    E->next=L->next;
    L->next=E;

}
void Delete(LiStcak L,int a){//a是从栈顶取出多少元素，L是对应的栈
    for(int i=0;i<a;i++)
    {
        
        LiStcak c=L->next;
        L->next=c->next;
        free(c);

    }

}

 int main(){
    LiStcak a = Init();
    Insert(1,a);
    Insert(2,a);
    printf("%d\n",a->next->e);
    printf("%d\n",a->next->next->e);
    Delete(a,1);
    printf("%d\n",a->next->e);
    

 }