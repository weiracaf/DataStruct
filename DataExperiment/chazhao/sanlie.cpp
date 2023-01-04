#include <stdio.h>

#include <stdlib.h>

typedef struct node
{int key;
struct node *lchild, *rchild;
}BSTNode, *BSTree;

//����
int InsertBST(BSTree *bst, int k)

{BSTree r, s, pre;
    r = (BSTree)malloc(sizeof(BSTNode));
    r->key = k;
    r->lchild = NULL;
    r->rchild = NULL;
    if(*bst == NULL)
    {*bst = r;
    return 1;
    }

pre = NULL;

s = *bst;
while(s)
{
if(k == s->key)
return 0;
else if(k < s->key)
{
pre = s;
s = s->lchild;
}
else
{
    pre = s;
    s = s->rchild;
}
}
    if(k < pre->key)
    pre->lchild = r;
    else
    pre->rchild = r;
    return 1;
}

void CreateBST(BSTree *bst)
{
    int key;
    *bst = NULL;
    scanf("%d", &key);

while(key != -1)

{
InsertBST(bst, key);
scanf("%d", &key);
}
}

void InOrder(BSTree root)

{
if(root != NULL)
{InOrder(root->lchild);
printf(" %d ", root->key);

InOrder(root->rchild);
}

}

BSTree SearchBST(BSTree bst, int key)

{
BSTree q;
q = bst;
while(q)
{
    if(q->key == key)
    return q;
    if(q->key > key)
    q=q->lchild;

else
q=q->rchild;

}
return NULL; //����ʧ��

}

int main()

{BSTree T;

    int tag = 1;

    int m, n;

    printf("����������������������������-1������\n");
    CreateBST(&T);

    printf("�������������������Ϊ��\n");

    InOrder(T);
    printf("\n");

while(tag != 0)

{

    printf("��������Ҫ���ҵ�Ԫ��:\n");

    scanf("%d", &n);

    if(SearchBST(T, n) == NULL)

    printf("��Ǹ����ʧ��!\n");

else

    printf("���ҳɹ������ҵ�����Ϊ%d\n", SearchBST(T,n)->key);

    printf("�Ƿ�������� �� ���밴 1 ���� 0:\n");
    scanf("%d", &tag);
}

return 0;

}