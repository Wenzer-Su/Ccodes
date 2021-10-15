#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

//数据库D
typedef struct
{
    int item[100];  //事务数据项
}D_node;

//候选集C
typedef struct
{
    //数据项，用item[0]来存储支持度信息
    int item[100];
}C_node;

//频繁集L
typedef struct
{
    int item[100];
}L_node;

C_node C[100][100];
L_node L[100][100];
D_node D[100];

//最小支持度
int min_sup;

void input();
void C1();
void Cn(int n);
void Ln(int n);
void output(int n);

int main()
{
    int i;
    int n=1;
    input();
    C1();
    Ln(n);
    while(L[n][0].item[0]!=0)
    {
        n++;
        Cn(n);
        Ln(n);
    }
    for (i=1;i<=n;i++)
    {
        output(i);
    }
    return 0;
}

void input()
{
    /*
    n是交易集的大小
    m是输入的记录个数
    数据输入到D[100]中
    */
    int i,j,k,n,m;
    cout<<"最小支持度:";
    cin>>min_sup;
    cout<<"事务数量:";
    cin>>n;
    //0号记录数据数量，n在结束以后会丢失
    D[0].item[0]=n;
    for (i=1;i<=n;i++)
    {
        cout<<"第"<<i<<"个事务中有多少条记录:";
        cin>>m;
        D[i].item[0]=m;
        for (j=1;j<=m;j++)
            cin>>D[i].item[j];
    }

//    for (i=1;i<=n;i++)
//    {
//        cout<<"第"<<i<<"个事务: 事务数量:";
//        cout<<m<<" 事务数据:";
//        m=D[i].item[0];
//        for (j=1;j<=m;j++)
//            cout<<D[i].item[j]<<' ';
//        cout<<endl;
//    }


}

//扫描数据库D生成候选集C1
void C1()
{

}

void Cn(int n)
{
    /* 将D放入C中，D[0]item[0]是交易集个数，D[i]item[0]是第i个交易集的数据项个数，
    D[1]item[1]到D[1]item[个数]是第一个交易集合的数据。
    c不管交易集个数，只看数据项。C[n][k].item[0]是候选集Cn的第k项的支持度，
    c[1][1]item[1]数据项，c[1][1]item[0]此数据项的个数。c[1][0]item[0]中no是不同数据项的个数。
    */
    int i,j,k;
    //不重复的数据项个数
    int no=1;
    int tmp=0;
    //1项集个数置0
    C[1][0].item[0]=0;
    if (D[0].item[0]!=0)
    {
        //数据库不为空，则开始赋初值
        C[1][1].item[1]=D[1].item[1];
    }
}

void Ln(int n)
{

}

void output(int n)
{

}
