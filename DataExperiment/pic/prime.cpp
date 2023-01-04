#include<stdlib.h>
#include<stdio.h>
#include<math.h>
 
#define inf 0x3f3f3f3f
#define maxx 505
int e[maxx][maxx];//记录两点之间的权值 
int n,m;	//分别为顶点数和边数

int vis[maxx];//记录访问情况
int dist[maxx];//记录最短距离 
int p[maxx];//记录前驱节点，方便输出
int mincost;//记录最小费用 
void Prim(int u){		//u作为我们开头的节点
	for(int i=1;i<=n;i++){ //最坏情况的u顶点全连，所以i<=n
		dist[i]=e[u][i];	//更新最短路径数组，此时只有u顶点在vis数组
		p[i]=u;		
	}
	vis[u]=1;		//节点u已经入树
	for(int i=1;i<=n;i++){	//遍历所有顶点
		double temp=inf;	
		int t=u;			//t对应下一个进入vis数组的顶点
		for(int j=1;j<=n;j++){
			if(!vis[j]&&dist[j]<temp){	//如果j顶点没有再vis内，且对应dist路径是最短的，最后把最短的dist赋给temp，顶点记录给t
				temp=dist[j];
				t=j;
			}
		} 
		if(t==u)break;					//这个是t都不连通的情况，压根没一个和他有关系，进行不下去了
		vis[t]=1;						//t顶点入vis（与vis数组中顶点最短的进入vis）
		mincost+=dist[t];				//最短和路径+现阶段最短路径呗
		for(int j=1;j<=n;j++){			//更新dist数组
			if(!vis[j]&&dist[j]>e[t][j]){
				dist[j]=e[t][j];
				p[j]=t;
			}
		}
	}
}
void displayEdge(int n){
	for(int i=2;i<=n;i++){
		printf("%d -> %d: %d\n",p[i],i,dist[i]);	//遍历输出其前驱,自己，还有最短路径
	}
}
int main(){
	int t;
	printf("请输入顶点数和边数: \n");
	while(scanf("%d %d",&n,&m)){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					e[i][j]=0;		
				}else{
					e[i][j]=inf;
				}
			}
		}
		for(int i=0;i<maxx;i++){
			vis[i]=0;
			p[i]=0;
			dist[i]=inf;
		}
		for(int i=1;i<=m;i++){
			int a,b,cost;
			scanf("%d %d %d",&a,&b,&cost);
			e[a][b]=e[b][a]=cost;
		}
		mincost=0;
		Prim(1);
		printf("最小费用 = %d\n",mincost);
		displayEdge(n);
		printf("请输入顶点数和边数: \n");
	}
	return 0;
}

 