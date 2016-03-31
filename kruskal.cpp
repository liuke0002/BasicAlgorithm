#include<stdio.h>
#include<stdlib.h>
int find(int *parent,int f){
	while(parent[f]>0){
		f=parent[f];
	}
	return f;
}
typedef struct{
	int begin;
	int end;
	int weight;
}Edge;
typedef struct {
	int numEdges;
	int numVexes;
	Edge edges[20];
}MGraph;
void Kruskal(MGraph G){
	int i,n,m;
	Edge edges[MAXEDGE];//定义边集数组
	int parent[i]=0;//定义parent数组来判断边与边是否形成环路
	for(i=0;i<G.numVertexes;i++){
		parent[i]=0;
	}
	for(i=0;i<G.numEdges;i++){
		n=find(parent,edges[i].begin);
		m=find(parent,edges[i].end);
		if(n!=m){
			parent[n]=m;
			printf("(%d,%d)",edges[i].begin,edges[i].end,edges[i].weight);
		}
	}
}