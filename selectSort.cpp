#include<stdio.h>
void selectSort(int k[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(k[j]<k[min]){
				min=j;
			}
		}
		if(min!=i){
			temp=k[min];
			k[min]=k[i];
			k[i]=temp;
		}
	}
}