//统计一个字符串中出现的字符及其次数
#include<stdio.h>
#include<malloc.h>
#include<string.h>


#define MAXWORD 100

typedef int KeyType;

typedef struct tnode 
{
	char ch;//字符
	int count;//出现次数
	struct tnode *lchild,*rchild;
}BTree;


void CreaTree(BTree *&p,char c)
{//采用递归方法构造一棵二叉排序树
	if(p==NULL)//p为NULL，则建立一个新结点
	{
		p=(BTree *)malloc(sizeof(BTree));
		p->ch=c;
		p->count=1;
		p->lchild=p->rchild=NULL;
	}
	else if(c==p->ch)
		p->count++;
	else if(c<p->ch)
		CreaTree(p->lchild,c);
	else
		CreaTree(p->rchild,c);
}

void InOrder(BTree *p)//中序遍历BST
{
	if(p!=NULL)
	{
		InOrder(p->lchild);//中序遍历左子树
		printf("字符 %c 在本串中出现的次数：%d \n",p->ch,p->count);//访问根节点
		InOrder(p->rchild);//中序遍历右子树
	}	
}


int main()
{
	BTree *root=NULL;
	int i=0;
	char str[MAXWORD];
	printf("\n");
	printf("输入字符串:");
	gets(str);
	while(str[i]!='\0')
	{
		CreaTree(root,str[i]);
		i++;
	}
	printf("各字符及出现次数:\n");
	InOrder(root);
	printf("\n");	
	return 0;
}
