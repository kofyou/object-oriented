#include"myheadfile.h"
void Menu()
{
	
	cout<<"---------------------------------------------------------------------------------\n";
	cout<<"*****************Welcome to use the arithmetic device for pupils!****************\n";
	cout<<"*******        1Chinese  2English  3Japanese  4Franch  5German       **********\n";
	cout<<"---------------------------------------------------------------------------------\n\n";
}

void user::choseLanguage()
{
	int choice;
	cin>>choice;
	if(choice<1||choice>5)
    {
    	cout<<"miu这种语言啦\n";
    	cin>>choice; 
    }
    if(choice<1||choice>5)
	{
		cout<<"再给你一次机会\n";
		cin>>choice; 
	}
	lan=choice;
	cout<<endl;
}

int user::readFile(char *c)
{
	char ch[10];
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
	n=atoi(ch);
	return n;
}

void user::scan()
{
	cin>>userans;
}


void equation::randomNumber()
{
	srand(time(NULL));
	n[1]=rand()%10;n[2]=rand()%10;n[3]=rand()%10;n[4]=rand()%10;
}

void equation::randomOperation()
{
	srand(time(NULL));
	op[1]=rand()%4;op[2]=rand()%4;op[3]=rand()%4;	
}

void equation::randomCircum()
{
	srand(time(NULL));
	circum=rand()%5;	
} 

void equation::generateExpression()
{
	char operation[4]={'+','-','*','/'};
	char suanshi[20];
	switch(circum) 
	{
		case 0:
		{
			cout<<n[1]<<operation[op[1]]<<n[2]<<operation[op[2]]<<n[3]<<operation[op[3]]<<n[4]<<'='; 
			sprintf(suanshi,"%d%c%d%c%d%c%d",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
			break;  	
		}
		case 1:
		{
			cout<<'('<<n[1]<<operation[op[1]]<<n[2]<<')'<<operation[op[2]]<<n[3]<<operation[op[3]]<<n[4]<<'='; 
			sprintf(suanshi,"(%d%c%d)%c%d%c%d",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
			break;
		}
		case 2:
		{
			cout<<n[1]<<operation[op[1]]<<'('<<n[2]<<operation[op[2]]<<n[3]<<')'<<operation[op[3]]<<n[4]<<'='; 
			sprintf(suanshi,"%d%c(%d%c%d)%c%d",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
			break;
		}
		case 3:
		{	
			cout<<n[1]<<operation[op[1]]<<n[2]<<operation[op[2]]<<'('<<n[3]<<operation[op[3]]<<n[4]<<')'<<'='; 
			sprintf(suanshi,"%d%c%d%c(%d%c%d)",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
			break;
		}
		case 4:
		{  
			cout<<'('<<n[1]<<operation[op[1]]<<n[2]<<operation[op[2]]<<n[3]<<')'<<operation[op[3]]<<n[4]<<'='; 
			sprintf(suanshi,"(%d%c%d%c%d)%c%d",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
			break;
		}
		case 5:
		{ 
			cout<<n[1]<<operation[op[1]]<<'('<<n[2]<<operation[op[2]]<<n[3]<<operation[op[3]]<<n[4]<<')'<<'='; 
			sprintf(suanshi,"%d%c(%d%c%d%c%d)",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
		}
	}
	expression=string(suanshi);
}

bool isadvancer(char a,char b)
{
	if(a=='(')return false;
	if(a=='+'||a=='-')
	{
		if(b=='*'||b=='/')
			return false;
		else 
			return true;
	}
	if(a=='*'||a=='/')
	{
		if(b=='+'||b=='-')
			return true;
		else
			return true;
	}
}


void midtoback(string exp,char expsz[100])
{
	std::stack<char> st;
	int i,j=0;
	int len=exp.size();
	char temp;
	string backexp;
	
	
	for(i=0;i<len;i++)
	{
		temp=exp[i];
        if(temp=='(')
            st.push(temp);
        else if(temp==')')
        {
            while(st.top()!='(')
            {
                backexp[j]=st.top();
                j++;
                st.pop();
            }
            st.pop();
        }
        else
        {
            if(temp>=48&&temp<=57)
                {
				st.push(temp);
				}
			else
            {
                while(st.empty()==false&&isadvancer(st.top(),temp)==true)
                {
                    backexp[j]=st.top();
                    j++;
                    st.pop();
                }
                st.push(temp);
            }
        }
	}
	while (st.empty()==false)
    {
        backexp[j++]=st.top();
        st.pop();
    }
    backexp[j]=0;
    
    

	
	strcpy(expsz,backexp.c_str());
		
}


int equation::caculateResult()
{
	char backsz[100];
	
	string backexp;
	
	midtoback(expression,backsz);
	backexp=string(backsz);
	int len=backexp.size();
	char temp;
	std::stack<char> st;
	for(int i=0;i<len;i++)
	{
		temp=backexp[i];
		if(temp>=48&&temp<=57)
		{
			st.push(temp-'0');
		}
		else
		{
			char num1,num2;
			int newnum;
			num1=st.top();
			st.pop();
			num2=st.top();
			st.pop();
			if(temp=='+')
			{
				newnum=num1+num2;
				st.push(newnum);
			}
			else if(temp=='-')
			{
				newnum=num2-num1;
				st.push(newnum);
			}
			else if(temp=='*')
			{
				newnum=num1*num2;
				st.push(newnum);
			}
			else
			{
				if(num1==0)
				{
					ans="error";
					cout<<ans<<endl;
					return 0;
				}
				newnum=num2/num1;
				st.push(newnum);
			}
		}
	}
	int intans;
	intans=st.top();
	char charans[10];
	sprintf(charans,"%d",intans);
	ans=string(charans);
	return 1;
}



void lan(int a,int b)
{
	char language[1000]; 
	if(a==1) strcpy(language,"D:\\github\\object-oriented1\\jisuanqi3\\Chinese.txt");
	if(a==2) strcpy(language,"D:\\github\\object-oriented1\\jisuanqi3\\English.txt");
	if(a==3) strcpy(language,"D:\\github\\object-oriented1\\jisuanqi3\\Japanese.txt");
	if(a==4) strcpy(language,"D:\\github\\object-oriented1\\jisuanqi3\\Franch.txt");
	if(a==5) strcpy(language,"D:\\github\\object-oriented1\\jisuanqi3\\German.txt");
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

int compareAnswer(user &uu,equation &tt)
{
	if(uu.userans==tt.ans)
	{
		lan(uu.lan,2);
		return 1;
	}
	else
	{
		lan(uu.lan,3);
		cout<<tt.ans<<endl<<endl;
		return 0;
	}
}

void writeFile(user &uu,equation &tt,char *a)
{
	char out[1000];
	char ch[10];
	strcpy(out,a);
	FILE * q;
	if((q=fopen(out,"a"))==NULL)
	printf("cant find");
	fputs("题目数量：",q);
	sprintf(ch,"%d",uu.n);
	fputs(ch,q);
	fputc('\n',q);
	
	
	char* c1;
	const int len1 =tt.expression.length();
	c1=new char[len1+1];
	strcpy(c1,tt.expression.c_str());
	fputs(c1,q);
	fputs("\n",q);
	
	char* c2;
	const int len2 =uu.userans.length();
	c2=new char[len2+1];
	strcpy(c2,uu.userans.c_str());
	fputs(c2,q);
	fputs("\n",q);
	
	char* c3;
	const int len3 =tt.ans.length();
	c3=new char[len3+1];
	strcpy(c3,tt.ans.c_str());
	fputs(c3,q);
	fputs("\n\n",q);
	
	
	fclose(q);
}


void print(user &uuu,int i,int score)
{
	lan(uuu.lan,4);
	cout<<i;
	lan(uuu.lan,5);
	cout<<score;
	lan(uuu.lan,6);
	cout<<i-score;
} 



