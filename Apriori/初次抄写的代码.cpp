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
    Ln(1);
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

    for (i=1;i<=n;i++)
    {
        cout<<"第"<<i<<"个事务: 事务数量:";
        cout<<m<<" 事务数据:";
        m=D[i].item[0];
        for (j=1;j<=m;j++)
            cout<<D[i].item[j]<<' ';
        cout<<endl;
    }


}

//扫描数据库D生成候选集C1
void C1()
{
    /* 将D放入C中，D[0]item[0]是交易集个数，D[i]item[0]是第i个交易集的数据项个数，
    D[1]item[1]到D[1]item[个数]是第一个交易集合的数据。
    c不管交易集个数，只看数据项。C[n][k].item[0]是候选集Cn的第k项的支持度，
    c[1][1]item[1]数据项，c[1][1]item[0]此数据项的个数。c[1][0]item[0]中no是不同数据项的个数。
    */
    int i,j,k;
    //不重复的数据项个数
    int no=1;
    //标记当前的记录是否匹配相同
    int tmp=0;
    //1项集个数置0
    C[1][0].item[0]=0;
    if (D[0].item[0]!=0)
    {
        //数据库不为空，则开始赋初值
        C[1][1].item[1]=D[1].item[1];
    }

    for (i=1;i<=D[0].item[0];i++)
    {
        //遍历每个事务
        for (j=1;j<=D[i].item[0];j++)
        {
            //遍历每个事务的各个数据
            tmp=1;
            for (k=1;k<=no;k++)
            {
                if (C[1][k].item[1]==D[i].item[j])
                {
                    //一项候选集的第k项的值等于第i条交易中第j项的值
                    //支持度+1
                    C[1][k].item[0]++;
                    tmp=0;
                }

            }
            if (tmp)
            {
                //第i条事务的第j项记录不在候选集中
                no++;
                //登记记录项
                C[1][no].item[1]=D[i].item[j];
                //记录支持度
                C[1][no].item[0]=1;
            }

        }
    }
    //更新这一组有多少个数据项
    C[1][0].item[0]=no;
}

//用频繁集Ln-1为基础，通过连接得到n项候选集Cn
void Cn(int n)
{
    int i,j,k,p,q,s,t,num;
    int no=0;   //不重复的数据项，初始置0
    int tmp=0;  //标记当前记录是否存在匹配
    int counter;

    C[n][0].item[0]=0;
    //Ln-1的项数，也是需要枚举的项集数
    num=L[n-1][0].item[0];
    for (i=1;i<=num;i++)
    {
        //枚举Ln-1每一个项
        for (j=i+1;j<=num;j++)
        {
            //枚举后面的数据项，做笛卡尔积
            //能否联接的标记,默认可行
            tmp=1;
            if (n>2)
            {
                for (k=1;k<=n-2;k++)
                {
                    //除最后一项外，前面的项都要一样才满足联接条件
                    if (L[n-1][i].item[k]!=L[n-1][j].item[k])
                    {
                        tmp=0;
                        break;
                    }

                }
            }
            // 可以联接
            if (tmp)
            {
                no++;
                for (p=1;p<=n-1;p++)
                {
                    //把Ln-1的前n-1项搬到Cn中
                    C[n][no].item[p]=L[n-1][i].item[p];
                }
                //把j的最后一项作为第n个记录加入到新的候选集中，形成新的频繁项
                C[n][no].item[p]=L[n-1][j].item[p-1];
                //支持度暂时还是0，初始化
                C[n][no].item[0]=0;

                //测试新建立的项支持度
                for (q=1;q<=D[0].item[0];q++)
                {
                    //枚举数据库当中所有的事务
                    counter=0;
                    for (s=1;C[n][no].item[s]!=0;s++)
                    {
                        //当前频繁项的所有记录数据
                        for (t=1;t<=D[q].item[0];t++)
                        {
                            if (C[n][no].item[s]==D[q].item[t])
                            {
                                //在事务的记录当中，找到相等的
                                counter++;
                                break;
                            }
                        }

                    }
                    if (counter==n)
                    {
                        //在数据库的事务中找到可以在一个事务中包含当前数据项所有记录的事务，也就是子集
                        //那么支持度可以+1
                        C[n][no].item[0]++;
                    }
                }
            }
        }
    }

}

void Ln(int n)
{
    int i,j,k;
    //第n项频繁项集第0个数据项的个数是0
    j=0;
    L[n][0].item[0]=0;
    for (i=1;i<=C[n][0].item[0];i++)
    {
        //枚举候选集
        if (C[n][i].item[0]>=min_sup)
        {
            j++;    //频繁集的计数
            for (k=1;k<=n;k++)
            {
                //将候选集中的n个记录搬到频繁集中
                L[n][j].item[k]=C[n][i].item[k];
            }
            //搬运其支持度
            L[n][j].item[0]=C[n][i].item[0];

        }
    }
    //记录频繁集中的项数
    L[n][0].item[0]=j;
}

void output(int n)
{
    int i,j,k;
    //频繁项集中的项数
    k=L[n][0].item[0];
    if (k)
    {
        //频繁项集中存在项
        printf("\n频繁项集L%d如下:\n",n);
        for (i=1;i<=k;i++)
        {
            //遍历频繁项集
            cout<<'<';
            for (j=1;j<=n;j++)
            {
                //输出频繁项集中的每一个记录
                cout<<L[n][i].item[j]<<',';
            }
            cout<<">    "<<"支持度:"<<L[n][i].item[0]<<endl;
        }
    }
    else
    {
        cout<<"迭代结束"<<endl;
    }
}
