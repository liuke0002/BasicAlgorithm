#define MAXVEX 9
#define INFINITY 65535
typedef int Patharc[MAXVEX]; //���ڴ洢���·���±������
typedef int ShortPathTable[MAXVEX];//���ڴ洢���������·����Ȩֵ��
void dijkstra(MGraph G,int C0,Patharc *P,ShortPathTable *D){

	int v,w,k,min;
	int final[MAXVEX];//final[w]=1 ��ʾ�Ѿ����V0��Vw�����·��
	for(v=0;v<G.numVexes;v++){
		final[v]=0;//ȫ�������ʼ��Ϊδ�ҵ����·��
		(*D)[v]=G.src[V0][v];//����v0�������ߵĶ������Ȩֵ
		(*P)[v]=0;//��ʼ��·������PΪ0
	}
	(*D)[v0]=0;//v0��v0��·��Ϊ0
	final[v0]=1;//v0��v0����Ҫ��·��

	for(v=1;v<G.numVexes;v++){
		min=INFINITY;
		for(w=0;w<G.numVexes;w++){
			if(!final[w]&&(*D)[w]<min){
				k=w;
				min=(*D)[w];
			}
		}
		final[k]=1; //��Ŀǰ�ҵ�������Ķ�����1
		for(w=0;w<G.numVexes;w++){
			if(!final[w]&&(min+G.arc[k][w]<(*D)[w])){
				(*D)[w]=min+G.arc[k][w];//�޸ĵ�ǰ·������
				(*p)[w]=k;//���ǰ���ڵ�
			}
		}
	}
}