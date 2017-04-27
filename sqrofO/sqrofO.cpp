#include <iostream>
#include "function.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) 
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
