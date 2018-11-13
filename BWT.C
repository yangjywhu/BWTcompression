/*copyright by Yang Jiayi, Grade 2015*/
#include<stdio.h>
#include <stdlib.h>
#define N 20
int main(void)
{
	char bwt[N][N]={0};
	char temp[N];
	int i,j,k,s,num=0;
	printf("copyright by Yang Jiayi, Grade 2015\n");
	printf("please input the sequence end by\"$\", max=%d\n",N);
	for(i=0;i<N;i++)
	{
		bwt[0][i]=getchar();
		num++;
		if(bwt[0][i]=='$')break;
	}
	for(j=1;j<num;j++)
	{
		for(i=j;i<num;i++)bwt[j][i]=bwt[0][i-j];
		for(i=0;i<j;i++)bwt[j][i]=bwt[0][num+i-j];
	}
	printf("\nѭ�����Ʊ��\n");
	for(j=0;j<num;j++)
	{
		for(i=0;i<num;i++)printf("%c ",bwt[j][i]);
		printf("\n");
	}
	for(i=0;i<num;i++)
	{
		for(j=0;j<num-1-i;j++)
		{
			for(s=0;s<num;)
			{
				if(bwt[j][s]==bwt[j+1][s])s++;
				else if(bwt[j][s]<bwt[j+1][s])break;
				else if(bwt[j][s]>bwt[j+1][s])
				{
					for(k=0;k<num;k++)
					{
				        temp[k]=bwt[j][k];
				        bwt[j][k]=bwt[j+1][k];
				        bwt[j+1][k]=temp[k];
					}
				break;
				}				
			}
		}
	}
	printf("\n������\n");
	for(j=0;j<num;j++)
	{
		for(i=0;i<num;i++)printf("%c ",bwt[j][i]);
		printf("\n");
	}
	printf("\nthe BWT result is:\n");
	for(i=0;i<num;i++)printf("%c",bwt[i][num-1]);
	printf("\n");
	system("pause");
	return 0;
}