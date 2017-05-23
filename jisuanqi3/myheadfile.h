#ifndef MYHEADFILE_H
#define MYHEADFILE_H
#include<iostream>
#include<string>
using namespace std;

class user
{
	public:
		int choseLanguage();                //选择语言 
		int readFile();                     //读取题目数量 
		void scan();                        //获取用户输入答案 
		friend int compareAnswer();         //声明友元函数 
		friend void writeFile();            //声明友元函数 
	private:
		int lan;                            //语言 
		int n;                              //题目数量 
		string userans[100];                //用户输入的答案 
};


class equation
{
	public:
		void randomNumber();                //生成随机数 
		void randomOperation();	            //生成随机运算符 
		void generateExpression();          //生成表达式 
		void caculateResult();              //计算答案 
		friend int compareAnswer();         //声明友元函数
		friend void writeFile();            //声明友元函数 
	private:
		static char operation[4];           //四个运算符 
		int n[5];                           //四个随机数 
		int op[4];                          //四个随机运算符 
		string expression;                  //算式 
		string ans;		                    //正确答案 
};

void menu();                                //菜单 
 
int compareAnswer(user &,equation &);       //比较答案 

void writeFile(user &,equation &);          //写入指定文件 
 
void print();                               //输出最终结果 

#endif
