/*copyright by Yang Jiayi, Grade 2015*/
#include<stdio.h>
#include<stdlib.h>
#define N 20
int main(void)
{
	char deb[2][N]={0},res[N]={0};
	int i,j,k,s,temp,num=0;
	int nodollar,nof,nol=0,no;
	
	printf("copyright by Yang Jiayi, Grade 2015\n");
	printf("please input the sequence, end by\"#\", max=%d\n>>>",N);
	
	for(i=0;i<N;i++)
	{
		deb[0][i]=getchar();
		deb[1][i]=deb[0][i];
		if(deb[0][i]=='#')break;
		num++;
	}

	for(i=0;i<num;i++)
		for(j=0;j<num-1-i;j++)
			if(deb[1][j]>deb[1][j+1])
			{
				temp=deb[1][j];
				deb[1][j]=deb[1][j+1];
				deb[1][j+1]=temp;
			}

	printf("\n--ÿ����β--\n");
	printf("F  L  L->F\n----------\n");
	for(i=0;i<num;i++)printf("%c  %c  %c->%c\n",deb[1][i],deb[0][i],deb[0][i],deb[1][i]);

	for(i=0;i<num;i++)
		if(deb[0][i]=='$')
		{
			res[0]=deb[1][i];
			no=i;
		}
	
	/*bugs in this part.
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
			if(deb[1][j]==res[i]){nof=j;break;}
		for(k=0;k<num;k++)
		{
			if(deb[0][k]==res[i])
			{
				if(no-nof==nol)break;
				else nol++;
			}
		}
		res[i+1]=deb[1][k];
		no=k;
	}*/
			


	printf("\nthe deBWT result is:\n");
	for(i=0;i<num;i++)printf("%c",res[i]);
	printf("\n\n");

	system("pause");
	return 0;
}