#include <iostream>
#include <string.h>
using namespace std;
char key[6][20] = {"begin","if","then","while","do","end"};//定义一个二维数组存放关键字 
char token[20];	//存放字符（单词） 
//判断关键字 
int isKey(char s[])
{
	for(int i = 0; i<6;i++)
	{
		if(strcmp(s,key[i]) == 0)
		{
			return i+1;	//关键字的种别码依次为 begin=1,if=2,then=3,while=4,do=5,end=6即为 i+1 的值 
		}
	}
	return -1;
}
//判断是不是字母 
bool isChar(char ch)
{
	if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
	return true;
	else return false;
}
//判断是不是数字 
bool isNum(char ch)
{
	if(ch>='0' && ch<='9')
	return true;
	else
	return false;
}
//核心子程序
void scanner(int &syn,int &p,char s[])
{
	int count = 0;
	if(s[p] == ' ') p++;
	//开头是字母
	if(isChar(s[p]))
	{
		while(isNum(s[p]) || isChar(s[p]))
		{
			token[count++] = s[p];
			p++;
		}
		token[count] = '\0';	//'\0'作为结束符 ,将单词分隔开 
		syn = isKey(token);
		if(syn == -1)	
		{
			syn = 10;	//标识符letter(letter|digit) *
		}
	}
	
	//开头是数字
	else if(isNum(s[p]))
	{
		while(isNum(s[p]))
		{
			token[count++] = s[p];
			p++;
		}
		token[count] = '\0';//结束标识 
		syn = 11;	//数字digit(digit) *
	}
	
	//如果是运算符或者界符
	else
	{	
		//先处理没有争议的字符 
		switch(s[p])
		{
			case '+': syn = 13;token[0] = s[p];token[1]='\0';break;
			case '-': syn = 14;token[0] = s[p];token[1]='\0';break;
			case '*': syn = 15;token[0] = s[p];token[1]='\0';break;
			case '/': syn = 16;token[0] = s[p];token[1]='\0';break;
			case '=': syn = 25;token[0] = s[p];token[1]='\0';break;
			case ';': syn = 26;token[0] = s[p];token[1]='\0';break;
			case '(': syn = 27;token[0] = s[p];token[1]='\0';break;
			case ')': syn = 28;token[0] = s[p];token[1]='\0';break;
			case '#': syn = 0 ;token[0] = s[p];token[1]='\0';break;
		}
		
		
		//处理有争议的
		//: :=
		if(s[p] == ':')
		{
			token[count++] = s[p];
			if(s[p+1] == '=')
			{
				p++;
				token[count++] = s[p];
				syn = 18;
			}
			else
			{
				syn = 17;
			}
			token[count] = '\0';
		}
		
		//< <> <=
		if(s[p] == '<')
		{
			token[count++] = s[p];
			if(s[p+1] == '>')
			{
				p++;
				token[count++] = s[p];
				syn = 21;
			}
			else if(s[p+1] == '=')
			{
				p++;
				token[count++] = s[p];
				syn = 22;
			}
			else
			{
				syn = 20;
			}
			token[count] = '\0';
		}
		
		//> >=
		if(s[p] == '>')
		{
			token[count++] = s[p];
			if(s[p+1] == '=')
			{
				p++;
				token[count++] = s[p];
				syn = 24;
			}
			else
			{
				syn = 23;
			}
			token[count] = '\0';
		}
		
		//后移 
		p++;	//判断运算符和界符的这部分由于指针 p 没有向后指，所以需要将指针 p 向后移一位 
	}
	 
} 
int main()
{
	char s[100];	//输入字符串 
	while(cin>>s)
	{
		int p = 0;
		int syn;
		while(p < strlen(s))	//循环条件 ,p还未指到字符串最后	
		{
			scanner(syn,p,s);
			cout<<'<'<<token<<','<<syn<<'>'<<endl;
		}
	}
	return 0;
}