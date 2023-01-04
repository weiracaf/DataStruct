#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OVERFLOW	-1
typedef struct {
	unsigned int weight;//权重
	unsigned int partent, lchild, rchild;
}HTNode,* HuffmanTree;
typedef int Status;
typedef char** HuffmanCode;

void Select(HuffmanTree* HT, int n, int* s1, int* s2) { //挑选两个权值最小的构成新节点（子树）
	int i;
	unsigned int min = 9999;        //记录最小权值
	int temp1 = 0, temp2 = 0;       //两个权值小的节点，temp1存放最小的，temp2存放第二小的。
	for (i = 1;i <= n;i++) {
		if ((*HT)[i].partent == 0 && (*HT)[i].weight < min) {
			min = (*HT)[i].weight;
			temp1 = i;
		}
	}
	*s1 = temp1;
	min = 9999;
	for (i = 1;i <= n;i++) {
		if ((*HT)[i].partent == 0 && (*HT)[i].weight < min && temp1 != i) {//防止条到重复的
			min = (*HT)[i].weight;
			temp2 = i;
		}
	}
	*s2 = temp2;
}
void HuffmanCoding(HuffmanTree* HT, HuffmanCode* HC, int w[], int n) {//i个节点
	//w存放n个字符的权值(均>0)，构造哈夫曼树HT，并求出n个字符的哈夫曼编码HC。
	if (n <= 1)return;
	int m = 2 * n - 1; //一共2n-1个节点
	(*HT) = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));  //第0个节点不用申请m+1个空间
	if (!(*HT))exit(OVERFLOW);//0节点退出
	int i;		
	for (i = 1;i <= n;++i) {//前n个节点权值
		(*HT)[i].weight = w[i];//权值
		(*HT)[i].partent = 0;
		(*HT)[i].lchild = 0;
		(*HT)[i].rchild = 0;
	}
	for (i=n+1;i <= m;++i) {//后n个节点无权值奥，直接权=0即可
		(*HT)[i].weight = 0;
		(*HT)[i].partent = 0;
		(*HT)[i].lchild = 0;
		(*HT)[i].rchild = 0;
	}
	int s1, s2;
	for (i = n + 1;i <= m;++i) {	//建哈夫曼树，i=n+1开始一个个赋值呗
		//在HT[1...i-1]选择parent为0且weight最小的两个结点，其序号分别为s1和s2
		Select(HT, i - 1, &s1, &s2);//还要传入新的节点所以第二个参数是i-1，几个有权值循环几个
		(*HT)[s1].partent = i;(*HT)[s2].partent = i; //给个爸妈，以防再次调用
		(*HT)[i].lchild = s1;(*HT)[i].rchild = s2;  //孩子
		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;  //父母的权值是孩子之和
	}

	//---从叶子到根逆向求每个字符的哈夫曼编码---
	(*HC) = (HuffmanCode)malloc((n + 1) * sizeof(char*)); //从下标1开始存储n个字符编码空间
	if (!(*HC))exit(OVERFLOW);
	char* cd = (char*)malloc(n * sizeof(char)); //临时存放每个字符编码的动态数组空间
	if (!cd)exit(OVERFLOW);
	cd[n - 1] = '\0';   //编码结束符
	for (int i = 1;i <= n;++i) {
		int start = n - 1;//要倒序存（从叶子节点开始到根的路径和根的叶子节点路径相反奥），所以从n-1开始放
		int f = 0;//来做i的父母节点进行判断存0还是1
		for (int c = i, f = (*HT)[i].partent;f != 0;c = f, f = (*HT)[f].partent)
			if ((*HT)[f].lchild == c)cd[--start] = '0';//左子树存0
			else cd[--start] = '1';//右子树存1
		(*HC)[i] = (char*)malloc((n - start) * sizeof(char));//最后申请一个新空间，看存了多少，申请多少
		if (!(*HC)[i])exit(OVERFLOW);
		strcpy((*HC)[i], &cd[start]);//把对应编码赋值给新空间
	}
	free(cd);
}


int main() {
	HuffmanTree HT;
	HuffmanCode HC;
	printf("请输入待编码字符个数:");
	int n;
	scanf_s("%d", &n);
	int w[100];
	printf("请输入对应字符的权值:");
	for (int i = 1;i <= n;i++) {
		scanf_s("%d", &w[i]);
	}
	HuffmanCoding(&HT, &HC, w, n);
	for (int i = 1;i <= 2 * n - 1;i++) {
		printf("%d:\t%d\t%d\t%d\t%d\n", i, HT[i].weight, HT[i].partent, HT[i].lchild, HT[i].rchild);
	}
	for (int i = 1;i <= n;i++) {
		printf("权值为%d的哈夫曼编码:%s\n", w[i],HC[i]);
	}
    return 0;
}
