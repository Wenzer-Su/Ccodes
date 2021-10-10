#include <cstdio>
#include <cstdlib>
#include <cstring>
#define _KEY_WORD_END "waiting for you expanding"   //�ؼ��ֽ�����־
typedef struct
{
    int typenum;    //�ֱ���
    char *word;     //�����ַ���
}WORD;

char input[255];        //������
char token[255]="";     //���ʻ�����
int p_input;
int p_token;            //�������͵��ʻ�������ָ��

char ch;
//������Ĺؼ�������
char *rwtab[]= {"begin","if","then","while","do","end",_KEY_WORD_END};


//�ʷ�ɨ�躯����ͨ���˺�����ȡһ������
WORD* scaner();

int main()
{
    int over=1;
    WORD* oneword=new WORD;
    printf("Enter Your words(end with #):");
    //���ж�������ķ�ʽ����#����
    scanf("%[^#]s",input);
    p_input=0;
    printf("Your words:\n% s \n",input);
    //��Դ������з�����ֱ������������
    while (over<1000&&over!=-1)
    {
        oneword=scaner();
        if (oneword->typenum<1000)
        {
            //��ӡ�����ֱ���͵�������
            printf("(%d,%s)\n",oneword->typenum,oneword->word);
        }
        over=oneword->typenum;
    }
    printf("\n press # to exit:");
    scanf("% [^#]s",input);

    return 0;
}

/*
�ӻ�������ȡһ���ַ���ch
*/
char m_getch()
{
    ch=input[p_input];
    p_input=p_input+1;
    return (ch);
}

/*
 ȥ���հ׷���
 �����ո�ͻس�
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
ƴ�ӵ���
��ch�������token
��Զ����token����һλ���Ͻ�����
*/
void concat()
{
    token[p_token]=ch;
    p_token=p_token+1;
    token[p_token]='\0';
}


/*
�ж��Ƿ�Ϊ��ĸ
�ж��Ƿ�Ϊ����
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
����һ���ַ���λ��
*/
void retract()
{
    p_input=p_input-1;
}

/*
�����ؼ��ֱ��
*/
int reverse_it()
{
    int i=0;
    //�������鵽β
    while (strcmp(rwtab[i],_KEY_WORD_END))
    {
        if (!strcmp(rwtab[i],token))
        {
            return i+1;
        }
        i=i+1;
    }
    //��ͨ�������ֱ�����10
    return 10;
}

/*
����ת���ɶ����ƣ��Լ���ȫ
�ò���
*/
char *dtb()
{

    /*



    �Լ���


    */
    return NULL;
}



/*
ʶ��ע��
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
        //��⵽��ĸ��ֻҪ���滹����ĸ����һֱƴ����ĸ��������
        while (letter()||digit())
        {
            concat();
            m_getch();
        }
        //�����ˣ�����һ��
        retract();
        //�Թؼ������ֱ���
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
        //�����ֱ���Ӧ����11
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




















