#include"myheadfile.h"

char equation::operation[4]={'+','-','*','/'};     //四种运算符的初始化 

int main(int argc,char *argv[])
{
	int i;
	int num;                       //题目数量 
	int language;                  //语言
	int point;                     //答对题目数量 
	menu();                        //菜单 
	user u;                        //用户类的对象 
	language=u.choseLanguage();    //用户选择语言 
	num=u.readFile();              //读取题目数量 
	for(i=1,point=0;i<=num;i++)
	{
		equation t;                //算式类的对象 
		string userans;            //存储用户输入的答案 
		t.randomNumber();          //生成随机数 
		t.randomOperation();       //生成随机操作符 
		t.generateExpression();    //生成算式 
		t.caculateResult();        //计算正确答案 
		u.scan();                  //获取用户输入 
		compareAnswer(u,t);        //友元函数 用于比较正确答案与用户答案 
		writeFile(u,t);            //友元函数  将结果写入指定文件 
	}
	print();                       //输出最终结果 
	return 0;
}
