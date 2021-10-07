#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#define _KEY_WORD_END "waiting for your expanding"
using namespace std;
//单词二元组的结构
typedef struct
{
    int type_num;
    char *word;
} WORD;

char input[255];        //输入缓冲区
char token[255]="";     //单词缓冲区
int p_input;            //输入缓冲区的指针
int p_token;            //单词缓冲区指针

char ch;
//可扩充的关键字数组
char *rwtab[]= {"begin","if","then","while","do","end",_KEY_WORD_END};

//词法扫描函数，由此获得一个新单词
WORD * scaner();
void getInput()
{
    int i=0;
    char c;

}
int main()
{
    int over=1;
    WORD * oneword=new WORD;
    cout<<"Enter Your words(end with #):";
    //要求用户输入内容，通过正则表达式实现以#结尾
    scanf("%[^#]s",input);
    p_input=0;
    printf("Your words:\n% s \n",input);


    while(over<1000&&over!=-1)
    {
        /*
        对源程序进行分析
        直至遇到结束符#
        */
        oneword=scaner();       //获取一个新的单词
        if (oneword->type_num<1000)
        {
            //打印种别码和单词自身的值
            printf("(%d,%s)",oneword->type_num,oneword->word);
        }
        over=oneword->type_num;
        if (over==10)
            break;


    }
    cout<<endl<<"press # to exit:";
    scanf("% [^#]s",input);
    return 0;
}

/*
从输入缓冲区读取一个字符到ch中
*/
char m_getch()
{
    ch=input[p_input];
    p_input++;
    return ch;
}

/*
去掉空白符号
*/
void getbc()
{
    while(ch==' '||ch==10)
    {
        //遇到空格就跳过，在缓冲区里跳过
        ch=input[p_input];
        p_input++;
    }
}

/*
拼接单词
*/
void concat()
{
    token[p_token]=ch;
    p_token++;
    token[p_token]='\0';    //对字符串的该位置清空
}

/*
判断是否为字母
*/
int letter()
{
    if ((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
    {
        return 1;
    }
    return 0;
}

/*
判断是否为数字
*/
int digit()
{
    if (ch>='0'&&ch<='9')
    {
        return 1;
    }
    return 0;
}

/*
检索关键字表格
*/
int reverse_it()
{
    int i=0;
    while(strcmp(rwtab[i],_KEY_WORD_END))
    {
        //检索当前截取的单词是否在关键字表当中
        if (strcmp(rwtab[i],token))
        {
            return i+1;
        }
        i++;
    }
}

/*
回退一个字符的位置
*/
void retract()
{
    p_input--;
}


/*
数字转化成二进制，自己补全
*/
char *dtb()
{

    /*



    自己做


    */
    return NULL;
}

WORD* scaner()
{
    WORD* myword=new WORD;
    myword->type_num=10;
    myword->word="";
    p_token=0;
    //从缓冲区中读入一个字符放入ch
    m_getch();
    //在缓冲区去掉空白符号
    getbc();
    if (letter())
    {
        //检测到首字符是字母，就可以拼接成关键字返回
        while(letter()||digit())
        {
            //只要还是字母或者数字，就不断拼接并读取下一个
            concat();
            m_getch();
        }
        //指针回退一格
        retract();
        //判定相关的关键字,确定是哪一个
        myword->type_num=reverse_it();
        //将此单词进行存储
        myword->word=token;
        return (myword);
    }
    else
    {
        if (digit())
        {
            //如果是数字，就一直拼接数字
            while(digit())
            {
                concat();
                m_getch();
            }
            retract();
            myword->type_num=20;
            myword->word=token;
            return (myword);
        }
        else
        {
            switch(ch)
            {
            case '=':
                m_getch();
                if (ch=='=')
                {
                    //如果下一个是等号的话，就是==
                    myword->type_num=39;
                    myword->word="==";
                    return (myword);
                }
                //如果不是两个=，就退格并返回单=
                retract();
                myword->type_num=21;
                myword->word="=";
                return (myword);
                break;
            case '+':
                myword->type_num=22;
                myword->word="+";
                return (myword);
                break;
            case '-':
                myword->type_num=23;
                myword->word="-";
                return (myword);
                break;
            case '*':
                myword->type_num=24;
                myword->word="*";
                return (myword);
                break;
            case '/':
                myword->type_num=25;
                myword->word="/";
                return (myword);
                break;
            case '(':
                myword->type_num=26;
                myword->word="(";
                return (myword);
                break;
            case ')':
                myword->type_num=27;
                myword->word=")";
                return (myword);
                break;
            case '[':
                myword->type_num=28;
                myword->word="[";
                return (myword);
                break;
            case ']':
                myword->type_num=29;
                myword->word="]";
                return (myword);
                break;
            case '{':
                myword->type_num=30;
                myword->word="{";
                return (myword);
                break;
            case '}':
                myword->type_num=31;
                myword->word="}";
                return (myword);
                break;
            case ',':
                myword->type_num=32;
                myword->word=",";
                return (myword);
                break;
            case ':':
                myword->type_num=33;
                myword->word=":";
                return (myword);
                break;
            case ';':
                myword->type_num=34;
                myword->word=";";
                return (myword);
                break;
            case '>':
                m_getch();
                if (ch=='=')
                {
                    myword->type_num=37;
                    myword->word=">=";
                    return (myword);
                }
                retract();
                myword->type_num=35;
                myword->word=">";
                return (myword);
                break;
            case '<':
                m_getch();
                if (ch=='=')
                {
                    myword->type_num=38;
                    myword->word="<=";
                    return (myword);
                }
                retract();
                myword->type_num=36;
                myword->word="<";
                return (myword);
                break;
            case '!':
                m_getch();
                if (ch=='=')
                {
                    myword->type_num=40;
                    myword->word="!=";
                }
                retract();
                myword->type_num=-1;
                myword->word="ERROR";
                return (myword);
                break;
            case '\0':
                myword->type_num==1000;
                myword->word="OVER";
                return (myword);
                break;
            default:
                myword->type_num=-1;
                myword->word="ERROR";
                return (myword);
            }
        }
    }
}
