#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

//���ݿ�D
typedef struct
{
    int item[100];  //����������
}D_node;

//��ѡ��C
typedef struct
{
    //�������item[0]���洢֧�ֶ���Ϣ
    int item[100];
}C_node;

//Ƶ����L
typedef struct
{
    int item[100];
}L_node;

C_node C[100][100];
L_node L[100][100];
D_node D[100];

//��С֧�ֶ�
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
    n�ǽ��׼��Ĵ�С
    m������ļ�¼����
    �������뵽D[100]��
    */
    int i,j,k,n,m;
    cout<<"��С֧�ֶ�:";
    cin>>min_sup;
    cout<<"��������:";
    cin>>n;
    //0�ż�¼����������n�ڽ����Ժ�ᶪʧ
    D[0].item[0]=n;
    for (i=1;i<=n;i++)
    {
        cout<<"��"<<i<<"���������ж�������¼:";
        cin>>m;
        D[i].item[0]=m;
        for (j=1;j<=m;j++)
            cin>>D[i].item[j];
    }

//    for (i=1;i<=n;i++)
//    {
//        cout<<"��"<<i<<"������: ��������:";
//        cout<<m<<" ��������:";
//        m=D[i].item[0];
//        for (j=1;j<=m;j++)
//            cout<<D[i].item[j]<<' ';
//        cout<<endl;
//    }


}

//ɨ�����ݿ�D���ɺ�ѡ��C1
void C1()
{

}

void Cn(int n)
{
    /* ��D����C�У�D[0]item[0]�ǽ��׼�������D[i]item[0]�ǵ�i�����׼��������������
    D[1]item[1]��D[1]item[����]�ǵ�һ�����׼��ϵ����ݡ�
    c���ܽ��׼�������ֻ�������C[n][k].item[0]�Ǻ�ѡ��Cn�ĵ�k���֧�ֶȣ�
    c[1][1]item[1]�����c[1][1]item[0]��������ĸ�����c[1][0]item[0]��no�ǲ�ͬ������ĸ�����
    */
    int i,j,k;
    //���ظ������������
    int no=1;
    int tmp=0;
    //1�������0
    C[1][0].item[0]=0;
    if (D[0].item[0]!=0)
    {
        //���ݿⲻΪ�գ���ʼ����ֵ
        C[1][1].item[1]=D[1].item[1];
    }
}

void Ln(int n)
{

}

void output(int n)
{

}
