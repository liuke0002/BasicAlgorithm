#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//递归查找二叉排序树T中是否存在key
//指针f指向T的双亲，其初始值调用值为NULL
//若查找成功，则指针p指向该数据元素节点，并返回TRUE 1
//否则p指向查找路径上访问的最后一个节点，并返回FALSE -1
int SearchBST(BiTree T,int key,BiTree f,BiTree *p){
	if(!T){//查询失败
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
	//三种情况处理1.叶子节点2.只有左子树或右子树3.既有左子树又有右子树
	if((*p)->rchild==NULL){
		q=*p;
		*p=(*p)->lchild;
		free(q);
	}else if((*p)->lchild==NULL){
		q=*p;
		*p=(*p)->rchild;
		free(q);
	}else{
		//直接前驱替换 
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
			*T=s;//插入s为新的根节点
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
