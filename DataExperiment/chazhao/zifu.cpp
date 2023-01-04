//ͳ��һ���ַ����г��ֵ��ַ��������
#include<stdio.h>
#include<malloc.h>
#include<string.h>


#define MAXWORD 100

typedef int KeyType;

typedef struct tnode 
{
	char ch;//�ַ�
	int count;//���ִ���
	struct tnode *lchild,*rchild;
}BTree;


void CreaTree(BTree *&p,char c)
{//���õݹ鷽������һ�ö���������
	if(p==NULL)//pΪNULL������һ���½��
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

void InOrder(BTree *p)//�������BST
{
	if(p!=NULL)
	{
		InOrder(p->lchild);//�������������
		printf("�ַ� %c �ڱ����г��ֵĴ�����%d \n",p->ch,p->count);//���ʸ��ڵ�
		InOrder(p->rchild);//�������������
	}	
}


int main()
{
	BTree *root=NULL;
	int i=0;
	char str[MAXWORD];
	printf("\n");
	printf("�����ַ���:");
	gets(str);
	while(str[i]!='\0')
	{
		CreaTree(root,str[i]);
		i++;
	}
	printf("���ַ������ִ���:\n");
	InOrder(root);
	printf("\n");	
	return 0;
}
