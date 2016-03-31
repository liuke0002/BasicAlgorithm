#define MAXVEX 9
#define INFINITY 65535
typedef int Patharc[MAXVEX]; //用于存储最短路径下标的数组
typedef int ShortPathTable[MAXVEX];//用于存储到各点最短路径的权值和
void dijkstra(MGraph G,int C0,Patharc *P,ShortPathTable *D){

	int v,w,k,min;
	int final[MAXVEX];//final[w]=1 表示已经求得V0到Vw的最短路径
	for(v=0;v<G.numVexes;v++){
		final[v]=0;//全部顶点初始化为未找到最短路径
		(*D)[v]=G.src[V0][v];//将与v0点有连线的顶点加上权值
		(*P)[v]=0;//初始化路径数组P为0
	}
	(*D)[v0]=0;//v0至v0的路径为0
	final[v0]=1;//v0至v0不需要求路径

	for(v=1;v<G.numVexes;v++){
		min=INFINITY;
		for(w=0;w<G.numVexes;w++){
			if(!final[w]&&(*D)[w]<min){
				k=w;
				min=(*D)[w];
			}
		}
		final[k]=1; //将目前找到的最近的顶点置1
		for(w=0;w<G.numVexes;w++){
			if(!final[w]&&(min+G.arc[k][w]<(*D)[w])){
				(*D)[w]=min+G.arc[k][w];//修改当前路径长度
				(*p)[w]=k;//存放前驱节点
			}
		}
	}
}