#include"myheadfile.h"

int main(int argc,char *argv[])
{
	int i;
	int num;                       //��Ŀ���� 
	int point;                     //�����Ŀ���� 
	Menu();                        //�˵� 
	user u;                        //�û���Ķ��� 
	u.choseLanguage();             //�û�ѡ������ 
	num=u.readFile(argv[1]);       //��ȡ��Ŀ���� 
	for(i=1,point=0;i<=num;i++)
	{
		equation t;                //��ʽ��Ķ��� 
		string userans;            //�洢�û�����Ĵ� 
		t.randomNumber();          //��������� 
		t.randomOperation();       //������������� 
		t.generateExpression();    //������ʽ 
		if(t.caculateResult()==0)continue;
		u.scan();                  //��ȡ�û����� 
		point+=compareAnswer(u,t);        //��Ԫ���� ���ڱȽ���ȷ�����û��� 
		writeFile(u,t,argv[2]);            //��Ԫ����  �����д��ָ���ļ� 
	}
	print(u,i-1,point);                       //������ս�� 
	return 0;
}
