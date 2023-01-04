#include<stdio.h>
#include<stdlib.h>
#define MaxVertexnum 11
//================================队列===========================
//队列节点的结构定义 
typedef struct Linknode{
	int data;
	struct Linknode *next;
}Linknode;
//队列首尾指针的定义 
typedef struct{
	Linknode *front,*rear;
}LinkQueue;

//初始化队列 
void InitQueue(LinkQueue &Q){
	//带头结点的链队列 
	Q.front=(Linknode*)malloc(sizeof(Linknode));
	Q.rear=Q.front;
	Q.front->next=NULL;
}
//入队 
void EnQueue(LinkQueue &Q,int p){
	//S指向新节点，连接Q.rear后面
	Linknode *S=(Linknode*)malloc(sizeof(Linknode));
	S->data=p;
	S->next=NULL;
	Q.rear->next=S;
	Q.rear=S; 	
} 
//出队
bool DeQueue(LinkQueue &Q,int &p){
	//如果队空就不能出队列了
	if(Q.front==Q.rear) return false;
	Linknode *q=Q.front->next;
	p=q->data;
	Q.front->next=q->next;
	//刚好最后一个结点出队了，把rear指向头结点从而判空
	if(q==Q.rear){
		Q.rear=Q.front;
	}
	free(q);
	return true;
}
//判空 
bool isEmptyQueue(LinkQueue Q){
	if(Q.front==Q.rear) return true;
	else return false;
}



//=======================图======================

bool visited[MaxVertexnum];//存储访问过的节点
//图---邻接矩阵法 
typedef struct{
	char Ver[MaxVertexnum];				//顶点表 
	int Edge[MaxVertexnum][MaxVertexnum];//边表 
	int Vexnum,arcnum;//顶点数，边数 
}MGraph; 
//输出邻接矩阵
void input_MGraph(MGraph &G){
	int x=0,y=0;
	for(int i=0;i<MaxVertexnum;i++) G.Ver[i]=65+i;
	for(int i=0;i<MaxVertexnum;i++) printf("%c ",G.Ver[i]);
	for(int i=0;i<MaxVertexnum;i++){
		for(int j=0;j<MaxVertexnum;j++)
			G.Edge[i][j]=0;
	}
	printf("\n请输入图的顶点数：");
	scanf("%d",&G.Vexnum);
	printf("请输入图的边数：");
	scanf("%d",&G.arcnum);
	getchar();
	for(int i=0;i<G.arcnum;i++){
		printf("请输入图边的无序对：");
		scanf("%d,%d",&x,&y);
		G.Edge[x-1][y-1]=G.Edge[y-1][x-1]=1;
	}
	for(int i=0;i<MaxVertexnum;i++){
		for(int j=0;j<MaxVertexnum;j++)
			printf("%d ",G.Edge[i][j]);
		printf("\n");
	}
}


void BFS(MGraph &G,LinkQueue &Q,int v);

//找到v节点在G中的第一个邻接节点
int FirstNeighbor(MGraph &G,int v){
	int i=0;
	for(i=0;i<G.Vexnum;i++){
		if(G.Edge[v][i]==1) return i;
	}
	return -1;
}
//w为v的一个邻接顶点，返回除了w之外顶点v的下一个邻接的顶点号，若w为v最后一个邻接点返回-1
int NextNeighbor(MGraph &G,int v,int w){
	int i=w;
	for(i=w+1;i<G.Vexnum;i++){//从w+1开始
		if(G.Edge[v][i]==1) return i;
	}
	return -1;
}

void BFSTravese(MGraph &G){ //对图G进行广度优先遍历（这里进行一些初始化操作）
	for(int i=0;i<G.Vexnum;i++) visited[i]=false; //赋初值，先全设成false
	LinkQueue Q;
	InitQueue(Q);
	for(int i=0;i<G.Vexnum;i++){	//从0号顶点开始遍历,这是对于非连连通图的有效操作
		if(!visited[i]) BFS(G,Q,i);	//如果对应节点没有访问过，访问i节点
	}
} 

void BFS(MGraph &G,LinkQueue &Q,int v){	//从顶点v出发，广度遍历图G
	int w=0;
	printf("%c  ",G.Ver[v]);	//访问
	visited[v]=true;			//该点已经访问
	EnQueue(Q,v);				//入队
	while(!isEmptyQueue(Q)){	
		DeQueue(Q,v);			//出队！，这里v是出队元素对应的顶点
		for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w)){ //遍历v附近的顶点
			if(!visited[w]){
				printf("%c  ",G.Ver[w]);
				visited[w]=true;
				EnQueue(Q,w);		
			}
		}
	}
}
void DFS(MGraph &G,int v);
void DFSTraverse(MGraph &G){		//初始化操作
	for(int i=0;i<G.Vexnum;i++) visited[i]=false;
	for(int i=0;i<G.Vexnum;i++){	//非连通图的有效操作
		if(!visited[i]) DFS(G,i);
	}
}
void DFS(MGraph &G,int v){	//核心操作
	printf("%c  ",G.Ver[v]);	//访问第一个顶点
	visited[v]=true;
	int w=0;
	for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w)){ //遍历头节点的所有节点
		if(!visited[w]) DFS(G,w);			//！！！！递归进行的深层遍历！！！！
	}
}
int main(){
	MGraph G;
	input_MGraph(G);
	LinkQueue Q;
	InitQueue(Q);
	printf("\n广度优先遍历序列："); 
	BFSTravese(G);
	printf("\n深度优先遍历序列：");
	DFSTraverse(G); 
	return 0;
} 

