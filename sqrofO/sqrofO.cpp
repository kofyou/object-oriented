#include<D:\github\object-oriented1\sqrofO\cacultsqr.h>
#include<iostream>
using namespace std;
int main()
{
	double rds=0,sqr=0;                             //�ֱ��ǰ뾶����� 
	cin>>rds;
	if(rds<0)                                       //s����С��0ʱ����� 
		cout<<"The circle doesn't exist."<<endl;
	else
	{
		sqr=cacultsqr(rds);                         //����������㺯�� 
		cout<<"The square of the circle is "
			<<sqr<<endl;
	} 
	return 0;
}
