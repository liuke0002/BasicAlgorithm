#include<stdio.h>
int fib(int n){
	if(n==0||n==1){
		return 1;
	}
	return fib(n-1)+fib(n-2);
}

int main(){
	int i;
	for(i=0;i<10;i++){
		printf("%d ",fib(i));
	}
	printf("\n");
	
	return 0;

}