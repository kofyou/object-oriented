#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include "myfunction.h" 
using namespace std; 
int fenzi,fenmu;
int ans;//special=0;
int choice;
int casemu0;                           
/*
  ���ܣ���ȡ��Ŀ���� 
*/
char * readFile(char *c,char *ch)
{
	char in[1000];
	strcpy(in,c);
	char temp; 
	int i=0;
	FILE * p;
	if((p=fopen(in,"r"))==NULL)
	printf("cant find");
	while(!feof(p))
	{
		temp=fgetc(p);
		ch[i]=temp;
		i++;
	}
	fclose(p);
	return ch;
}


/*
  ���ܣ�����������ļ��� 
*/
void writeFile(int num,char *a,char *ch,char cans[][100],char input[][100],char shizi[][1000])
{
	int j;
	char out[1000];
	strcpy(out,a);
	FILE * q;
	if((q=fopen(out,"w"))==NULL)
	printf("cant find");
	fputs("��Ŀ������",q);
	fputs(ch,q);
	fputc('\n',q);
	for(j=1;j<=num;j++)
	{
		fputs(shizi[j],q);
		fputs("\n",q);
		fputs(input[j],q);
		fputs("\n",q);
		fputs(cans[j],q);
		fputs("\n\n",q);
	}
	fclose(q);
}


/*
  ���ܣ��˵� 
*/
void Menu()
{
	
	cout<<"---------------------------------------------------------------------------------\n";
	cout<<"*****************Welcome to use the arithmetic device for pupils!****************\n";
	cout<<"*******        1Chinese  2English  3Japanese  4Franch  5German       **********\n";
	cout<<"---------------------------------------------------------------------------------\n\n";
}


/*
  ���ܣ���ͬ�������
*/ 
void lan(int a,int b)
{
	char language[1000]; 
	if(a==1) strcpy(language,"D:\\github\\object-oriented1\\jisuanqi2\\Chinese.txt");
	if(a==2) strcpy(language,"D:\\github\\object-oriented1\\jisuanqi2\\English.txt");
	if(a==3) strcpy(language,"D:\\github\\object-oriented1\\jisuanqi2\\Japanese.txt");
	if(a==4) strcpy(language,"D:\\github\\object-oriented1\\jisuanqi2\\Franch.txt");
	if(a==5) strcpy(language,"D:\\github\\object-oriented1\\jisuanqi2\\German.txt");
	int line=1;
	FILE * p;
	if((p=fopen(language,"r"))==NULL)printf("fuck\n");
	char StrLine[100];
	while(!feof(p))
	{
		if(line==b)
		{
			fgets(StrLine,100,p);
			cout<<"\n"<<StrLine<<endl;
		}
		fgets(StrLine,100,p);
		line++;
	}
	fclose(p);
}


/*
  ���ܣ����������ʽ 
*/ 
void randomNumber(int *n)
{
	srand(time(NULL));
	n[1]=rand()%11;n[2]=rand()%11;n[3]=rand()%11;n[4]=rand()%11;
}


/*
  ���ܣ������������� 
*/ 
void randomOperation(int *op)
{
	srand(time(NULL));
	op[1]=rand()%4;op[2]=rand()%4;op[3]=rand()%4;	
} 


/*
  ���ܣ�������ʽ 
*/
void generateExpression(int i,int circum,int *n,int *op,char shizi[][1000])
{
	
	char operation[4]={'+','-','*','/'};
	switch(circum) 
	{
		case 0:
		{
			cout<<n[1]<<operation[op[1]]<<n[2]<<operation[op[2]]<<n[3]<<operation[op[3]]<<n[4]<<'='; 
			sprintf(shizi[i],"%d%c%d%c%d%c%d=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
			break;  	
		}
		case 1:
		{
			cout<<'('<<n[1]<<operation[op[1]]<<n[2]<<')'<<operation[op[2]]<<n[3]<<operation[op[3]]<<n[4]<<'='; 
			sprintf(shizi[i],"(%d%c%d)%c%d%c%d=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
			break;
		}
		case 2:
		{
			cout<<n[1]<<operation[op[1]]<<'('<<n[2]<<operation[op[2]]<<n[3]<<')'<<operation[op[3]]<<n[4]<<'='; 
			sprintf(shizi[i],"%d%c(%d%c%d)%c%d=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
			break;
		}
		case 3:
		{	
			cout<<n[1]<<operation[op[1]]<<n[2]<<operation[op[2]]<<'('<<n[3]<<operation[op[3]]<<n[4]<<')'<<'='; 
			sprintf(shizi[i],"%d%c%d%c(%d%c%d)=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
			break;
		}
		case 4:
		{  
			cout<<'('<<n[1]<<operation[op[1]]<<n[2]<<operation[op[2]]<<n[3]<<')'<<operation[op[3]]<<n[4]<<'='; 
			sprintf(shizi[i],"(%d%c%d%c%d)%c%d=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
			break;
		}
		case 5:
		{ 
			cout<<n[1]<<operation[op[1]]<<'('<<n[2]<<operation[op[2]]<<n[3]<<operation[op[3]]<<n[4]<<')'<<'='; 
			sprintf(shizi[i],"%d%c(%d%c%d%c%d)=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
		}
	}
}


/*
  ���ܣ������ 
*/ 
int calculateResult(int *n,int *op,char cans[][100],int i)
{
	int circum;  
	srand(time(NULL));
	circum=rand()%5;
	int chengchu1(int n[5],int op[4]);  
	int chengchu2(int n[5],int op[4]);  
	int chengchu3(int n[5],int op[4]);  
	int chengchu4(int n[5],int op[4]);  
	int chengchu5(int n[5],int op[4]);  
	int chengchu6(int n[5],int op[4]); 
	//casemu0=0; 
	switch(circum)
	{
		case 0:
		{
			ans=chengchu1(n,op);         
			break;
		}
		case 1:
		{
			ans=chengchu2(n,op);
			break;
		}
		case 2:
		{
			ans=chengchu3(n,op);  
			break;
		}
		case 3:
		{
			ans=chengchu4(n,op);  
			break;
		}
		case 4:
		{
			ans=chengchu5(n,op);
			break;
		}
		case 5:
		{
			ans=chengchu6(n,op); 
		}
		
	}
		if(ans==10002)
		{
			casemu0=1;
		}
		if(ans!=10002&&ans!=10001)
		{
			sprintf(cans[i],"%d",ans);	
		}
		if(ans==10001)
		{
			sprintf(cans[i],"%d/%d",fenzi,fenmu);
		}
		return circum;
		
}



/*
  ���ܣ��û�����𰸲��ж�
*/ 
int scan(char input[][100],char cans[][100],int i)
{
	void lan(int a,int b);
	int userans=10003;
	int userfenzi=10003;                            
	int userfenmu; 
	char chuhao;  
	scanf("%s",input[i]);
	if(strcmp(input[i],cans[i])==0)
	{
		lan(choice,2);
		return 1;
	}
	else if(input[i][0]=='e')
	{
		return 3;
	}
	else
	{
		lan(choice,3);
		printf("%s\n",cans[i]);
		return 0;
	}
	/*if(ans==10001)                                //change       ������û�з������� �в�ͬ���û�����ͳ������ 
   	{
   		scanf("%d%c",&userfenzi,&chuhao);
   		if(userfenzi==10003)
   		{
   			if(getchar()=='e')
   			return 3;
		}
   		else if(chuhao=='/')
		{
			scanf("%d",&userfenmu); 
   			if(userfenzi==fenzi&&userfenmu==fenmu)
   			{
				lan(choice,2);
				return 1;
			}
			else
			{
				lan(choice,3); 
   				printf("%d/%d\n",fenzi,fenmu);
				return 0;
			}
		}
		else
   		{
   			lan(choice,3);
			printf(" %d/%d\n",fenzi,fenmu);
   			return 0;
   		}
	}
	else if(ans==10002)
	{
		return 0;
	}
	else
	{  
		scanf("%d%c",&userans,&chuhao);
		if(userans==10003)
		{
			if(getchar()=='e')
			return 3;
		}
		else if(chuhao=='\n')
		{
			if(userans==ans)
			{
			lan(choice,2);
			return 1;
			}
			else
			{
				lan(choice,3);	
				printf(" %d\n",ans);
				return 0;
   			}
   	    }
   	    else
   	    {
   	    	scanf("%d",&userfenmu);
   	    	lan(choice,3);
			printf("%d\n",ans);
   	    	return 0;
		}
   	}*/
} 



/*
������������
*/ 
int chengchu1(int n[5],int op[4])          
{
	int fenshuhuajian();
	int flag=0;
	if(op[1]==0)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]+n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]+n[3]-n[4];
			    if(op[3]==2) ans=n[1]+n[2]+(n[3]*n[4]);
			    if(op[3]==3)
			    {
			    	fenzi=n[3]+(n[1]+n[2])*n[4];       
			    	fenmu=n[4];
			    	flag=fenshuhuajian();                //���������� 
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]+n[2]-n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]-n[3]-n[4];
			    if(op[3]==2) ans=n[1]+n[2]-(n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=(n[1]+n[2])*n[4]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]+(n[2]*n[3])+n[4];
			    if(op[3]==1) ans=n[1]+(n[2]*n[3])-n[4];
			    if(op[3]==2) ans=n[1]+(n[2]*n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4]+n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=(n[1]+n[4])*n[3]+n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=(n[1]-n[4])*n[3]+n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]*n[3]+n[2]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3]*n[4]+n[2];
			    	fenmu=n[3]*n[4];
			    	flag=fenshuhuajian();
				}
		}
	}
	    	if(op[1]==1)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]-n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]-n[2]+n[3]-n[4];
			    if(op[3]==2) ans=n[1]-n[2]+(n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=(n[1]-n[2])*n[4]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]-n[2]-n[3]+n[4];
			    if(op[3]==1) ans=n[1]-n[2]-n[3]-n[4];
			    if(op[3]==2) ans=n[1]-n[2]-(n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=(n[1]-n[2])*n[4]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]-(n[2]*n[3])+n[4];
			    if(op[3]==1) ans=n[1]-(n[2]*n[3])-n[4];
			    if(op[3]==2) ans=n[1]-(n[2]*n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4]-n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=(n[1]+n[4])*n[3]-n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=(n[1]-n[4])*n[3]-n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]*n[3]-n[2]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3]*n[4]-n[2];
			    	fenmu=n[3]*n[4];
			    	flag=fenshuhuajian();
				}
		}
	}
			if(op[1]==2)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]*n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]*n[2]+n[3]-n[4];
			    if(op[3]==2) ans=(n[1]*n[2])+(n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[2]*n[4]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=(n[1]*n[2])-n[3]+n[4];
			    if(op[3]==1) ans=(n[1]*n[2])-n[3]-n[4];
			    if(op[3]==2) ans=(n[1]*n[2])-(n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[2]*n[4]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=(n[1]*n[2]*n[3])+n[4];
			    if(op[3]==1) ans=(n[1]*n[2]*n[3])-n[4];
			    if(op[3]==2) ans=n[1]*n[2]*n[3]*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]*n[2]+n[3]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]*n[2]-n[3]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]*n[2]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				} 
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[2];
			    	fenmu=n[3]*n[4];
			    	flag=fenshuhuajian();
				}
		}
	}
		if(op[1]==3)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=(n[3]+n[4])*n[2]+n[1];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=(n[3]-n[4])*n[2]+n[1];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[2]*n[3]*n[4]+n[1];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4]+n[2]*n[3];
			    	fenmu=n[2]*n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=(n[4]-n[3])*n[2]+n[1];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=(-n[3]-n[4])*n[2]+n[1];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]-n[2]*n[3]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4]-n[2]*n[3];
			    	fenmu=n[2]*n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[2]*n[4]+n[1]*n[3];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]*n[3]-n[2]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]*n[3]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3];
			    	fenmu=n[2]*n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0)
			    {
			    	fenzi=n[1]+n[2]*n[3]*n[4];
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]-n[2]*n[3]*n[4];
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]*n[4];
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]*n[3]*n[4];
			    	flag=fenshuhuajian();
				}
		}
	}	
	if(flag==1)               //�����Ƿ��з�������  ���ز�ֵͬ 
	return 10001; 
	if(flag==0)
	return ans;
	if(flag==2)
	return 10002;
}


int chengchu2( int n[5],int op[4])        
{
	int fenshuhuajian();
	int flag=0;	
	if(op[1]==0)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]+n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]+n[3]-n[4];
			    if(op[3]==2) ans=n[1]+n[2]+n[3]*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[3]+(n[1]+n[2])*n[4];       
			    	fenmu=n[4];
			    	flag=fenshuhuajian();  
				} 
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]+n[2]-n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]-n[3]-n[4];
			    if(op[3]==2) ans=n[1]+n[2]-n[3]*n[4];
			    if(op[3]==3) 
			    {
					fenzi=(n[1]+n[2])*n[4]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				} 
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=(n[1]+n[2])*n[3]+n[4];
			    if(op[3]==1) ans=(n[1]+n[2])*n[3]-n[4];
			    if(op[3]==2) ans=(n[1]+n[2])*n[3]*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=(n[1]+n[2])*n[3];
					fenmu=n[4];
					flag=fenshuhuajian(); 
			    }
		}
			if(op[2]==3)
		{
			    if(op[3]==0)
			    {
			    	fenzi=n[4]*n[3]+n[1]+n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) 
			     {
			    	fenzi=n[1]+n[2]-(n[3]*n[4]);
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) 
			     {
			    	fenzi=(n[1]+n[2])*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3)
			     {
			    	fenzi=n[1]+n[2];
			    	fenmu=n[3]*n[4];
			    	flag=fenshuhuajian();
			    }
		}
	}
	    	if(op[1]==1)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]-n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]-n[2]+n[3]-n[4];
			    if(op[3]==2) ans=n[1]-n[2]+n[3]*n[4];
			    if(op[3]==3) 
			     {
			    	fenzi=(n[1]-n[2])*n[4]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]-n[2]-n[3]+n[4];
			    if(op[3]==1) ans=n[1]-n[2]-n[3]-n[4];
			    if(op[3]==2) ans=n[1]-n[2]-n[3]*n[4];
			    if(op[3]==3) 
			     {
			    	fenzi=(n[1]-n[2])*n[4]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=(n[1]-n[2])*n[3]+n[4];
			    if(op[3]==1) ans=(n[1]-n[2])*n[3]-n[4];
			    if(op[3]==2) ans=(n[1]-n[2])*n[3]*n[4];
			    if(op[3]==3) 
			     {
			    	fenzi=(n[1]-n[2])*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			     {
			    	fenzi=n[4]*n[3]+n[1]-n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) 
			     {
			    	fenzi=n[1]-n[2]-(n[3]*n[4]);
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) 
			     {
			    	fenzi=(n[1]-n[2])*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3) 
			     {
			    	fenzi=n[1]-n[2];
			    	fenmu=n[3]*n[4];
			    	flag=fenshuhuajian();
			    }
		}
	}
			if(op[1]==2)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]*n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]*n[2]+n[3]-n[4];
			    if(op[3]==2) ans=n[1]*n[2]+n[3]*n[4];
			    if(op[3]==3) 
			     {
			    	fenzi=n[1]*n[2]*n[4]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]*n[2]-n[3]+n[4];
			    if(op[3]==1) ans=n[1]*n[2]-n[3]-n[4];
			    if(op[3]==2) ans=n[1]*n[2]-n[3]*n[4];
			    if(op[3]==3) 
			     {
			    	fenzi=n[1]*n[2]*n[4]-n[3];
			    	fenmu=n[4];
					flag=fenshuhuajian();
			    }
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]*n[2]*n[3]+n[4];
			    if(op[3]==1) ans=n[1]*n[2]*n[3]-n[4];
			    if(op[3]==2) ans=n[1]*n[2]*n[3]*n[4];
			    if(op[3]==3) 
			     {
			    	fenzi=n[1]*n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==3)
		{
			    if(op[3]==0)
			     {
			    	fenzi=n[4]*n[3]+n[1]*n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) 
			     {
			    	fenzi=n[1]*n[2]-n[3]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) 
			     {
			    	fenzi=n[1]*n[2]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3) 
			     {
			    	fenzi=n[1]*n[2];
			    	fenmu=n[3]*n[4];
			    	flag=fenshuhuajian();
			    }
		}
	}
		if(op[1]==3)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) 
			     {
			    	fenzi=n[1]+(n[3]+n[4])*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1)
			     {
			    	fenzi=n[1]+(n[3]-n[4])*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) 
			     {
			    	fenzi=n[1]+n[2]*n[3]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3)
			     {
			    	fenzi=n[1]*n[4]+n[3]*n[2];
			    	fenmu=n[2]*n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==1)
		{
			    if(op[3]==0)
			     {
			    	fenzi=n[1]-n[3]*n[2]+n[4]*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1)
			     {
			    	fenzi=n[1]-n[3]*n[2]-n[4]*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) 
			     {
			    	fenzi=n[1]-n[3]*n[4]*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3)
			     {
			    	fenzi=n[1]*n[4]-n[3]*n[2];
			    	fenmu=n[2]*n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==2)
		{
			    if(op[3]==0) 
			     {
			    	fenzi=n[1]*n[3]+n[4]*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) 
			     {
			    	fenzi=n[1]*n[3]-n[4]*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) 
			     {
			    	fenzi=n[1]*n[3]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3) 
			     {
			    	fenzi=n[1]*n[3];
			    	fenmu=n[2]*n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==3)
		{
			    if(op[3]==0)
			     {
			    	fenzi=n[1]+n[4]*n[2]*n[3];
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) 
			     {
			    	fenzi=n[1]-n[4]*n[2]*n[3]; 
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2)
			     {
			    	fenzi=n[1]*n[4];
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3) ans=n[1]/n[2]/n[3]/n[4];
			     {
			    	fenzi=n[1];
			    	fenmu=n[2]*n[3]*n[4];
			    	flag=fenshuhuajian();
			    }
		}
	}	
	if(flag==1)             
	return 10001; 
	if(flag==0)
	return ans;
	if(flag==2)
	return 10002;	
}


int chengchu3( int n[5],int op[4])        
{
	int fenshuhuajian();
	int flag=0;	
	if(op[1]==0)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]+(n[2]+n[3])+n[4];
			    if(op[3]==1) ans=n[1]+(n[2]+n[3])-n[4];
			    if(op[3]==2) ans=n[1]+(n[2]+n[3])*n[4];
			    if(op[3]==3) ans=n[1]+(n[2]+n[3])/n[4];
			     {
			    	fenzi=n[2]+n[3]+n[1]*n[4]; 
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]+(n[2]-n[3])+n[4];
			    if(op[3]==1) ans=n[1]+(n[2]-n[3])-n[4];
			    if(op[3]==2) ans=n[1]+(n[2]-n[3])*n[4];
			    if(op[3]==3) ans=n[1]+(n[2]-n[3])/n[4];
			     {
			    	fenzi=n[1]*n[4]+n[2]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]+(n[2]*n[3])+n[4];
			    if(op[3]==1) ans=n[1]+(n[2]*n[3])-n[4];
			    if(op[3]==2) ans=n[1]+(n[2]*n[3])*n[4];
			    if(op[3]==3) ans=n[1]+(n[2]*n[3])/n[4];
			     {
			    	fenzi=n[1]*n[4]+n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==3)
		{
			    if(op[3]==0) ans=n[1]+(n[2]/n[3])+n[4];
			     {
			    	fenzi=(n[1]+n[4])*n[3]+n[2]; 
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) ans=n[1]+(n[2]/n[3])-n[4];
			     {
			    	fenzi=(n[1]-n[4])*n[3]+n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) ans=n[1]+(n[2]/n[3])*n[4];
			     {
			    	fenzi=n[1]*n[3]+n[2]*n[4]; 
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3) ans=n[1]+(n[2]/n[3])/n[4];
			     {
			    	fenzi=n[1]*n[3]*n[4]+n[2];
			    	fenmu=n[3]*n[4];
			    	flag=fenshuhuajian();
			    }
		}
	}
	    	if(op[1]==1)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]-(n[2]+n[3])+n[4];
			    if(op[3]==1) ans=n[1]-(n[2]+n[3])-n[4];
			    if(op[3]==2) ans=n[1]-(n[2]+n[3])*n[4];
			    if(op[3]==3) ans=n[1]-(n[2]+n[3])/n[4];
			     {
			    	fenzi=n[1]*n[4]-n[2]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]-(n[2]-n[3])+n[4];
			    if(op[3]==1) ans=n[1]-(n[2]-n[3])-n[4];
			    if(op[3]==2) ans=n[1]-(n[2]-n[3])*n[4];
			    if(op[3]==3) ans=n[1]-(n[2]-n[3])/n[4];
			     {
			    	fenzi=n[1]*n[4]-n[2]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]-(n[2]*n[3])+n[4];
			    if(op[3]==1) ans=n[1]-(n[2]*n[3])-n[4];
			    if(op[3]==2) ans=n[1]-(n[2]*n[3])*n[4];
			    if(op[3]==3) ans=n[1]-(n[2]*n[3])/n[4];
			     {
			    	fenzi=n[1]*n[4]+n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==3)
		{
			    if(op[3]==0) ans=n[1]-(n[2]/n[3])+n[4];
			     {
			    	fenzi=(n[1]+n[4])*n[3]-n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) ans=n[1]-(n[2]/n[3])-n[4];
			     {
			    	fenzi=(n[1]-n[4])*n[3]-n[2]; 
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) ans=n[1]-(n[2]/n[3])*n[4];
			     {
			    	fenzi=n[1]*n[3]-n[2]*n[4];
			    	fenmu=n[3]; 
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3) ans=n[1]-(n[2]/n[3])/n[4];
			     {
			    	fenzi=n[1]*n[3]*n[4]-n[2];
			    	fenmu=n[3]*n[4];
			    	flag=fenshuhuajian();
			    }
		}
	}
			if(op[1]==2)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]*(n[2]+n[3])+n[4];
			    if(op[3]==1) ans=n[1]*(n[2]+n[3])-n[4];
			    if(op[3]==2) ans=n[1]*(n[2]+n[3])*n[4];
			    if(op[3]==3) ans=n[1]*(n[2]+n[3])/n[4];
			     {
			    	fenzi=n[1]*(n[2]+n[3]);
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]*(n[2]-n[3])+n[4];
			    if(op[3]==1) ans=n[1]*(n[2]-n[3])-n[4];
			    if(op[3]==2) ans=n[1]*(n[2]-n[3])*n[4];
			    if(op[3]==3) ans=n[1]*(n[2]-n[3])/n[4];
			     {
			    	fenzi=n[1]*(n[2]-n[3]);
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]*(n[2]*n[3])+n[4];
			    if(op[3]==1) ans=n[1]*(n[2]*n[3])-n[4];
			    if(op[3]==2) ans=n[1]*(n[2]*n[3])*n[4];
			    if(op[3]==3) ans=n[1]*(n[2]*n[3])/n[4];
			     {
			    	fenzi=n[1]*n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==3)
		{
			    if(op[3]==0) ans=n[1]*(n[2]/n[3])+n[4];
			     {
			    	fenzi=n[1]*n[2]+n[4]*n[3];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) ans=n[1]*(n[2]/n[3])-n[4];
			     {
			    	fenzi=n[1]*n[2]-n[4]*n[3];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) ans=n[1]*(n[2]/n[3])*n[4];
			     {
			    	fenzi=n[1]*n[2]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3) ans=n[1]*(n[2]/n[3])/n[4];
			     {
			    	fenzi=n[1]*n[2];
			    	fenmu=n[3]*n[4];
			    	flag=fenshuhuajian();
			    }
		}
	}
		if(op[1]==3)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]/(n[2]+n[3])+n[4];
			     {
			    	fenzi=n[1]+(n[2]+n[3])*n[4];
			    	fenmu=n[2]+n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) ans=n[1]/(n[2]+n[3])-n[4];
			     {
			    	fenzi=n[1]+(n[2]+n[3])*n[4];
			    	fenmu=n[2]+n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) ans=n[1]/(n[2]+n[3])*n[4];
			     {
			    	fenzi=n[1]*n[4];
			    	fenmu=n[2]+n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3) ans=n[1]/(n[2]+n[3])/n[4];
			     {
			    	fenzi=n[1];
			    	fenmu=(n[2]+n[3])*n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]/(n[2]-n[3])+n[4];
			     {
			    	fenzi=n[1]+(n[2]-n[3])*n[4];
			    	fenmu=n[2]-n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) ans=n[1]/(n[2]-n[3])-n[4];
			     {
			    	fenzi=n[1]-(n[2]-n[3])*n[4];
			    	fenmu=n[2]-n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) ans=n[1]/(n[2]-n[3])*n[4];
			     {
			    	fenzi=n[1]*n[4];
			    	fenmu=n[2]-n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3) ans=n[1]/(n[2]-n[3])/n[4];
			     {
			    	fenzi=n[1];
			    	fenmu=(n[2]-n[3])*n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]/(n[2]*n[3])+n[4];
			     {
			    	fenzi=n[1]+n[4]*n[2]*n[3]; 
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) ans=n[1]/(n[2]*n[3])-n[4];
			     {
			    	fenzi=n[1]-n[4]*n[2]*n[3];
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) ans=n[1]/(n[2]*n[3])*n[4];
			     {
			    	fenzi=n[1]*n[4];
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3) ans=n[1]/(n[2]*n[3])/n[4];
			     {
			    	fenzi=n[1];
			    	fenmu=n[2]*n[3]*n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==3)
		{
			    if(op[3]==0) ans=n[1]/(n[2]/n[3])+n[4];
			     {
			    	fenzi=n[1]*n[3]+n[4]*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) ans=n[1]/(n[2]/n[3])-n[4];
			     {
			    	fenzi=n[1]*n[3]-n[4]*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) ans=n[1]/(n[2]/n[3])*n[4];
			     {
			    	fenzi=n[1]*n[3]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3) ans=n[1]/(n[2]/n[3])/n[4];
			     {
			    	fenzi=n[1]*n[3];
			    	fenmu=n[2]*n[4]; 
			    	flag=fenshuhuajian();
			    }
		}
	}	
	if(flag==1)             
	return 10001; 
	if(flag==0)
	return ans;
	if(flag==2)
	return 10002;	
}


int chengchu4( int n[5],int op[4])     
{
	int fenshuhuajian();
	int flag=0;	
	if(op[1]==0)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]+n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]+n[3]-n[4];
			    if(op[3]==2) ans=n[1]+n[2]+n[3]*n[4];
			    if(op[3]==3)
			    {
			    	fenzi=n[3]+(n[1]+n[2])*n[4];       
			    	fenmu=n[4];
			    	flag=fenshuhuajian();      
				} 
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]+n[2]-(n[3]+n[4]);
			    if(op[3]==1) ans=n[1]+n[2]-(n[3]-n[4]);
			    if(op[3]==2) ans=n[1]+n[2]-n[3]*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=(n[1]+n[2])*n[4]-n[3];       
			    	fenmu=n[4];
			    	flag=fenshuhuajian();      
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]+n[2]*(n[3]+n[4]);
			    if(op[3]==1) ans=n[1]+n[2]*(n[3]-n[4]);
			    if(op[3]==2) ans=n[1]+n[2]*n[3]*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4]+n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0)
			    {
			    	fenzi=n[1]*(n[3]+n[4])+n[2];
			    	fenmu=n[4]+n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1)
			    {
			    	fenzi=n[1]*(n[3]-n[4])+n[2];
			    	fenmu=n[3]-n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]*(n[3]*n[4])+n[2];
			    	fenmu=n[4]*n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3]+n[2]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
		}
	}
	    	if(op[1]==1)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]-n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]-n[2]+n[3]-n[4];
			    if(op[3]==2) ans=n[1]-n[2]+n[3]*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=(n[1]-n[2])*n[4]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]-n[2]-(n[3]+n[4]);
			    if(op[3]==1) ans=n[1]-n[2]-(n[3]-n[4]);
			    if(op[3]==2) ans=n[1]-n[2]-n[3]*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=(n[1]-n[2])*n[4]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]-n[2]*(n[3]+n[4]);
			    if(op[3]==1) ans=n[1]-n[2]*(n[3]-n[4]);
			    if(op[3]==2) ans=n[1]-n[2]*n[3]*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4]-n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]*(n[3]+n[4])-n[2];
			    	fenmu=n[4]+n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]*(n[3]-n[4])-n[2];
			    	fenmu=n[3]-n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]*n[3]*n[4]-n[2];
			    	fenmu=n[4]*n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3]-n[2]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
		}
	}
			if(op[1]==2)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]*n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]*n[2]+n[3]-n[4];
			    if(op[3]==2) ans=n[1]*n[2]+n[3]*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[2]*n[4]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]*n[2]-(n[3]+n[4]);
			    if(op[3]==1) ans=n[1]*n[2]-(n[3]-n[4]);
			    if(op[3]==2) ans=n[1]*n[2]-(n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4]*n[2]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]*n[2]*(n[3]+n[4]);
			    if(op[3]==1) ans=n[1]*n[2]*(n[3]-n[4]);
			    if(op[3]==2) ans=n[1]*n[2]*(n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]*n[2];
			    	fenmu=n[4]+n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]*n[2];
			    	fenmu=n[3]-n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
					fenzi=n[1]*n[2];
			    	fenmu=n[4]*n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[2]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
		}
	}
		if(op[1]==3)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=(n[3]+n[4])*n[2]+n[1];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=(n[3]-n[4])*n[2]+n[1];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[3]*n[4]*n[2]+n[1];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4]+n[2]*n[3];
			    	fenmu=n[4]*n[2];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]-n[2]*(n[3]+n[4]);
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]-n[2]*(n[3]-n[4]);
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]-n[2]*n[3]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4]-n[2]*n[3];
			    	fenmu=n[4]*n[2];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]*(n[3]+n[4]);
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]*(n[3]-n[4]);
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]*n[3]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				} 
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3];
			    	fenmu=n[4]*n[2];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]*(n[3]+n[4]);
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]*(n[3]-n[4]);
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]*n[3]*n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3)
			    {
			    	fenzi=n[1]*n[4];
			    	fenmu=n[3]*n[2];
			    	flag=fenshuhuajian();
				}
		}
	}	
	if(flag==1)             
	return 10001; 
	if(flag==0)
	return ans;
	if(flag==2)
	return 10002;	
}


int chengchu5( int n[5],int op[4])     
{
	int fenshuhuajian();
	int flag=0;	
	if(op[1]==0)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]+n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]+n[3]-n[4];
			    if(op[3]==2) ans=(n[1]+n[2]+n[3])*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]+n[2]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]+n[2]-n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]-n[3]-n[4];
			    if(op[3]==2) ans=(n[1]+n[2]-n[3])*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]+n[2]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]+n[2]*n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]*n[3]-n[4];
			    if(op[3]==2) ans=(n[1]+n[2]*n[3])*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]+n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]*n[3]+n[2+n[3]*n[4]];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]*n[3]+n[2]-n[3]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=(n[1]*n[3]+n[2])*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3]+n[2];
			    	fenmu=n[4]*n[3];
			    	flag=fenshuhuajian();
				} 
		}
	}
	    	if(op[1]==1)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]-n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]-n[2]+n[3]-n[4];
			    if(op[3]==2) ans=(n[1]-n[2]+n[3])*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]-n[2]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]-n[2]-n[3]+n[4];
			    if(op[3]==1) ans=n[1]-n[2]-n[3]-n[4];
			    if(op[3]==2) ans=(n[1]-n[2]-n[3])*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]-n[2]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]-n[2]*n[3]+n[4];
			    if(op[3]==1) ans=n[1]-n[2]*n[3]-n[4];
			    if(op[3]==2) ans=(n[1]-n[2]*n[3])*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]-n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				} 
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]*n[3]-n[2]+n[3]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]*n[3]-n[2]-n[3]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=(n[1]*n[3]-n[2])*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3]-n[2];
			    	fenmu=n[4]*n[3];
			    	flag=fenshuhuajian();
				}
		}
	}
			if(op[1]==2)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]*n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]*n[2]+n[3]-n[4];
			    if(op[3]==2) ans=(n[1]*n[2]+n[3])*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[2]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]*n[2]-n[3]+n[4];
			    if(op[3]==1) ans=n[1]*n[2]-n[3]-n[4];
			    if(op[3]==2) ans=(n[1]*n[2]-n[3])*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[2]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]*n[2]*n[3]+n[4];
			    if(op[3]==1) ans=n[1]*n[2]*n[3]-n[4];
			    if(op[3]==2) ans=n[1]*n[2]*n[3]*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]*n[2]+n[3]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1)
			    {
			    	fenzi=n[1]*n[2]-n[3]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2)
			    {
			    	fenzi=n[1]*n[2]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[2];
			    	fenmu=n[4]*n[3];
			    	flag=fenshuhuajian();
				}
		}
	}
		if(op[1]==3)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]+n[2]*n[3]+n[2]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1)
			    {
			    	fenzi=n[1]+n[2]*n[3]-n[2]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=(n[1]+n[2]*n[3])*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]+n[2]*n[3];
			    	fenmu=n[4]*n[2];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]+(n[4]-n[3])*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]-(n[3]+n[4])*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=(n[1]-n[2]*n[3])*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]-n[2]*n[3];
			    	fenmu=n[2]*n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]*n[3]+n[2]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]*n[3]-n[2]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]*n[3]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3];
			    	fenmu=n[2]*n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]+n[2]*n[3]*n[4];
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]-n[2]*n[3]*n[4];
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]*n[4];
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]*n[3]*n[4];
			    	flag=fenshuhuajian();
				}
		}
	}	
	if(flag==1)             
	return 10001; 
	if(flag==0)
	return ans;	
	if(flag==2)
	return 10002;
}


int chengchu6( int n[5],int op[4])        
{
	int fenshuhuajian();
	int flag=0;	
	if(op[1]==0)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]+n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]+n[3]-n[4];
			    if(op[3]==2) ans=n[1]+n[2]+n[3]*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[3]+(n[1]+n[2])*n[4];       
			    	fenmu=n[4];
			    	flag=fenshuhuajian();  
				} 
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]+n[2]-n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]-n[3]-n[4];
			    if(op[3]==2) ans=n[1]+n[2]-n[3]*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=(n[1]+n[2])*n[4]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]+n[2]*n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]*n[3]-n[4];
			    if(op[3]==2) ans=n[1]+n[2]*n[3]*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4]+n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=(n[1]+n[4])*n[3]+n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=(n[1]-n[4])*n[3]+n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]*n[3]+n[2]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			   		fenzi=n[1]*n[3]*n[4]+n[2];
			    	fenmu=n[3]*n[4];
			    	flag=fenshuhuajian();
				}
		}
	}
	    	if(op[1]==1)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]-(n[2]+n[3]+n[4]);
			    if(op[3]==1) ans=n[1]-(n[2]+n[3]-n[4]);
			    if(op[3]==2) ans=n[1]-(n[2]+n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=(n[1]-n[2])*n[4]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]-(n[2]-n[3]+n[4]);
			    if(op[3]==1) ans=n[1]-(n[2]-n[3]-n[4]);
			    if(op[3]==2) ans=n[1]-(n[2]-n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=(n[1]-n[2])*n[4]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]-(n[2]*n[3]+n[4]);
			    if(op[3]==1) ans=n[1]-(n[2]*n[3]-n[4]);
			    if(op[3]==2) ans=n[1]-(n[2]*n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4]-n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=(n[1]-n[4])*n[3]-n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=(n[1]+n[4])*n[3]-n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]*n[3]-n[2]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3]*n[4]-n[2];
			    	fenmu=n[3]*n[4];
			    	flag=fenshuhuajian();
				}
		}
	}
			if(op[1]==2)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]*(n[2]+n[3]+n[4]);
			    if(op[3]==1) ans=n[1]*(n[2]+n[3]-n[4]);
			    if(op[3]==2) ans=n[1]*(n[2]+n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*(n[2]*n[4]+n[3]);
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]*(n[2]-n[3]+n[4]);
			    if(op[3]==1) ans=n[1]*(n[2]-n[3]-n[4]);
			    if(op[3]==2) ans=n[1]*(n[2]-n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*(n[2]*n[4]-n[3]);
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]*(n[2]*n[3]+n[4]);
			    if(op[3]==1) ans=n[1]*(n[2]*n[3]-n[4]);
			    if(op[3]==2) ans=n[1]*(n[2]*n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3]*n[2];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]*(n[2]+n[3]*n[4]);
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1)
			    {
			    	fenzi=n[1]*(n[2]-n[3]*n[4]);
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]*n[2]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[2];
			    	fenmu=n[3]*n[4];
			    	flag=fenshuhuajian();
				}
		}
	}
		if(op[1]==3)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]+n[3]+n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
					fenzi=n[1];
			    	fenmu=n[2]+n[3]-n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]+n[3]*n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4];
			    	fenmu=n[3]+n[2]*n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]-n[3]+n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]-n[3]-n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]-n[3]*n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4];
			    	fenmu=n[2]*n[4]-n[3];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]*n[3]+n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]*n[3]-n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]*n[3]*n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3)
			    {
			    	fenzi=n[1]*n[4];
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]*n[3];
			    	fenmu=n[2]+n[3]*n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]*n[3];
			    	fenmu=n[2]-n[3]*n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2)
			    {
			    	fenzi=n[1]*n[3];
			    	fenmu=n[2]*n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
		}
	}	
	if(flag==1)             
	return 10001; 
	if(flag==0)
	return ans;
	if(flag==2)
	return 10002;	
}



/*
����������
*/
int fenshuhuajian()
{
	int common(int m,int n);       //����������� 
	int yinshu;
	/*if(fenmu==0)
	{
		randomNumber();
		randomOperation();
		calculateResult();
		if(casemu0!=1) 
		{
			generateExpression();
			special+=scan();
		}
		return 2;	
	} */
	/*else*/ if(fenzi==0)                        //����Ϊ0 
	{
		ans=0;
		return 0;
	}
	else if(fenzi%fenmu==0)                   //�������Ի������� 
	{
		ans=fenzi/fenmu;
		return 0;
	}
	else
	{   
		yinshu=common(fenzi,fenmu);
		fenzi=fenzi/yinshu;
		fenmu=fenmu/yinshu;
		if((fenzi>0&&fenmu<0)||(fenzi<0&&fenmu<0))                 // ��ֹ��� 4/-7  �� -5/-6   ����� 
		{
			fenzi=-fenzi;
			fenmu=-fenmu;
		}
		return 1;
	}
} 
/*
����������� 
*/
int common(int m,int n)
{
	int a,b,temp;
	if(m<n)
	{
		temp=m;
		m=n;
		n=temp;
	}
	a=m;
	b=n;
	while(b!=0)
	{
		temp=a%b;
		a=b;
		b=temp;
	}
	return(a);
}
/*
  ���ܣ����ͳ�ƽ��
*/ 
void print(int num,int i,int a,int score)
{
	void lan(int a,int b);
	score=score;//+special;
	lan(choice,4);
	cout<<i;
	lan(choice,5);
	cout<<score;
	lan(choice,6);
	cout<<i-score;
}



/*
  ���ܣ�����ѡ������ѡ�� 
*/ 
void choose()
{
	Menu();
	cin>>choice;
	if(choice<1||choice>5)
    {
    	cout<<"miu����������\n";
    	cin>>choice; 
    }
    if(choice<1||choice>5)
	{
		cout<<"�ٸ���һ�λ���\n";
		cin>>choice; 
	}
	lan(choice,1);
	cout<<endl;
}



/*
  ���ܣ�������
*/ 
int main(int argc,char *argv[])
{
	int n[5];
	int op[4];
	int i,point;
	int score=0;  
	int num;
	int circum;  
	char ch[10];
	char cans[100][100];
	char input[100][100];
	char shizi[100][1000];
	choose();           //ѡ���������� 
	num=atoi(readFile(argv[1],ch));
	for(i=1;i<=num;i++)
	{ 
		randomNumber(n);
		randomOperation(op);
		circum=calculateResult(n,op,cans,i);
		if(casemu0!=1) 
		{
			generateExpression(i,circum,n,op,shizi);
			point=scan(input,cans,i);
			if(point==3)
				break;
			else
				score+=point;
		}
	}
	writeFile(num,argv[2],ch,cans,input,shizi); 
	print(num,i-1,choice,score);
	return 0;
}

