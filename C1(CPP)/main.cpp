#include <cstdio>
#include <cstdlib>
#include <cstring>
#define _KEY_WORD_END "waiting for you expanding"   //关键字结束标志
typedef struct
{
    int typenum;    //种别码
    char *word;     //具体字符串
}WORD;

char input[255];        //缓冲区
char token[255]="";     //单词缓冲区
int p_input;
int p_token;            //缓冲区和单词缓冲区的指针

char ch;
//可扩充的关键字数组
char *rwtab[]= {"begin","if","then","while","do","end",_KEY_WORD_END};


//词法扫描函数，通过此函数获取一个单词
WORD* scaner();

int main()
{
    int over=1;
    WORD* oneword=new WORD;
    printf("Enter Your words(end with #):");
    //运行多行输入的方式，以#结束
    scanf("%[^#]s",input);
    p_input=0;
    printf("Your words:\n% s \n",input);
    //对源程序进行分析，直到遇到结束符
    while (over<1000&&over!=-1)
    {
        oneword=scaner();
        if (oneword->typenum<1000)
        {
            //打印自身种别码和单词自身
            printf("(%d,%s)\n",oneword->typenum,oneword->word);
        }
        over=oneword->typenum;
    }
    printf("\n press # to exit:");
    scanf("% [^#]s",input);

    return 0;
}

/*
从缓冲区读取一个字符到ch
*/
char m_getch()
{
    ch=input[p_input];
    p_input=p_input+1;
    return (ch);
}

/*
 去掉空白符合
 包含空格和回车
*/
void getbc()
{
    while (ch==' '||ch==10)
    {
        ch=input[p_input];
        p_input=p_input+1;
    }
}


/*
拼接单词
将ch逐个放入token
永远都在token的下一位填上结束符
*/
void concat()
{
    token[p_token]=ch;
    p_token=p_token+1;
    token[p_token]='\0';
}


/*
判断是否为字母
判断是否为数字
*/
int letter()
{
    if (ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int digit()
{
    if (ch>='0'&&ch<='9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/*
回退一个字符的位置
*/
void retract()
{
    p_input=p_input-1;
}

/*
检索关键字表格
*/
int reverse_it()
{
    int i=0;
    //检索数组到尾
    while (strcmp(rwtab[i],_KEY_WORD_END))
    {
        if (!strcmp(rwtab[i],token))
        {
            return i+1;
        }
        i=i+1;
    }
    //普通变量的种别码是10
    return 10;
}

/*
数字转化成二进制，自己补全
用不上
*/
char *dtb()
{

    /*



    自己做


    */
    return NULL;
}



/*
识别注释
*/
int content()
{
    if (ch=='/')
    {
       m_getch();
       if (ch=='/')
       {
           return 1;
       }
       else
       {
           retract();
           retract();
           return 0;
       }
    }
    else
    {

        return 0;
    }
}

void skipContent()
{
    while (ch!=' '&&ch!=10)
    {
        m_getch();
    }
    getbc();
}

WORD* scaner()
{
    WORD* myword=new WORD;
    myword->typenum=10;
    myword->word="";
    p_token=0;

    m_getch();
    getbc();
    if (content())
    {
        skipContent();
    }
    if (letter())
    {
        //检测到字母，只要后面还是字母，就一直拼接字母，并连接
        while (letter()||digit())
        {
            concat();
            m_getch();
        }
        //读多了，回退一格
        retract();
        //对关键字求种别码
        myword->typenum=reverse_it();
        myword->word=token;
        return (myword);
    }
    else if (digit())
    {
        while (digit())
        {
            concat();
            m_getch();

        }
        retract();
        //数字种别码应该是11
        myword->typenum=11;
        myword->word=token;
        return (myword);
    }
    else
    {
        switch (ch)
        {
        case '=':
            m_getch();
            if (ch=='=')
            {
                myword->typenum=39;
                myword->word="==";
                return (myword);
            }
            retract();
            myword->typenum=25;
            myword->word="=";
            return (myword);
            break;
        case '+':
            myword->typenum=13;
            myword->word="+";
            return (myword);
            break;
        case '-':
            myword->typenum=14;
            myword->word="-";
            return (myword);
            break;
        case '*':
            myword->typenum=15;
            myword->word="*";
            return (myword);
            break;
        case '/':
            myword->typenum=16;
            myword->word="/";
            return (myword);
            break;
        case '(':
            myword->typenum=27;
            myword->word="(";
            return (myword);
            break;
        case ')':
            myword->typenum=28;
            myword->word=")";
            return (myword);
            break;
        case '[':
            myword->typenum=29;
            myword->word="[";
            return (myword);
            break;
        case ']':
            myword->typenum=30;
            myword->word="]";
            return (myword);
            break;
        case '{':
            myword->typenum=31;
            myword->word="{";
            return (myword);
            break;
        case '}':
            myword->typenum=32;
            myword->word="}";
            return (myword);
            break;
        case ',':
            myword->typenum=33;
            myword->word=",";
            return (myword);
            break;
        case ':':
            m_getch();
            if (ch=='=')
            {
                myword->typenum=18;
                myword->word=":=";
                return (myword);
                break;
            }
            retract();
            myword->typenum=17;
            myword->word=":";
            return (myword);
            break;
        case ';':
            myword->typenum=26;
            myword->word=";";
            return (myword);
            break;
        case '>':
            m_getch();
            if (ch=='=')
            {
                myword->typenum=24;
                myword->word=">=";
                return (myword);
                break;
            }
            retract();
            myword->typenum=23;
            myword->word=">";
            return (myword);
            break;
        case '<':
            m_getch();
            if (ch=='=')
            {
                myword->typenum=22;
                myword->word="<=";
                return (myword);
                break;
            }
            if (ch=='>')
            {
                myword->typenum=21;
                myword->word="<>";
                return (myword);
                break;
            }
            retract();
            myword->typenum=20;
            myword->word="<";
            return (myword);
            break;
        case '!':
            m_getch();
            if (ch=='=')
            {
                myword->typenum=40;
                myword->word="!=";
                return (myword);
                break;
            }
            retract();
            myword->typenum=-1;
            myword->word="ERROR";
            return (myword);
            break;
        case '\0':
            myword->typenum=1000;
            myword->word="OVER";
            return (myword);
            break;
        default:
            myword->typenum=-1;
            myword->word="ERROR";
            return (myword);
        }
    }
}




















