#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long numbers[10005][2];
int main()
{
    long n,i,j;
    cin>>n;
    do
    {
        long maxLen=1;
        for (i=0;i<n;i++)
        {
            cin>>numbers[i][0];
            numbers[i][1]=1;
        }
        for (i=1;i<n;i++)
        {
            for (j=0;j<i;j++)
            {
                if (numbers[i][0]>numbers[j][0])
                {
                    numbers[i][1]=max(numbers[i][1],numbers[j][1]+1);
                }
            }
            if (numbers[i][1]>maxLen)
            {
                maxLen=numbers[i][1];
            }
        }
        cout<<maxLen<<endl;
        cin>>n;
    }while(n);
    return 0;
}
