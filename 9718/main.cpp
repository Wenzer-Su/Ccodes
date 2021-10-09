#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

long solve(long n)
{
    if (n==1)
        return 1;
    long i;
    long ans=0;
    for (i=2;i<=n;i++)
    {
        if (n%i==0)
        {
            ans+=solve(n/i);
        }
    }
    return ans;
}

int main()
{
    long n;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}
