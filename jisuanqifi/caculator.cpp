#include "mainwindow.h"
#include "ui_mainwindow.h"

char suanshi[20];
int point=0;
int numofround=0;
std::string expression;
int ans;

bool isadvancer(char a,char b);
void midtoback(std::string exp,char expsz[100]);
int caculateResult();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
        int n[5],op[4],circum;
        char operation[4]={'+','-','*','/'};
        srand(time(NULL));
        n[1]=rand()%10;n[2]=rand()%10;n[3]=rand()%10;n[4]=rand()%10;

        srand(time(NULL));
        op[1]=rand()%4;op[2]=rand()%4;op[3]=rand()%4;

        srand(time(NULL));
        circum=rand()%5;

        switch(circum)
        {
         case 0:{
             sprintf(suanshi,"%d%c%d%c%d%c%d",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
        }break;
        case 1:{
             sprintf(suanshi,"(%d%c%d)%c%d%c%d",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
        }break;
        case 2:{
             sprintf(suanshi,"%d%c(%d%c%d)%c%d",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
        }break;
        case 3:{
             sprintf(suanshi,"%d%c%d%c(%d%c%d)",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
        }break;
        case 4:{
             sprintf(suanshi,"(%d%c%d%c%d)%c%d",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
        }break;
        case 5:{
             sprintf(suanshi,"%d%c(%d%c%d%c%d)",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
        }
        }

        QString expression2=QString(suanshi);

        expression=expression2.toStdString();

        ui->label_3->setText(expression2);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString tmpStr;
    bool OK;
    QString strans=ui->lineEdit->text();
    int userans= strans.toInt(&OK,10);

    if(caculateResult()==0)
    {
        ui->label_4->setText("除零错误");
    }
    else{
        if(ans==userans)
        {
            ui->label_4->setText("正确");
            point++;
            numofround++;
        }
        else
        {
            QString tmpStr;
            ui->label_4->setText(tmpStr.setNum(ans));
            numofround++;
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString tmpStr;

    ui->label_6->setText(tmpStr.setNum(numofround));

    ui->label_9->setText(tmpStr.setNum(point));

}

bool isadvancer(char a,char b)
{
    if(a=='(')return false;
    if(a=='+'||a=='-')
    {
        if(b=='*'||b=='/')
            return false;
        else
            return true;
    }
    if(a=='*'||a=='/')
    {
        if(b=='+'||b=='-')
            return true;
        else
            return true;
    }
}

void midtoback(std::string exp,char expsz[100])
{
    std::stack<char> st;
    int i,j=0;
    int len=exp.size();
    char temp;
    std::string backexp;


    for(i=0;i<len;i++)
    {
        temp=exp[i];
        if(temp=='(')
            st.push(temp);
        else if(temp==')')
        {
            while(st.top()!='(')
            {
                backexp[j]=st.top();
                j++;
                st.pop();
            }
            st.pop();
        }
        else
        {
            if(temp>=48&&temp<=57)
                {
                st.push(temp);
                }
            else
            {
                while(st.empty()==false&&isadvancer(st.top(),temp)==true)
                {
                    backexp[j]=st.top();
                    j++;
                    st.pop();
                }
                st.push(temp);
            }
        }
    }
    while (st.empty()==false)
    {
        backexp[j++]=st.top();
        st.pop();
    }
    backexp[j]=0;




    strcpy(expsz,backexp.c_str());

}

int caculateResult()
{
        char backsz[100];

        std::string backexp;

        midtoback(expression,backsz);
        backexp=std::string(backsz);
        int len=backexp.size();
        char temp;
        std::stack<char> st;
        for(int i=0;i<len;i++)
        {
            temp=backexp[i];
            if(temp>=48&&temp<=57)
            {
                st.push(temp-'0');
            }
            else
            {
                char num1,num2;
                int newnum;
                num1=st.top();
                st.pop();
                num2=st.top();
                st.pop();
                if(temp=='+')
                {
                    newnum=num1+num2;
                    st.push(newnum);
                }
                else if(temp=='-')
                {
                    newnum=num2-num1;
                    st.push(newnum);
                }
                else if(temp=='*')
                {
                    newnum=num1*num2;
                    st.push(newnum);
                }
                else
                {
                    if(num1==0)
                    {
                        return 0;
                    }
                    newnum=num2/num1;
                    st.push(newnum);
                }
            }
        }
        ans=st.top();
        return 1;
}
