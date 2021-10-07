#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#define _KEY_WORD_END "waiting for your expanding"
using namespace std;
//���ʶ�Ԫ��Ľṹ
typedef struct
{
    int type_num;
    char *word;
} WORD;

char input[255];        //���뻺����
char token[255]="";     //���ʻ�����
int p_input;            //���뻺������ָ��
int p_token;            //���ʻ�����ָ��

char ch;
//������Ĺؼ�������
char *rwtab[]= {"begin","if","then","while","do","end",_KEY_WORD_END};

//�ʷ�ɨ�躯�����ɴ˻��һ���µ���
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
    //Ҫ���û��������ݣ�ͨ��������ʽʵ����#��β
    scanf("%[^#]s",input);
    p_input=0;
    printf("Your words:\n% s \n",input);


    while(over<1000&&over!=-1)
    {
        /*
        ��Դ������з���
        ֱ������������#
        */
        oneword=scaner();       //��ȡһ���µĵ���
        if (oneword->type_num<1000)
        {
            //��ӡ�ֱ���͵��������ֵ
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
�����뻺������ȡһ���ַ���ch��
*/
char m_getch()
{
    ch=input[p_input];
    p_input++;
    return ch;
}

/*
ȥ���հ׷���
*/
void getbc()
{
    while(ch==' '||ch==10)
    {
        //�����ո���������ڻ�����������
        ch=input[p_input];
        p_input++;
    }
}

/*
ƴ�ӵ���
*/
void concat()
{
    token[p_token]=ch;
    p_token++;
    token[p_token]='\0';    //���ַ����ĸ�λ�����
}

/*
�ж��Ƿ�Ϊ��ĸ
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
�ж��Ƿ�Ϊ����
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
�����ؼ��ֱ��
*/
int reverse_it()
{
    int i=0;
    while(strcmp(rwtab[i],_KEY_WORD_END))
    {
        //������ǰ��ȡ�ĵ����Ƿ��ڹؼ��ֱ���
        if (strcmp(rwtab[i],token))
        {
            return i+1;
        }
        i++;
    }
}

/*
����һ���ַ���λ��
*/
void retract()
{
    p_input--;
}


/*
����ת���ɶ����ƣ��Լ���ȫ
*/
char *dtb()
{

    /*



    �Լ���


    */
    return NULL;
}

WORD* scaner()
{
    WORD* myword=new WORD;
    myword->type_num=10;
    myword->word="";
    p_token=0;
    //�ӻ������ж���һ���ַ�����ch
    m_getch();
    //�ڻ�����ȥ���հ׷���
    getbc();
    if (letter())
    {
        //��⵽���ַ�����ĸ���Ϳ���ƴ�ӳɹؼ��ַ���
        while(letter()||digit())
        {
            //ֻҪ������ĸ�������֣��Ͳ���ƴ�Ӳ���ȡ��һ��
            concat();
            m_getch();
        }
        //ָ�����һ��
        retract();
        //�ж���صĹؼ���,ȷ������һ��
        myword->type_num=reverse_it();
        //���˵��ʽ��д洢
        myword->word=token;
        return (myword);
    }
    else
    {
        if (digit())
        {
            //��������֣���һֱƴ������
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
                    //�����һ���ǵȺŵĻ�������==
                    myword->type_num=39;
                    myword->word="==";
                    return (myword);
                }
                //�����������=�����˸񲢷��ص�=
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
