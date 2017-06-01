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
		void choseLanguage();                //选择语言 
		int readFile(char *c);                     //读取题目数量 
		void scan();                        //获取用户输入答案 
		friend int compareAnswer(user &,equation&);         //声明友元函数 
		friend void writeFile(user &,equation&,char *);            //声明友元函数 
		friend void print(user&,int,int);
	private:
		int lan;                            //语言 
		int n;                              //题目数量 
		string userans;                //用户输入的答案 
};


class equation
{
	public:
		void randomNumber();                //生成随机数 
		void randomOperation();	            //生成随机运算符 
		void randomCircum();                  //生成随机括号位置 
		void generateExpression();          //生成表达式 
		string midtoback();
		void caculateResult();              //计算答案 
		friend int compareAnswer(user &,equation&);         //声明友元函数
		friend void writeFile(user &,equation&,char *);            //声明友元函数 
	private:
		int circum;                           //随机括号位置 
		int n[5];                           //四个随机数 
		int op[4];                          //四个随机运算符 
		string expression;                  //算式 
		string ans;		                    //正确答案 
};



void Menu();                                //菜单 
 
int compareAnswer(user &,equation &);       //比较答案 

void lan(int a,int b);                      //交互语句 

void writeFile(user &,equation &,char *);          //写入指定文件 
 
void print(user &,int,int);                               //输出最终结果 

#endif
