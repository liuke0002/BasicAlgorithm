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
		lowcost[i]=G.arc[0][i];//���ڽӾ����0������Ȩֵ�ȼ�������
		adjvex[i]=0;//��ʼ��ȫ����ΪV0���±�
	}
	for(i=1;i<G.numVertexes;i++){
		min=INFINITY;
		j=1;
		k=0;
		//����ȫ������
		while(j<G.numVertexes){
			//�ҳ�lowcost�������Ѵ洢����СȨֵ
			if(lowcost[j]!=0&&lowcost[j]<min){
				min=lowcost[j];
				k=j;//�����ֵ���СȨֵ���±����k,�Դ�ʹ��
			}
			j++;
		}
		//��ӡ��ǰ�������Ȩֵ��С�ı�
		printf("(%d,%d)",adjvex[k],k);
		lowcost[k]=0;//����ǰ�����Ȩֵ����Ϊ0����ʾ�˶����Ѿ�������������һ���ڵ�ı���
	    //�ڽӾ���k���������ȫ������
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