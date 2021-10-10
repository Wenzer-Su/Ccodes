#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

}
