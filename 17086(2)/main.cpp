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
    //��Ҫ����������Ԫ�أ�������һ��ʱ���Ͳ�Ҫ������
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
            swapVar(chList[k],chList[i]);   //��������Ԫ�غ͵�ǰԪ��
            perm(chList,k+1,m);             //��ʣ�ಿ�ֽ���ȫ����
            swapVar(chList[k],chList[i]);   //������
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
