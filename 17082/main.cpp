#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;



int solution(int a[],int b[],int a_begin,int a_end,int b_begin,int b_end,int k)
{
    if (a_begin>a_end)
    {
        //此时a数组为空，所有的查找都在b数组内
        //由于数组从0开始算，所以要b_begin+k-1
        return b[b_begin+k-1];
    }
    if (b_begin>b_end)
    {
        //此时b数组为空，所有的查找都在a数组内
        return a[a_begin+k-1];
    }

    //a.b数组的中间位置
    int a_mid=(a_begin+a_end)/2;
    int b_mid=(b_begin+b_end)/2;


    /*
    表示半部分数据的数量
    由于从0开始算，所以要+1
    如0--3，实际有4个元素，所以3-0+1
    */
    int half_len=(a_mid-a_begin+1)+(b_mid-b_begin+1);

    /*
    以两数组的中位数来做分支
    用以舍弃较大者的后半段或者较小者的前半段
    */
    if (a[a_mid]<b[b_mid])
    {
        //此时a的前半段都存在于b[mid]的左侧
        if (k<half_len)
        {
            /*
            此时第k小一定小于b[mid]，所以可以舍弃b的右半部分
            因为k<half_len，所以第k小必定小于b[mid]，所以b_mid-1
            */
            //舍弃了b的右半部分，保留了a全部和b[0--mid-1]
             return solution(a,b,a_begin,a_end,b_begin,b_mid-1,k);

        }
        else
        {
            /*
            此时第k小一定大于a[mid]，所以舍弃a的左半部分，因此a_mid+1
            保留a[mid+1--end]和b全部
            */
            //k要去掉a[0--mid]全段，因为从0开始，所以+1，同上面一样
             return solution(a,b,a_mid+1,a_end,b_begin,b_end,k-(a_mid-a_begin+1));
        }

    }
    else
    {
        //此时b的前半段都位于a[mid]的左侧
        if (k<half_len)
        {
             return solution(a,b,a_begin,a_mid-1,b_begin,b_end,k);
        }
        else
        {
             return solution(a,b,a_begin,a_end,b_mid+1,b_end,k-(b_mid-b_begin+1));
        }
    }

}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    //输入数值以后再分配空间，节省内存
    int a[n],b[m];
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<m;i++)
        cin>>b[i];
    cout<<solution(a,b,0,n-1,0,m-1,k);
//    cout<<endl;
//    for (int i=0;i<n;i++)
//        cout<<a[i]<<' ';
//    cout<<endl;
//    for (int i=0;i<m;i++)
//        cout<<b[i]<<' ';
    return 0;
}


/*
假设：X序列为X[xBeg…xEnd]，而Y序列为Y[yBeg…yEnd]。

将序列X和Y都均分2段，即取X序列中间位置为 xMid (xMid = xBeg+(xEnd-xBeg)/2)，也同理取序列Y中间位置为yMid。
比较X[xMid]和Y[yMid]的大小，此时记录X左段和Y左段元素个数合计为halfLen，即halfLen = xMid-xBeg+yMid-yBeg+2。

当X[xMid] < Y[yMid]时，在合并的数组中，原X[xBeg…xMid]所有元素一定在Y[yMid]的左侧，
（1） 若k < halfLen，则此时第k大的元素一定不会大于Y[yMid]这个元素，
故以后没有必要搜索 Y[yMid…yEnd]这些元素，可弃Y后半段数据。
此时只需递归的对X序列+Y序列的前半段，去搜索第k小的数。

（2） 若k >= halfLen，则此时第k大的元素一定不会小于X[xMid]这个元素，
故以后没有必要搜索 X[xBeg…xMid]这些元素，可弃X前半段数据。
此时只需递归的对X序列的后半段+Y序列，去搜索第 k-(xMid-xBeg+1）小的数。

当X[xMid] >= Y[yMid]时，在合并的数组中，原Y[yBeg…yMid]的所有元素一定在X[xMid]的左侧，
（1） 若k < halfLen，则此时第k大的元素一定不会大于X[xMid]这个元素，
故以后没有必要搜索 X[xMid…xEnd]这些元素，可弃X后半段数据。
此时只需递归的对X序列的前半段+Y序列，去搜索第k小的数。

（2） 若k >= halfLen，则此时第k大的元素一定不会小于Y[yMid]这个元素，
故以后没有必要搜索 Y[yBeg…yMid]这些元素，可弃Y前半段数据。
此时只需递归的对X序列+Y序列的后半段，去搜索第 k-(yMid-yBeg+1）小的数。

递归的边界，如何来写？

if (xBeg > xEnd) return Y[yBeg + k - 1]; //X序列为空时，直接返回Y序列的第k小元素。
if (yBeg > yEnd) return X[xBeg + k - 1]; //Y序列为空时，直接返回X序列的第k小元素。
效率分析：

T(m,n)表示对长度为m的有序的X序列和长度为n的有序的Y序列，搜索第k小元素的复杂度。
T(m,n)=1 m=0或n=0
T(m,n) <= max{T(m/2,n), T(m,n/2)} + O(1)

则T(m,n) = O(max{logm, logn})

*/
