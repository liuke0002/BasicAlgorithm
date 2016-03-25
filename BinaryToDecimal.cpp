#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define STACH_INIT_SIZE 20
#define STACH_INCRE_SIZE 10
typedef struct  {
	char *base;
	char *top;
	int stackSize;
}sqStack;

void initStack(sqStack *s){//对其进行修改，往往传一个指针
	s->base=(char *)malloc(sizeof(char)*STACH_INIT_SIZE);
	s->top=s->base;
	s->stackSize=STACH_INIT_SIZE;
}
void push(sqStack *s,char e){
	if(s->top-s->base>STACH_INIT_SIZE){
		s->base=(char *)realloc(s->base,sizeof(char)*(s->stackSize+STACH_INCRE_SIZE));
	}
	*(s->top)=e;
	(s->top)++;

}
void pop(sqStack *s,char *e){
	*e=	*--(s->top);
}
int stackSize(sqStack s){
	return (s.top-s.base);
}
int main(){
	char c;
	int sum=0;
	int count=0;
	char e;
	sqStack s;
	initStack(&s);
	scanf("%c",&c);
	while(c!='#'){
		push(&s,c);
		scanf("%c",&c);
	}
	
	while(stackSize(s)!=0){
		pop(&s,&e);
		sum+=(e-48)*pow(2,count++);
	}
	printf("%d\n",sum);
	return 0;
}