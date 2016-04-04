#include<stdio.h>
void insertSort(int k[],int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		if(k[i]<k[i-1]){
			temp=k[i];
			for(j=i-1;k[j]>temp;j--){
				k[j+1]=k[j];//向后移动
			}
			k[j+1]=temp;//插入相应的位置
		}
	}
}