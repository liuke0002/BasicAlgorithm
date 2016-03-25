#include<stdio.h>
#include<stdlib.h>
#define CardNumber 13
typedef struct node{
	int data;
	struct node *next;
}node;
node *createLinkList(){
	node *head,*p;
	node *s;
	int i;
	head=(node*)malloc(sizeof(node));
	p=head;
	for(i=0;i<CardNumber;i++){
		s=(node*)malloc(sizeof(node));
		s->data=0;
		p->next=s;
		p=s;
	}
	s->next=head->next;
	free(head);
	return s->next;
}
void margician(node *head){
	node *p;
	int j;
	int countNumber=2;
	p=head;
	p->data=1;
	while(1){
		for(j=0;j<countNumber;j++){
			p=p->next;
			if(p->data!=0){//¸ÃÎ»ÖÃÓÐÅÆ
				p->next;
				j--;
			}
		}
		if(p->data==0){
			p->data=countNumber;
			countNumber++;
			if(countNumber==14){
				break;
			}
		}
	}
}
int main(){
	node *p=createLinkList();
	margician(p);
	int i;
	for(i=1;i<CardNumber;i++){
		printf("%d->",p->data);
		p=p->next;
	}
	printf("%d\n",p->data);
	return 0;
}