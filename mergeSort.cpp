#include<stdio.h>
#define MAXSIZE 10
void merging(int *list1,int list1_size,int *list2,int list2_size){
	int temp[MAXSIZE],m;
	int i,j,k;
	i=j=k=0;
	while(i<list1_size&&j<list2_size){
		if(list1[i]<list2[j]){
			temp[k++]=list1[i++];
		}else{
			temp[k++]=list2[j++];
		}
	}
	while(i<list1_size){
		temp[k++]=list1[i++];
	}
	while(j<list2_size){
		temp[k++]=list2[j++];
	}
	for(m=0;m<list1_size+list2_size;m++){
		list1[m]=temp[m];
	}
}
void MergeSort(int k[],int n){
	if(n>1){
		int *list1=k;
		int list1_size=n/2;
		int *list2=k+n/2;
		int list2_size=n-list1_size;
		MergeSort(list1,list1_size);
		MergeSort(list2,list2_size);
		merging(list1,list1_size,list2,list2_size);
	}
}
int main(){
	int a[10]={0,3,2,1,6,5,8,7,9,4},i;
	MergeSort(a,10);
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
}