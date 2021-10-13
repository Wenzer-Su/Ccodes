#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[105][105];
int m[105][105];
int p[105][105][2];
int main()
{
    int n;
    int i,j,k;
    cin>>n;
//    cout<<n<<endl;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=i;j++)
        {
            cin>>a[i][j];
            m[i][j]=a[i][j];
            p[i][j][0]=i;
            p[i][j][1]=j;
        }
    }

    for (i=n-1;i>0;i--)
    {
        for (j=1;j<=i;j++)
        {
            if (m[i+1][j]>m[i+1][j+1])
            {
                m[i][j]=m[i+1][j]+a[i][j];
                p[i][j][0]=i+1;
                p[i][j][1]=j;
            }
            else
            {
                m[i][j]=m[i+1][j+1]+a[i][j];
                p[i][j][0]=i+1;
                p[i][j][1]=j+1;
            }
        }
    }
    cout<<m[1][1]<<endl;
    int x=1;
    int y=1;
    int x1,y1;
    for (i=1;i<=n;i++)
    {
        cout<<a[x][y]<<' ';
        x1=x;
        y1=y;
        x=p[x1][y1][0];
        y=p[x1][y1][1];
    }
//    for (i=1;i<n;i++)
//    {
//        cout<<a[x][y]<<' ';
//        int x1=x;
//        int y1=y;
//        x=p[x1][y1][0];
//        y=p[x1][y1][1];
//    }

    return 0;
}
