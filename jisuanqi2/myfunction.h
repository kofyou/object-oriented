#ifndef MYFUNCTION_H
#define MYUNCTION_H 

char * readFile(char *c,char *ch);

void writeFile(int num,char *a,char *ch,char cans[][100],char input[][100],char shizi[][1000]);

void Menu();

void lan(int a,int b);

void randomNumber(int *n);

void randomOperation(int *op);

void generateExpression(int i,int circum,int *n,int *op,char shizi[][1000]);

int calculateResult(int *n,int *op,char cans[][100],int i);

int chengchu1(int n[5],int op[4]);  
int chengchu2(int n[5],int op[4]);  
int chengchu3(int n[5],int op[4]);  
int chengchu4(int n[5],int op[4]);  
int chengchu5(int n[5],int op[4]);  
int chengchu6(int n[5],int op[4]); 

int scan(char input[][100],char cans[][100],int i);

int fenshuhuajian();

int common(int m,int n);

void print(int num,int i,int a,int score);

void choose();


#endif
