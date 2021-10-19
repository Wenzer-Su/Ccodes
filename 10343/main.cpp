/*
10343 划分凸多边形

问题描述：一个正凸N边形，可以用N-3条互不相交的对角线将正N边形分成N-2个三角形。
现在要求读入N边形的N（N≤20），输出不同划分方法的总数（要求解的是划分方法数，而不需要输出各种划分法）

Total(N) = sum{ Total(I)*Total(N+1-I) | for I=2 to N-1}   if N>=4
Total(2) = Total(3) = 1

*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

map<int,int> m;
int getTotal(int n)
{
    if (m.find(n)==m.end())
    {
        int counter=0;
        for (int i=2;i<=n-1;i++)
        {
            counter+=getTotal(i)*getTotal(n-i+1);
        }
        m[n]=counter;
    }
    return m[n];

}
using namespace std;
int main()
{
    int n;
    cin>>n;
    if (n<=2)
    {
        cout<<"No answer"<<endl;
        return 0;
    }
    m[2]=1;
    m[2]=1;

    cout<<getTotal(n)<<endl;

    return 0;
}
