#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
long nums[20];
long len_nums=0;
map<long,long> m;
void ini_nums()
{
    long couonter=1;
    for (int i=0;i<15;i++)
    {
        nums[len_nums++]=couonter;
        couonter*=2;
    }
}

long solve(long n,long x)
{
    //n是要被拆分的数，x是数组里拆分数上限的下标
    if (n==0)
        return 1;
    if (m.find(n))
        return m.
}

int main()
{
    ini_nums();
    m.insert(pair<long,long>(1,1));
    m.insert(pair<long,long>(2,2));
    long n;
    cin>>n;
    long x=len_nums-1;
    while(nums[x]>n&&x>0)
    {
        x--;
    }
//    for (int i=0;i<len_nums;i++)
//    {
//        cout<<nums[i]<<' ';
//    }
//    cout<<endl;
//    for (int i=0;i<=x;i++)
//    {
//        cout<<nums[i]<<' ';
//    }
    return 0;
}
