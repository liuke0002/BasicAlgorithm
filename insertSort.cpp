#include<stdio.h>
void insertSort(int k[],int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		if(k[i]<k[i-1]){
			temp=k[i];
			for(j=i-1;k[j]>temp;j--){
				k[j+1]=k[j];//����ƶ�
			}
			k[j+1]=temp;//������Ӧ��λ��
		}
	}
}