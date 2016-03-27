#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void postorder(char *pre, char *in, int n) 
{
	char *p; 
	int k;
    for(p=in; p<in+n; p++)  /*����������������λ��*/
		if(*p == *pre)   
			break;
    k = p - in;
    if(k)  //k����ʱ
		postorder(pre+1, in, k);//������
	if(n-k-1) 
		postorder(pre+k+1, p+1, n-k-1);//������
	printf("%c", *p);
}

int main()
{
    char pre[30], in[30];
	int n;

	gets(pre);//�������У�ABDGCEFH
	gets(in); //�������У�DGBAECHF
	n = strlen(pre);
     
    postorder(pre, in, n);//�������У�GDBEHFCA
	return 0;
}     
