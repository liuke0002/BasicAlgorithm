#include<stdio.h>
#include<stdio.h>
#define MAX_VERTEX_NUM 100
#define MAX_INT 10000
typedef int AdjType;
typedef char VType;//设顶点类型为字符类型
typedef struct{
	VType V[MAX_VERTEX_NUM];//顶点存储空间
	AdjType A[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
}MGraph;
void Floyd(MGraph *G,int path[][MAX_VERTEX_NUM],int D[][MAX_VERTEX_NUM],int n){
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(G->A[i][j]<MAX_INT){
				path[i][j]=j;
			}else{
				path[i][j]=-1;
			}
			D[i][j]=G->A[i][j];
		}
	}
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(D[i][j]>D[i][k]+D[k][j]){
					D[i][j]=D[i][k]+D[k][j];
					path[i][j]=path[i][k];
				}
			}
		}
	}
}
int main(){
	int i,j,k,v=0,n,ajdm;
	int path[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	//打印最短路径的path
	k=path[x][y];
	printf("%d ",x);
	while(k!=y){
		printf("%d  ",k);
		k=path[k][y];
	}
	printf("%d\n",y);
	return 0;

}