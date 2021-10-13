
/*
11088 整数划分的扩展问题（优先做）

下面有整数划分问题扩展出的多个题例：
（1）正整数n划分为若干正整数之和，最大加数不超过m的划分数
（2）正整数n划分为不超过m个正整数之和的划分数
（3）正整数n划分为若干正奇整数之和的划分数
（4）正整数n划分为互不相同正整数之和的划分数
约定：
整数划分无顺序，比如对7划分，认为2 2 3和3 2 2和2 3 2为同一种划分。
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int q(int n,int m);
int odd(int n,int m);
int even(int n,int m);
int solve(int n,int m);
int main()
{
    int ans;    //1、2题答案一样
    int ans3;
    int n,m;
    cin>>n>>m;
    /*
    1,2答案相同
    1分析数值关系
    */
    ans=q(n,m);
    ans3=0;
    for (int i=1;i<=n;i++)
    {
        ans3+=odd(n,i);
    }
    cout<<ans<<' '<<ans<<' '<<ans3<<' '<<ans3<<endl;
    return 0;
}

int solve(int n,int m)
{
    if (n==1)
    {
        if (m==1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (m==0)
    {
        return 1;
    }

    if (m<0)
    {
        return 0;
    }


    return solve(n-1,m)+solve(n-1,m-1);
}

int q(int n,int m)
{
    if (n<1||m<1) {
        //随便一个是0都没法分
        return 0;
    }

    if (n==1&&m==1) {
        //1往下再分1份，都是只有一个分法
        return 1;
    }

    if (n<m) {
        //当m>n时，事实上就是q(n,n)
        return q(n,n);
    }

    if (n==m) {
        //此时划分的方式是n1=n和n1<=n-1来划分
        return 1+q(n,n-1);
    }


    return q(n,m-1)+q(n-m,m);
}


/*
把n划分成n个正奇数
*/
int odd(int n,int m)
{
    if (m>n||m<0)
    {
        //份数大过数值本身，无法计算
        return 0;
    }
    if (n==1&&m==1)
    {
        return 1;
    }
    if (n==2&&m==1)
    {
        //2没法拆成1份奇数
        return 0;
    }
    if (n==2&&m==2)
    {
        //2拆成两个1，刚好两份奇数
        return 1;
    }

    //1是奇数，减去1，抵掉一份，剩下的m-1份继续往下拆分
    //m个奇加数各减去1，就是m个偶数，所以求m个偶加数再各+1
    return odd(n-1,m-1)+even(n-m,m);

}


/*
把n划分成m个正偶数
*/
int even(int n,int m)
{
    if (m>n||m<=0)
    {
        //这两种情况没法分
        //除非m==0,但这就是0份
        return 0;
    }

    if (n==1&&m==1)
    {
        //1不可以拆成1个偶数
        return 0;
    }

    if (n==2&&m==2)
    {
        //2只能拆成一个2，一份，没法拆成两份
        return 0;
    }
    if (n==2&&m==1)
    {
        //2刚好就是1个2
        return 1;
    }

    //分成m个偶数，每个加数都减掉1，变成m个奇数，加回这个1就是m个偶加数
    return odd(n-m,m);

}

/*
这四个问题，不但要分析递归关系，还要正确写出递归的边界，有时边界值错一个，结果都不一定对，因此要小心。

1, 问题（1）即为书上例2-5。
(1) q(n,1)=1,n1;
当最大加数n1不大于1时，任何正整数n只有一种划分形式
(2) q(n,m)=q(n,n),mn;
最大加数n1实际上不能大于n。因此，q(1,m)=1。
(3) q(n,n)=1+q(n,n-1);
正整数n的划分由n1=n的划分和n1<=n-1的划分组成。
(4) q(n,m)=q(n,m-1)+q(n-m,m),n>m>1;
正整数n的最大加数n1不大于m的划分由n1=m的划分和
n1<=m-1 的划分组成。



2, 问题（2）也可以这样来想：
设d[i][j]表示i划分为j份，视为i个球放入j个盒子的方法数。d[n][m]为题目问题（2）所求，d[i][j]有如下递推关系：
（1）j个盒子有空的，d[i][j]=d[i][j-1]，把某一空盒子拿出来放一边
（2）j个盒子都不空，d[i][j]=d[i-j][j]，每个盒子扣掉1个球
因此，d[i][j] = d[i][j-1] + d[i-j][j]， j>1;
特别的有： d[k][0]=0,k>=1; d[k][1]=1,k>=1

3, 问题（1）和问题（2）是结果是相同的。
可以证明，任何一个问题（1）的解都可以转化为另一个问题（2）的解，一一对应，因此记数相同。
这个证明思路可以参考如下：
对正整数n进行划分，不超过m个的划分，视为n块立方体积木堆成m列，垂直的来看n=n1+n2+...+nm。
对每一个堆法，将视角旋转90度，即水平方向上看，其实都对应一个最大加数不超过m的划分。
因此，对正整数n进行划分，不超过m个的划分，换种视角，都对应于一个最大加数不超过m的划分。反之亦然。
所以，这种对应是一一对应。
不超过m个加数的划分数 = 最大加数不超过m的划分数。

4, 设： Odd(I,J)表示I划分为J个正奇数的划分数; Even(I,J)表示I划分为J个正偶数的划分数.
有如下递推关系：
（1）Even(I,J) = Odd(I-J,J), 每个偶加数减掉1变为奇加数
（2）Odd(I,J) = Odd(I-1,J-1) + Even(I-J,J)， 加数含1的方式数 + 加数不含1的方式数
（3）特别的：  J>I || J<0, Odd(I,J)=0;
             Odd(1,1)=1, Odd(2,1)=0, Odd(2,2)=1
             J>I || J<0, Even(I,J)=0;
             Even(1,1)=0, Even(2,1)=1, Even(2,2)=0

5, 思想： 转化为子集和问题： 集合{1,2,…,n}，挑选若干正整数，使之和为n，这也是一个背包装物品问题。
设F(I,J)： 表示挑选集合前I个，使之和为J的方式数。
递推关系： F(I,J) = F(I-1,J) + F(I-1,J-I)， 第I个不挑的方式数 + 挑第I个的方式数
递推边界： F(1,1)=1, F(1,k)=0(k>1), F(I,k)=0(k<0), F(I,0)=1(I>0)（这里一个都没挑，值为0，也是一种方式，所以为1）

6, 其实这第(4)个问题的解也和第(3)问题的解是相同的，但我还未能证明，请同学们给我思路。
*/