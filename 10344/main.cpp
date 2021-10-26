#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int solve(int n);
map<int,int> m;
int main()
{
    int n;
    cin>>n;
    m[1]=1;
    if (n>1)
    {
        cout<<solve(n)<<endl;
    }
    else
    {
        cout<<1<<endl;
    }
    return 0;
}
int solve(int n)
{
    if (m.find(n)==m.end())
    {
        int counter=0;
        for (int i=1;i<n;i++)
            counter+=solve(i)*solve(n-i);
        m[n]=counter;
    }
    return m[n];
}
