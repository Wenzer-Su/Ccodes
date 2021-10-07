#include <iostream>
#include <cstdio>
using namespace std;
int m[10000][10000];
int main()
{
    long s=0;
    long n;
    long x1,x2,y1,y2;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        for (int j=x1;j<x2;j++)
            for (int k=y1;k<y2;k++)
                m[j][k]=1;
    }
    for (int i=0;i<1000;i++)
        for (int j=0;j<1000;j++)
            s+=m[i][j];
    cout<<s<<endl;
    return 0;
}
