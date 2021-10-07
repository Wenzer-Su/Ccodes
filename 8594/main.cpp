#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long charList[20];
void switchNumber(long &a,long &b)
{
    long t=a;
    a=b;
    b=t;
}
void Perm(long l[],long k,long m)
{
    if (k==m)
    {
        for (int i=1;i<=m;i++)
        {
            cout<<l[i];
        }
        cout<<endl;
    }
    else
    {
        for (int i=k;i<=m;i++)
        {
            switchNumber(l[k],l[i]);
            Perm(l,k+1,m);
            switchNumber(l[k],l[i]);
        }
    }
}
int main()
{
    long n;
    char ch;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>ch;
        charList[i]=ch-'0';
    }
    sort(charList+1,charList+n+1);
    Perm(charList,1,n);
    return 0;
}
