#include<D:\github\object-oriented1\sqrofO\cacultsqr.h>
#include<iostream>
using namespace std;
int main()
{
	double rds=0,sqr=0;                             //分别是半径和面积 
	cin>>rds;
	if(rds<0)                                       //s输入小于0时的输出 
		cout<<"The circle doesn't exist."<<endl;
	else
	{
		sqr=cacultsqr(rds);                         //引用面积计算函数 
		cout<<"The square of the circle is "
			<<sqr<<endl;
	} 
	return 0;
}
