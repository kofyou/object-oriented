#include"myheadfile.h"

char equation::operation[4]={'+','-','*','/'};     //����������ĳ�ʼ�� 

int main(int argc,char *argv[])
{
	int i;
	int num;                       //��Ŀ���� 
	int language;                  //����
	int point;                     //�����Ŀ���� 
	menu();                        //�˵� 
	user u;                        //�û���Ķ��� 
	language=u.choseLanguage();    //�û�ѡ������ 
	num=u.readFile();              //��ȡ��Ŀ���� 
	for(i=1,point=0;i<=num;i++)
	{
		equation t;                //��ʽ��Ķ��� 
		string userans;            //�洢�û�����Ĵ� 
		t.randomNumber();          //��������� 
		t.randomOperation();       //������������� 
		t.generateExpression();    //������ʽ 
		t.caculateResult();        //������ȷ�� 
		u.scan();                  //��ȡ�û����� 
		compareAnswer(u,t);        //��Ԫ���� ���ڱȽ���ȷ�����û��� 
		writeFile(u,t);            //��Ԫ����  �����д��ָ���ļ� 
	}
	print();                       //������ս�� 
	return 0;
}
