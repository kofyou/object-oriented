#ifndef MYHEADFILE_H
#define MYHEADFILE_H
#include<iostream>
#include<string>
using namespace std;

class user
{
	public:
		int choseLanguage();                //ѡ������ 
		int readFile();                     //��ȡ��Ŀ���� 
		void scan();                        //��ȡ�û������ 
		friend int compareAnswer();         //������Ԫ���� 
		friend void writeFile();            //������Ԫ���� 
	private:
		int lan;                            //���� 
		int n;                              //��Ŀ���� 
		string userans[100];                //�û�����Ĵ� 
};


class equation
{
	public:
		void randomNumber();                //��������� 
		void randomOperation();	            //������������ 
		void generateExpression();          //���ɱ��ʽ 
		void caculateResult();              //����� 
		friend int compareAnswer();         //������Ԫ����
		friend void writeFile();            //������Ԫ���� 
	private:
		static char operation[4];           //�ĸ������ 
		int n[5];                           //�ĸ������ 
		int op[4];                          //�ĸ��������� 
		string expression;                  //��ʽ 
		string ans;		                    //��ȷ�� 
};

void menu();                                //�˵� 
 
int compareAnswer(user &,equation &);       //�Ƚϴ� 

void writeFile(user &,equation &);          //д��ָ���ļ� 
 
void print();                               //������ս�� 

#endif
