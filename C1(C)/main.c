#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

}
