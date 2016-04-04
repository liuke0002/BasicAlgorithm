#include<stdio.h>
void shellSort(int k[],int n){
	int i,j,temp;
	int gap=n;
	do{
		gap=gap/3+1;
		for(i=gap;i<n;i++){
			if(k[i]<k[i-gap]){
				temp=k[i];
				for(j=i-gap;k[j]>temp;j-=gap){
					k[j+gap]=k[j];
				}
				k[j+gap]=temp;
			}
		}
	}while(gap>1);
}
int main(){
	int i,a[10]={0,3,2,1,5,6,9,8,7,4};
	shellSort(a,10);
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	return 0;
}