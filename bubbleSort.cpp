#include<stdio.h>
void BubbleSort1(int k[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(k[i]>k[j]){
				temp=k[j];
				k[j]=k[i];
				k[i]=temp;
			}
		}
	}
}

void BubbleSort2(int k[],int n){
	int i,j,temp,flag;
	flag=1;
	for(i=0;i<n-1&&flag==1;i++){
		flag=0;
		for(j=n-1;j>i;j--){
		
			if(k[j-1]>k[j]){
				temp=k[j];
				k[j]=k[j-1];
				k[j-1]=temp;
				flag=1;
			}
		}
	}
}


int main(){
	int i,a[10]={2,3,4,5,1,9,7,8,6,0};
	BubbleSort2(a,10);
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	return 0;
}