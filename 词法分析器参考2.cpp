/*
*author:  cuiyanran 
*date:    2020-4-26 15:08
*version: 1.0
*IDE:     Dev-C++
*/ 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <windows.h>
#include <cstdlib>
#define MAX_LEN 1024
#define MAX_ELEM_SIZE 256            // 变量名最大长度 
#define KEYWORDS_SIZE 6              // 关键字个数 
using namespace std;

typedef struct token{
	int kind_code;                   // 种别编码
	char inner_code[MAX_ELEM_SIZE];  // 内码值，为内部字符串或者数值 	
}Token;

int pr_index = 0, tk_index = 0;      // program_index and token_index 
char *prgrm_content;
// 可以使用枚举体 
const char *keywords[] = {"main", "if", "else", "int", "void", "while"};  // 关键字
const int kw_kind_code[] = {1, 2, 3, 4, 5, 6, 7}; 
Token *token;

bool isDigit(const char ch);
bool isPunct(const char ch);
bool isLetter(const char ch);
int matchKeyword(const char *str);
bool cmpString(const char *str1, const char *str2);
int strLength(const char *str);
char *readPrgrmFromFile(const char *file_name);  // return program 
char nextLetter();								 // 读取下个字符 
void skipSpace();                                // 跳过空格 
void rollbackIndex();                            // 指针回退 
void initKindCode(int kind_code);  				 // 初始化种别码
void writeConseqToFile(const char *file_name);   // 将生成的语法分析结果写入指定文件 
void syntaxAnalysis(const char *prgrm_content); 

void rollbackIndex()
{
	pr_index--;
}
void skipSpace()
{
	char ch = prgrm_content[pr_index];
	// windows的文件中换行的符号是\r\n，如果单纯判断\n会导致输出乱序且不全 
	while((ch == '\n') || (ch == ' ') || (ch == '\r') || (ch == '\t')){
		pr_index++;
		ch = prgrm_content[pr_index];
	}
}
char nextLetter()
{
	return prgrm_content[pr_index + 1];
}
bool isDigit(const char ch)
{
	if(ch >= '0' && ch <= '9')
		return true;
	return false;	
}
bool isLetter(const char ch)
{
	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return true;
	return false;
}
int strLength(const char *str)
{
	int len = 0;
	for(;str[len] != '\0';len++);
	return len + 1;
}
bool cmpString(const char *str1, const char *str2)
{
	int len1 = strLength(str1), len2 = strLength(str2);
	if(len1 != len2)
		return false;
	for(int i = 0;i < len1;i++)
	{
		if(str1[i] != str2[i])
		{
			return false;
		}
	}
	return true;
}
int matchKeyword(const char *str)
{
	for(int i = 0;i < KEYWORDS_SIZE;i++)
	{
		if(cmpString(str, keywords[i]))
		{
			return kw_kind_code[i];
		}
	}
	return -1;
}
void addToken(const int kind_code, const char *inner_code)
{
	token[tk_index].kind_code = kind_code;
	strcat(token[tk_index].inner_code, inner_code);
	tk_index++;
}
void syntaxAnalysis(const char *prgrm_content)
{
	while(prgrm_content[pr_index] != '\0')
	{
		//printf("%d\n", pr_index); 
		skipSpace();
		int kind_code = 0, str_index = 0;
		char str[MAX_ELEM_SIZE];
		switch(prgrm_content[pr_index])
		{
			case '=':
				if(nextLetter() == '='){
					addToken(17, "==");
					pr_index++;
				}
				else{
					addToken(8, "=");	
				}
				break;
			case '+':
				addToken(9, "+");
				break;
			case '-':
				addToken(10, "-");
				break;
			case '*':
				addToken(11, "*");
				break;
			case '/':
				if(nextLetter() == '/'){
					addToken(31, "//");
					pr_index++;
				}
				else{
					addToken(12, "/");	
				}
				break;
			case '<':
				if(nextLetter() == '='){
					addToken(14, "<=");
					pr_index++;
				}
				else{
					addToken(13, "<");	
				}
				break;
			case '>':
				if(nextLetter() == '='){
					addToken(16, ">=");
					pr_index++;
				}
				else{
					addToken(15, ">");	
				} 
				break;
			case '!':
				if(nextLetter() == '='){
					addToken(19, "!=");
					pr_index++;
				}
				else{
					addToken(18, "!");	
				}
				break;
			case ';':
				addToken(20, ";");
				break;
			case ':':
				addToken(21, ":");
				break;
			case ',':
				addToken(22, ",");
				break;
			case '{':
				addToken(23, "{");
				break;
			case '}':
				addToken(24, "}");
				break;	
			case '[':
				addToken(25, "[");
				break;
			case ']':
				addToken(26, "]");
				break;	
			case '(':
				addToken(27, "(");
				break;
			case ')':
				addToken(28, ")");
				break;			
			case '\"':case '\'':
			case '\\':case '.':case '#':case '_':case '~':case '%':case '^':case '&':break;
			default:
				char nextChar = prgrm_content[pr_index];
				int flag = isLetter(nextChar) ? 1 : 0;
				// 读取连续字符构成字符串 
				while(isLetter(nextChar) || isDigit(nextChar))
				{
					skipSpace();
					str[str_index++] = nextChar;
					nextChar = nextLetter();
					if(isLetter(nextChar) || isDigit(nextChar))
						pr_index++;
				}
				str[str_index] = '\0';
				int t = matchKeyword(str);
				if(t != -1)
					addToken(t, str);
				else
					if(flag)
						addToken(29, str);
				else
					addToken(30, str);
				break;	
		}
		pr_index++;
	}
}
char *readPrgrmFromFile(const char *file_name)  // return program
{
	FILE *fp;
	if((fp = fopen(file_name, "rb")) == NULL)
	{
		printf("file not found!\n");
		exit(-1);
	}

    static char line[256];
    while(!feof(fp) && !ferror(fp)) 
	{
		char str[256]; 
        fgets(str, sizeof(line), fp);
        strcat(line, str);
    }
    fclose(fp);
    return line;
}
void writeConseqToFile(const char *file_name)   // 将生成的语法分析结果写入指定文件 
{
	
}
void displayToken()
{
	for(int i = 0;i < tk_index;i++)
	{
		printf("[ %-6d %-6s ]\n", token[i].kind_code, token[i].inner_code);
	}	
}

int main()
{
	int cnt = 0;
	const char *path = "program.txt";
	prgrm_content = (char *)malloc(sizeof(char)*MAX_LEN); 
	prgrm_content = readPrgrmFromFile(path);
	token = (Token *)malloc(MAX_ELEM_SIZE*sizeof(Token));
	char str[MAX_LEN];
	syntaxAnalysis(prgrm_content);
	displayToken();
	return 0;
}
