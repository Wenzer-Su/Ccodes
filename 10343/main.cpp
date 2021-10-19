/*
10343 ����͹�����

����������һ����͹N���Σ�������N-3�������ཻ�ĶԽ��߽���N���ηֳ�N-2�������Ρ�
����Ҫ�����N���ε�N��N��20���������ͬ���ַ�����������Ҫ�����ǻ��ַ�������������Ҫ������ֻ��ַ���

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
