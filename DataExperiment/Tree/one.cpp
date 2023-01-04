#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef char DataType;
typedef struct BiTNode {
	DataType data;
	int LTag;
	int RTag;
	struct BiTNode *LChild;
	struct BiTNode *RChild;
}BiTNode, *BiTree;

void CreateBiTree(BiTree *root)	//先序遍历创建二叉树
{	
	char ch;
	ch = getchar();
	if (ch == '.')   *root = NULL;
	else {
		*root = (BiTNode *)malloc(sizeof(BiTNode));
		(*root)->data = ch;
		(*root)->LTag = 0;
		(*root)->RTag = 0;
		CreateBiTree(&((*root)->LChild) );  //依次设立其左子树
		CreateBiTree(&((*root)->RChild));	//依次设立其右子树
	}
}
BiTNode *pre = NULL; 
//将一棵树中序线索化
void InThread(BiTree root) //中序遍历的过程中进行一个线索化
{
	if (root == NULL) return;

	InThread(root->LChild);
	if (root->LChild == NULL) {
		root->LTag = 1;
		root->LChild = pre;   //左中右中序排序最左边的前驱节点一定为NULL，最右边的后继节点一定为NULL
	}
	if (pre != NULL && pre->RChild == NULL) {		//这步操作是把pre前一个节点1的右孩子子项后继节点
		pre->RTag = 1;
		pre->RChild = root;
	}
	pre = root;
	InThread(root->RChild);
}

BiTree Firstnode(BiTree a){  //找到以a为根节点第一个被中序遍历的节点！！！
	while (a->LTag==0)		//有左孩子的话
	{
		a=a->LChild;
	}
	return a;

}
BiTree Lastnode(BiTree a){	//找到以a为根节点的最后一个被中序遍历的节点
	while(a->RTag==0)
	{
		a=a->RChild;
	}
	return a;
}

BiTree houji(BiTree a){  //后继
	if(a->RTag==1)
	return a->RChild;
	else 
	return Firstnode(a->RChild);  //当rtag不为1，肯定有右孩子（右子树第一个遍历的节点就是对应a的后继奥）
	}
BiTree qianqu(BiTree a){
	if(a->LTag==1)
	return a->LChild;
	else return Lastnode(a->LChild);	//Ltag不为1，肯定有左孩子（左子树最右下角节点是a的前驱）
}

int main(){
	BiTree p;
	printf("先序创建二叉树");
	CreateBiTree(&p);
	InThread(p);
	printf("根节点的前驱为%c",qianqu(p)->data);
	printf("根节点的后继为%c",houji(p)->data);
	return 0;
}