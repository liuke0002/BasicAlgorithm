#include<stdio.h>
void move(int n,char x,char y,char z){
	if(n==1){
		printf("%c-->%c\n",x,z);
	}else{
		move(n-1,x,z,y);
		printf("%c-->%c\n",x,z);
		move(n-1,y,x,z);
	}

}
int main(){
	int n;
	scanf("%d",&n);
	move(n,'X','Y','Z');
	return 0;
}
