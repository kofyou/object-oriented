#include<time.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

class Random{ 
	public:
		void random()
		{
		}
};

class RandomOperation:protected Random{
	public:
		void random()
		{
			int temp;
			char operations[]={"+-*/"};
			srand(time(NULL));
			for(int i=1;i<=3;i++)
			{
				temp=rand()%4;
				op[i]=operations[temp];
			}
		}
	protected:
		char op[4];
};

class RandomNumber:protected Random{
	public:
		void random()
		{
			n[1]=rand()%11;
			n[2]=rand()%11;
			n[3]=rand()%11;
			n[4]=rand()%11;
		}
	protected:
		int n[5];
};

class RandomExpression:protected RandomOperation,protected RandomNumber{
	public:
		void random()
		{	
			RandomOperation::random();
			RandomNumber::random();
			sprintf(expression,"%d%c%d%c%d%c%d",n[1],op[1],n[2],op[2],n[3],op[3],n[4]);
		} 
	protected:
		char expression[8];
};

