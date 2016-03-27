#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void postorder(char *pre, char *in, int n) 
{
	char *p; 
	int k;
    for(p=in; p<in+n; p++)  /*在中序中找子树的位置*/
		if(*p == *pre)   
			break;
    k = p - in;
    if(k)  //k非零时
		postorder(pre+1, in, k);//左子树
	if(n-k-1) 
		postorder(pre+k+1, p+1, n-k-1);//右子树
	printf("%c", *p);
}

int main()
{
    char pre[30], in[30];
	int n;

	gets(pre);//先序序列：ABDGCEFH
	gets(in); //中序序列：DGBAECHF
	n = strlen(pre);
     
    postorder(pre, in, n);//后序序列：GDBEHFCA
	return 0;
}     
