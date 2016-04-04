#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//�ݹ���Ҷ���������T���Ƿ����key
//ָ��fָ��T��˫�ף����ʼֵ����ֵΪNULL
//�����ҳɹ�����ָ��pָ�������Ԫ�ؽڵ㣬������TRUE 1
//����pָ�����·���Ϸ��ʵ����һ���ڵ㣬������FALSE -1
int SearchBST(BiTree T,int key,BiTree f,BiTree *p){
	if(!T){//��ѯʧ��
		*p=f;
		return -1;
	}else if(key==T->data){
		*p=T;
		return 1;
	}else if(key<T->data){
		return SearchBST(T->lchild,key,T,p);
	}else{
		return SearchBST(T->rchild,key,T,p);
	}
}
int Delete(BiTree *p){
	BiTree q,s;
	//�����������1.Ҷ�ӽڵ�2.ֻ����������������3.��������������������
	if((*p)->rchild==NULL){
		q=*p;
		*p=(*p)->lchild;
		free(q);
	}else if((*p)->lchild==NULL){
		q=*p;
		*p=(*p)->rchild;
		free(q);
	}else{
		//ֱ��ǰ���滻 
		q=*p;
		s=(*p)->lchild;
		while(s->rchild){
			q=s;
			s=s->rchild;
		}
		(*p)->data=s->data;
		if(q!=*p){
			q->rchild=s->lchild;
		}else{
			q->lchild=s->lchild;
		}	 
		free(s);
	}
	return 1;
}
int deleteBST(BiTree *T,int key){
	if(!*T){
		return -1;
	}else{
		if(key==(*T)->data){
			return Delete(T);
		}else if(key<(*T)->data){
			return deleteBST(&(*T)->lchild,key);
		}else{
			return DeleteBST(&(*T)->rchild,key);
		}
	}
}
int insertBST(BiTree *T,int key){
	BiTree p,s;
	if(-1==SearchBST(*T,key,NULL,&p)){
		s=(BiTree)malloc(sizeof(BiTNode));
		s->data=key;
		s->lchild=s->rchild=NULL;
		if(!p){
			*T=s;//����sΪ�µĸ��ڵ�
		}else if(key<p->data){
			p->lchild=s;
		}else{
			p->rchild=s;
		}
		return 1;
	}else{
		return -1;
	}
}
