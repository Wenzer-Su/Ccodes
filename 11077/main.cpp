#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int dp[10005][10005];
int main()
{
    string a,b;
    int i,j,len_a,len_b;
    int loc,max_len;
    loc=max_len=0;
    cin>>a;
    cin>>b;
    len_a=a.size();
    len_b=b.size();
    for (i=0;i<len_a;i++)
        dp[i][0]=0;
    for (j=0;j<len_b;j++)
        dp[0][j]=0;
    for (i=0;i<len_a;i++)
    {
        for (j=0;j<len_b;j++)
        {
            if (a[i]==b[j])
            {
                if (i==0||j==0)
                {
                    dp[i][j]=1;
                }
                else
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                if (dp[i][j]>max_len)
                {
                    max_len=dp[i][j];
                    loc=j;
                }
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    cout<<max_len<<endl;
    for (i=loc-max_len+1;i<=loc;i++)
        cout<<b[i];
    return 0;
}
