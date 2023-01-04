#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node *next;
} Stacknode,*LinkStack; //定义结点和头指针类型名

//初始化链栈
void Init_LinkStack(LinkStack &s)
{
    //printf("init执行开始\n");
    s=(Stacknode *)malloc(sizeof(Stacknode));
    s->next=NULL;
    //printf("init执行结束\n");
}


//入栈
void Push(LinkStack &s,ElemType e)
{
    //printf("push执行开始\n");
    Stacknode *p;
    p=(Stacknode *)malloc(sizeof(Stacknode));
    p->data=e;//头插法
    p->next=s;
    s=p;
    //printf("push执行结束\n");
}

//出栈
int Pop(LinkStack &s)
{
    Stacknode *p;
    if(s==NULL)
    {
        printf("栈空\n");
        return 1;
    }
    else
    {
        p=s;
        s=p->next;//往后挪一位
        free(p);
        return 1;
    }
}

//查看栈顶元素
int GetTop(LinkStack &s)
{
    if(s==NULL)
    {
        printf("栈空\n");
        return 0;
    }
    else
    {
        printf("%d",s->data);
        return 1;
    }
}

//链表的显示
void Display_LinkStack(LinkStack &s)
{
    //printf("display执行开始\n");
    Stacknode *p;
    p=s;

    //printf("%d",p->data);
    while(p->next!=NULL)
    {
        printf("            %6d\n",p->data);
        //printf("12");
        p=p->next;
    }
    //printf("display执行结束\n");
}

int main()
{
    LinkStack s;
    int i=1;
    ElemType x;
    Init_LinkStack(s);
    
    //Display_LinkStack(s);
    while(i)//保证一直进行
    {
        printf("------------------------------------\n");
        printf("    1   进栈    \n");
        printf("    2   出栈   \n");
        printf("    3   读取栈顶元素   \n");
        printf("    0   结束程序      \n");
        printf("------------------------------------\n");
        printf("请输入你选择的菜单号<1, 2, 3, 0>:\n");
        scanf("%d",&i);
        switch(i)
        {
        case 1:
            printf("请输入进栈元素：");
            scanf("%d",&x);
            Push(s,x);
            //Display_SeqStack(&s);
            printf("\n\n");
            break;
        case 2:
            Pop(s);
            //Display_SeqStack(&s);
            printf("\n\n");
            break;
        case 3:
            printf("栈顶元素为：");
            GetTop(s);
            printf("\n\n");
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("输入有误~\n");
            break;
        }
        printf("当前的顺序栈如下（下为底，上为顶）：\n");
        Display_LinkStack(s);
    }
    return 0;
}
