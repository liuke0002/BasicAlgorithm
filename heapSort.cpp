#include<stdio.h>
void swap(int k[],int i,int j){
	int temp;
	temp=k[i];
	k[i]=k[j];
	k[j]=temp;
}
void HeapAdjust(int k[],int s,int n){
	int i,temp;
	temp=k[s];
	for(i=2*s;i<=n;i++){
		if(i<n&&k[i]<k[i+1]){
			i++;
		}
		if(temp>=k[i]){
			break;
		}
		k[s]=k[i];
		s=i;
	}
	k[s]=temp;
}
void HeapSort(int k[],int n){
	int i;
	for(i=n/2;i>0;i--){
		HeapAdjust(k,i,n);
	}
	for(i=n;i>1;i--){
		swap(k,1,i);
		HeapAdjust(k,1,i-1);
	}
}
int main(){
	int i,a[11]={-1,1,2,3,6,0,9,8,5,4,7};
	HeapSort(a,10);
	for(i=1;i<=10;i++){
		printf("%d ",a[i]);
	}
	return 0;
}