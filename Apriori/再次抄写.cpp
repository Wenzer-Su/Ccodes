#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
//每个事务的数据结构
typedef struct
{
    //存储事务数据记录
    int item[100];
}data_node;

//输入数据集数据库
data_node database[100];
//候选集和频繁集的数据域
data_node c_list[100][100],l_list[100][100];

//输入的最小支持度
int min_sup;

void input_from_dos();
void input_from_file();
void getC1();
void getCn(int n);
void getLn(int n);
void output(int n);

int main()
{
    int i,n;
    char choice;
    cout<<"Input F to input frome file,else input here"<<endl;
    cin>>choice;
    if (choice=='F')
    {
        input_from_file();
    }
    else
    {
        input_from_dos();
    }
    n=1;
    getC1();
    getLn(n);
    while (l_list[n][0].item[0]!=0)
    {
        //当存在频繁n项集时，就尝试生成n+1项候选集
        n++;
        getCn(n);
        getLn(n);
    }
    for (i=1;i<=n;i++)
    {
        output(i);
    }


    return 0;
}

void input_from_dos()
{
    int i,j,k,n,m;
    //先输入最小支持度和事务数量
    cin>>min_sup;
    cin>>n;
    //数据库中的事务个数
    database[0].item[0]=n;
    for (i=1;i<=n;i++)
    {
        cin>>m;
        //事务当中的记录数量
        database[i].item[0]=m;
        for (j=1;j<=m;j++)
        {
            cin>>database[i].item[j];
        }
    }
        for (i=1;i<=n;i++)
    {
        m=database[i].item[0];
        cout<<"第"<<i<<"个事务: 事务数量:";
        cout<<m<<" 事务数据:";
        for (j=1;j<=m;j++)
            cout<<database[i].item[j]<<' ';
        cout<<endl;
    }
}

void input_from_file()
{


}

//扫描数据库中的内容，生成候选集C1
void getC1()
{
     /* 将D放入C中，D[0]item[0]是交易集个数，D[i]item[0]是第i个交易集的数据项个数，
    D[1]item[1]到D[1]item[个数]是第一个交易集合的数据。
    c不管交易集个数，只看数据项。C[n][k].item[0]是候选集Cn的第k项的支持度，
    c[1][1]item[1]数据项，c[1][1]item[0]此数据项的个数。c[1][0]item[0]中no是不同数据项的个数。
    */
    int i,j,k;
    //不重复的记录个数
    int no=1;
    //标记当前记录是否和前面的有匹配
    int tmp=0;
    //1项集的个数初始化，置0
    c_list[1][0].item[0]=0;
    if (database[0].item[0]!=0)
    {
        //数据库中存在数据
        //将数据库的第一项事务放入到候选集中
        c_list[1][1].item[1]=database[1].item[1];
    }

    //枚举每项事务
    for (i=1;i<=database[0].item[0];i++)
    {
        //枚举该事务中的所有记录
        for (j=1;j<=database[i].item[0];j++)
        {
            //枚举候选集中现有的记录
            for (k=1;k<=no;k++)
            {
                //该项记录与候选集中的某一项匹配
                if (database[i].item[j]==c_list[1][k].item[1])
                {
                    //支持度+1
                    c_list[1][k].item[0]++;
                    break;
                }
            }
            //该记录未被加入到候选集
            if (tmp)
            {
                //候选集规模+1，将记录加入候选集，并置支持度为1
                no++;
                c_list[1][no].item[1]=database[i].item[j];
                c_list[1][no].item[0]=1;
            }
        }

    }
    //候选集规模，也就是候选集中有多少个项
    c_list[1][0].item[0]=no;

}

//用频繁集Ln-1为基础，通过连接得到n项候选集Cn
void getCn(int n)
{
    int i,j,k,p,q,s,t,number;
    //标记入库的联接事务个数
    int no=0;
    //标记
    int tmp=0;
    int counter;

    //Cn现在的个数为0，要枚举的数量是Ln-1的数量
    c_list[n][0].item[0];
    number=l_list[n-1][0].item[0];
    for (i=1;i<=number;i++)
    {
        for (j=i+1;j<=number;j++)
        {
            tmp=1;  //默认可以联接
            //n>2时，Ln-1有多个元素，需要枚举比对
            if (n>2)
            {
                //枚举Ln-1中的前n-2中，除最后一个都一样的才能联接到一起形成新的事务
                for (k=1;k<n-1;k++)
                {
                    if (l_list[n-1][i].item[k]!=l_list[n-1][j].item[k])
                    {
                        tmp=0;
                        break;
                    }
                }
            }
            //满足联接条件
            if (tmp==1)
            {
                //将Ln-1的第i个事务全部记录搬到C，再把第j个的最后一个记录搬到C
                no++;
                for (p=1;p<=n-1;p++)
                {
                    c_list[n][no].item[p]=l_list[n-1][i].item[p];
                }
                c_list[n][no].item[p]=l_list[n-1][j].item[p-1];
                c_list[n][no].item[0]=0;
                //计算其支持度
                for (q=1;q<=database[0].item[0];q++)
                {
                    counter=0;
                    //C的新增项有n个记录,n项集
                    for (s=1;s<=n;s++)
                    {
                        //枚举一条事务中的所有记录
                        for (t=1;t<=database[q].item[0];t++)
                        {
                            //确定这个事务中有没有与C当前这条事务中的第s个记录相等
                            if (c_list[n][no].item[s]==database[q].item[t])
                            {
                                counter++;
                                break;
                            }
                        }
                    }
                    if (counter==n)
                    {
                        c_list[n][no].item[0]++;
                    }
                }
                //一条新的事务成功建立到Cn中
                c_list[n][0].item[0]++;
            }

        }
    }
}

void getLn(int n)
{
    int i,j,k;
    //对频繁集已存入的数据项数量进行计数
    j=0;
    //频繁集的规模初始化置0
    l_list[n][0].item[0]=0;
    //枚举候选集中的每个事务
    for (i=1;i<=c_list[n][0].item[0];i++)
    {
        //支持度满足最小支持度
        if (c_list[n][i].item[0]>min_sup)
        {
            //频繁集数量+1，将候选集中当前事务的每个记录搬运到频繁集中，并将支持度搬进来
            j++;
            for (k=1;k<=n;k++)
            {
                l_list[n][j].item[k]=c_list[n][i].item[k];
            }
            l_list[n][j].item[0]=c_list[n][i].item[0];
        }
    }
    //记录频繁集中加入的事务数量
    l_list[n][0].item[0]=j;

}

void output(int n)
{
    int i,j,k;
    //频繁集中的事务数量
    k=l_list[n][0].item[0];
    if (k)
    {
        cout<<"频繁集 L"<<i<<" 如下:"<<endl;
        for (i=1;i<=k;i++)
        {
            cout<<'<';
            for (j=1;j<=n;j++)
            {
                cout<<' '<<l_list[n][i].item[j];
            }
            cout<<">    支持度:"<<l_list[n][i].item[0]<<endl;
        }
    }
    else
    {
        cout<<"迭代结束"<<endl;
    }
}
