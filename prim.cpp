#include<stdio.h>
#include<stdlib.h>
#define INFINITY 1000
#define MAXVEX 20
typedef struct{
	int numVertexes;
	int numEdges;
	int arc[MAXVEX][MAXVEX];
}MGraph;
void prim(MGraph G){
	int min,i,j,k;
	int adjvex[MAXVEX];
	int lowcost[MAXVEX];
	lowcost[0]=0;
	adjvex[0]=0;
	for(i=1;i<G.numVertexes;i++){
		lowcost[i]=G.arc[0][i];//将邻接矩阵第0行所有权值先加入数组
		adjvex[i]=0;//初始化全部先为V0的下标
	}
	for(i=1;i<G.numVertexes;i++){
		min=INFINITY;
		j=1;
		k=0;
		//遍历全部顶点
		while(j<G.numVertexes){
			//找出lowcost数组中已存储的最小权值
			if(lowcost[j]!=0&&lowcost[j]<min){
				min=lowcost[j];
				k=j;//将发现的最小权值的下标存入k,以待使用
			}
			j++;
		}
		//打印当前顶点边中权值最小的边
		printf("(%d,%d)",adjvex[k],k);
		lowcost[k]=0;//将当前顶点的权值设置为0，表示此顶点已经完成任务进行下一个节点的遍历
	    //邻接矩阵k行逐个遍历全部顶点
		for(j=1;j<G.numVertexes;j++){
			if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j]){
				lowcost[j]=G.arc[k][j];
				adjvex[j]=k;
			}
		}
	}
}
int main(){
	return 0;
}