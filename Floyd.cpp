#include<stdio.h>
#include<stdio.h>
#define MAX_VERTEX_NUM 100
#define MAX_INT 10000
typedef int AdjType;
typedef char VType;//Éè¶¥µãÀàÐÍÎª×Ö·ûÀàÐÍ
typedef struct{
	VType V[MAX_VERTEX_NUM];//¶¥µã´æ´¢¿Õ¼ä
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
	//´òÓ¡×î¶ÌÂ·¾¶µÄpath
	k=path[x][y];
	printf("%d ",x);
	while(k!=y){
		printf("%d  ",k);
		k=path[k][y];
	}
	printf("%d\n",y);
	return 0;

}

ashjdhaskjaskjhaskhask

61273812739812891278912
