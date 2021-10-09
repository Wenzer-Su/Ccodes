#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;


int fun(int x[],int y[],int xbeg,int xend,int ybeg,int yend,int k)
{
    //X序列为空时，直接返回Y序列的第k小元素。
    if (xbeg > xend) return y[ybeg + k - 1];
    //Y序列为空时，直接返回X序列的第k小元素。
    if (ybeg > yend) return x[xbeg + k - 1];

    int xmid = (xbeg+xend)/2;//x的中间位置
    int ymid = (ybeg+yend)/2;//y的中间位置
    int halfLen = xmid-xbeg+ymid-ybeg+2;//x和y的左段元素个数之和
    if (x[xmid]<y[ymid])
    {
        if (k<halfLen)
        {
            //此时第k大的元素一定小于Y[yMid]这个元素，所以要mid-1
            //此时只需递归的对X序列+Y序列的前半段，去搜索第k小的数。
            fun(x,y,xbeg,xend,ybeg,ymid-1,k);

        }
        else
        {
            //此时第k大的元素一定大于X[xMid]这个元素，所以要mid+1
            //此时只需递归的对X序列的后半段+Y序列,去搜索第 k-(xMid-xBeg+1）小的数。
            fun(x,y,xmid+1,xend,ybeg,yend,k-(xmid-xbeg+1));
        }
    }
    else
    {
        if(k<halfLen)
        {
            //此时第k大的元素一定小于X[xMid]这个元素，mid-1
            //此时只需递归的对X序列的前半段+Y序列，去搜索第k小的数。
            fun(x,y,xbeg,xmid-1,ybeg,yend,k);
        }
        else
        {
            //此时第k大的元素一定大于Y[yMid]这个元素，mid+1
            //此时只需递归的对X序列+Y序列的后半段，去搜索第 k-(yMid-yBeg+1）小的数。
            fun(x,y,xbeg,xend,ymid+1,yend,k-(ymid-ybeg+1));
        }
    }
}

int main()
{
    int m,n,k;
    scanf("%d %d %d",&m,&n,&k);
    int x[m],y[n];
    int halfLen = m+n;
    for (int i=0;i<m;i++)
    {
        scanf("%d",&x[i]);
    }
    for (int i=0;i<n;i++)
    {
        scanf("%d",&y[i]);
    }
    printf("%d",fun(x,y,0,m-1,0,n-1,k));
    return 0;
}

