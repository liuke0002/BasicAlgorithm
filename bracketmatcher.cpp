#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define INIT_STACK_SIZE 20
#define STACK_INCRE_SIZE 10
typedef struct {
	char *base;
	char *top;
	int stackSize;
}sqStack;
void initStack(sqStack *s){
	s->base=(char *)malloc(sizeof(char)*INIT_STACK_SIZE);
	s->top=s->base;
	s->stackSize=INIT_STACK_SIZE;
}
void push(sqStack *s,char e){
	if(s->top-s->base>INIT_STACK_SIZE){
		s->base=(char *)realloc(s->base,sizeof(char)*(s->stackSize+STACK_INCRE_SIZE));
	}
	*(s->top)=e;
	(s->top)++;
}
void pop(sqStack *s,char *e){
	*e=*--(s->top);
}
char getTop(sqStack *s){
	return *(s->top-1);
}

int stackLen(sqStack *s){
	return (s->top-s->base);
}

int main(){
	char str[20];
	int i;
	char e;
	sqStack s;
	initStack(&s);
	scanf("%s",str);
	for(i=0;i<strlen(str);i++){
		if(str[i]=='('||str[i]=='{'||str[i]=='['){
			push(&s,str[i]);
		}else if(str[i]==')'||str[i]=='}'||str[i]==']'){
			if(stackLen(&s)==0){
				printf("matcher error!\n");
				return 0;
			}else{
				if(str[i]==')'&&getTop(&s)=='('){
					pop(&s,&e);
				}else if(str[i]==']'&&getTop(&s)=='['){
					pop(&s,&e);
				}else if(str[i]=='}'&&getTop(&s)=='{'){
					pop(&s,&e);
				}else{
					printf("matcher error!\n");
					return 0;
				}
			}
		}
	}
	if(stackLen(&s)==0){
		printf("matcher success!\n");
	}
	
	return 0;
}