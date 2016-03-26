#include<stdio.h>
#include<String.h>
//ababaaaba
//011234223
typedef char* String;
void get_next(String T,int *next){

	int i=1,j=0;
	next[1]=0;
	while(i<T[0]){
		if(j==0||T[i]==T[j]){
			i++;
			j++;
			if(T[i]!=T[j]){
				next[i]=j;
			}else{
				next[i]=next[j];
			}
			
		}else{
			j=next[j];//回溯
		}
	}
}
//返回T在S第pos位置之后的index，若不存在，则返回0
int index_kmp(String S,String T,int pos){
	int i=pos ,j=0;
	int next[20];
	get_next(T,next);
	while(i<=S[0]&&j<=T[0]){
		if(j==0||S[i]==T[j]){
			i++;
			j++;
		}else{
			j=next[j];
		}
	}
	if(j>T[0]){
		return i-T[0];
	}
	
	return 0;
}
int main(){

	int next[20],i;
	char T[20]=" ababaaaba";
	T[0]=9;
	get_next(T,next);
	for(i=1;i<10;i++){
		printf("%d\n",next[i]);
	}

	return 0;
}