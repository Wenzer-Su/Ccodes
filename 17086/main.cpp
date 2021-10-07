#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
long a[1000];
int main()
{
    long n;
    char ch;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>ch;
        a[i]=ch-'0';
    }
    sort(a,a+n);

    long counter=1;
    do
    {
        cout<<counter++<<' ';
        for (int i=0; i<n; i++)
        {
            cout<<a[i];
        }
        cout<<endl;
    }
    while(next_permutation(a,a+n));
    return 0;
}
