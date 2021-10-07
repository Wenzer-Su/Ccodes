#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
char data[255];
int main()
{
    ifstream ifile("test.txt");
    int i=0;
    char ch;
    while(ifile.get(ch))
    {
        data[i++]=ch;
    }
    cout<<data<<endl;
    return 0;

}
