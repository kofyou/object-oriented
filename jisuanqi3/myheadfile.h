#ifndef MYHEADFILE_H
#define MYHEADFILE_H
#include<iostream>
#include<stack>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;

class equation;
class user
{
	public:
		void choseLanguage();                //ѡ������ 
		int readFile(char *c);                     //��ȡ��Ŀ���� 
		void scan();                        //��ȡ�û������ 
		friend int compareAnswer(user &,equation&);         //������Ԫ���� 
		friend void writeFile(user &,equation&,char *);            //������Ԫ���� 
		friend void print(user&,int,int);
	private:
		int lan;                            //���� 
		int n;                              //��Ŀ���� 
		string userans;                //�û�����Ĵ� 
};


class equation
{
	public:
		void randomNumber();                //��������� 
		void randomOperation();	            //������������ 
		void randomCircum();                  //�����������λ�� 
		void generateExpression();          //���ɱ��ʽ 
		string midtoback();
		void caculateResult();              //����� 
		friend int compareAnswer(user &,equation&);         //������Ԫ����
		friend void writeFile(user &,equation&,char *);            //������Ԫ���� 
	private:
		int circum;                           //�������λ�� 
		int n[5];                           //�ĸ������ 
		int op[4];                          //�ĸ��������� 
		string expression;                  //��ʽ 
		string ans;		                    //��ȷ�� 
};



void Menu();                                //�˵� 
 
int compareAnswer(user &,equation &);       //�Ƚϴ� 

void lan(int a,int b);                      //������� 

void writeFile(user &,equation &,char *);          //д��ָ���ļ� 
 
void print(user &,int,int);                               //������ս�� 

#endif
