#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[10005];
int t[10005];
int count_inversion(int a[],int l,int r);
int merge_inversion(int a[],int l,int m,int r);
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int ans=count_inversion(a,0,n-1);
    cout<<ans<<endl;
    return 0;
}

int count_inversion(int a[],int l,int r)
{
    int counter=0;
    int middle;
    if (l<r)
    {
        middle=l+(r-l)/2;
        counter+=count_inversion(a,l,middle);
        counter+=count_inversion(a,middle+1,r);
        counter+=merge_inversion(a,l,middle,r);
    }
    return counter>0? counter:0;

}
int merge_inversion(int a[],int l,int m,int r)
{
    int counter=0;
    int i,j,k;
    i=l;
    j=m+1;
    while (i<=m&&j<=r)
    {
        if (a[i]>a[j])
        {
            counter+=m-i+1;
            //右段取一个更大的数与左段这个大数比较
            j++;
        }
        else
        {
            //左段的数不够大，要取一个更大的数
            i++;
        }
    }
    i=l;
    k=l;
    j=m+1;
    while (i<=m&&j<=r)
    {
        if (a[i]<=a[j])
        {
            t[k++]=a[i++];
        }
        else
        {
            t[k++]=a[j++];
        }
    }
    while (i<=m)
    {
        t[k++]=a[i++];
    }
    while (j<=r)
    {
        t[k++]=a[j++];
    }
    for (i=l;i<=r;i++)
    {
        a[i]=t[i];
    }
    return counter;
}
