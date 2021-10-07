#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long counter=0;
void swapVar(char &x,char &y)
{
    char t=x;
    x=y;
    y=t;
    return;
}
bool isSame(char chList[],long k,long m)
{
    //当要交换的两个元素，内容是一样时，就不要交换了
    for (int i=k;i<m;i++)
    {
        if (chList[m]==chList[i])
            return true;
    }
    return false;
}
void perm(char chList[],long k,long m)
{
    if (k==m)
    {
        counter++;
//        cout<<++counter<<' ';
        for (int i=0;i<=m;i++)
        {
            cout<<chList[i];
        }
        cout<<endl;
    }
    else
    {
        for (int i=k;i<=m;i++)
        {
            if (isSame(chList,k,i))
            {
                continue;
            }
            swapVar(chList[k],chList[i]);   //交换最左元素和当前元素
            perm(chList,k+1,m);             //对剩余部分进行全排列
            swapVar(chList[k],chList[i]);   //换回来
        }
    }
}
int main()
{
    long n;
    cin>>n;
    char chList[n];
    scanf("%s",chList);
    perm(chList,0,n-1);
    cout<<counter<<endl;
    return 0;

}
