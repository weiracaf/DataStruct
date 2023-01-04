#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
 
/**
	栈的顺序存储类型描述
	栈顶指针S.top,初始化时设置S.top=-1;
	栈顶元素S.data[S.top];
**/
typedef struct SqStack{
	int data[MaxSize];//存放栈元素
	int top;	//栈顶指针
}SqStack;
 
/**
	栈判空
**/
bool StackEmpty(SqStack S){
	if(S.top==-1) //栈空
		return true;
	else 
		return false;
}
 
/**
	初始化一个栈，并将栈顶指针指向-1
*/
void InitStack(SqStack &S){
	S.top = -1; //初始化栈顶指针
}
 
/**
	进栈
**/
bool Push(SqStack &S,int x){
	if(S.top==MaxSize-1) //栈顶指针指向最后一个，栈满，报错，因为数组下标从0开始，数组下标最大值为Max-1
		return false;
	S.data[++S.top] = x; //应熟练掌握++i和i++的区别，这里因为top指针指向的是栈目前最后一个元素，需要将指针移到下一个再装填新元素，否则会覆盖，所以使用++S.top。
	return true;
}
 
/**
	出栈
*/
bool Pop(SqStack &S,int &x){
	if(S.top==-1)
		return false;
	x = S.data[S.top--]; //将栈顶元素弹出，指针往下-1。
		return true;
}
 
/**
	读取栈顶元素
*/
int GetTop(SqStack S){
	if(S.top==-1)
		return false;
	 int x = S.data[S.top];
	return x;
}
 
/*
	清空栈
*/
bool ClearStack(SqStack &S){
	if(S.top==-1)
		return false;
	S.top=-1;     //将栈顶指针指向-1,遍历的时候到top就结束
	return true;
}
 
/**
	销毁栈
*/
bool DestroyStack(SqStack &S){
	if(S.top==-1)
		return false;
	free(S.data);
	return true;
}
 
/**
	遍历输出栈
*/
bool PrintStack(SqStack S){
	if(S.top==-1){
		printf("栈为空");
		return false;}
	for(int i =0;i<=S.top;i++){
		printf("          |%d|\n",S.data[S.top-i]);
	}
	return true;
}
 
int main(){
 
	SqStack S;
	InitStack(S);
	int chose;
	int push,pop;
	printf("\n---------------------------------------------\n");
	printf("请选择功能：\n1:入栈   2:出栈  3:判空  4:读取栈顶元素 4:遍历  6:清空栈 7:销毁栈\n");
	scanf("%d",&chose);
	while(chose == 0 || chose == 1 ||chose == 2 ||chose == 3 ||chose == 4 ||chose == 5 ||chose == 6 ||chose == 7 ){
		switch(chose){
			case 0:
				scanf("%d",&chose);continue;
			case 1:
				printf("请输入入栈数：");
				scanf("%d",&push);
				Push(S,push);
				printf("入栈后为：\n");
				PrintStack(S);
				chose = 0;
				break;
			case 2:
				Pop(S,pop);
				printf("将栈顶元素 %d 出栈\n",pop);
				printf("出栈后为：\n");
				PrintStack(S);
				pop = NULL;
				chose = 0;
				break;
			case 3:
				if(StackEmpty(S)){
					printf("栈空\n");
				}else
					printf("栈不为空\n");
				chose = 0;
				break;
			case 4:
 
				printf("栈顶元素为%d",GetTop(S));
				chose = 0;
				break;
			case 5:
				PrintStack(S);
				chose = 0;
				break;
			case 6:
				 ClearStack(S);
				 printf("清空栈\n");
				chose = 0;
				break;
			case 7:
				DestroyStack(S);
				printf("销毁栈\n");
				chose = 0;
				break;
 
		}
		printf("\n---------------------------------------------\n");
		printf("请选择功能：\n1:入栈   2:出栈  3:判空  4:读取栈顶元素 5:遍历  6:清空栈 7:销毁栈\n");
	}
	return 0;
}
 