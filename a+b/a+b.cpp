#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,d,e,flag1,flag2,flag3=0,sum,c[7],i,j=0;
	scanf("%d%d",&a,&b);
	sum=a+b;
	if(sum==0)
		printf("0");
	for(i=0;;i++)
	{
		d=(int)pow(10,(i+1));
		e=(int)pow(10,i);
		if(e>abs(sum))break;
		c[i]=abs(sum)%d/e;
	}
	if(sum<0)
		printf("-");
	flag1=i%3;
	flag2=i/3; 
	i=i-1;
	if(flag1!=0&&flag2!=0)
	{
		for(;j<flag1;i--,j++)
		{
			printf("%d",c[i]);
		}
		printf(",");
	} 
	for(;i>=0;i--)
	{
		printf("%d",c[i]);
		flag3++;
		if(flag3%3==0&&i!=0)
			printf(",");
	}
	printf("\n");
	return 0;
} 
