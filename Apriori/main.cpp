#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct
{
    int item[100]; //������
} D_Node; //���ݿ�D

typedef struct
{
    int item[100]; //������,��item[0]����֧�ֶ�
} C_Node; //��ѡ��

typedef struct
{
    int item[100]; //������,��item[0]����֧�ֶ�
} L_Node;//Ƶ����

C_Node C[1000][1000];
L_Node L[1000][1000];
D_Node D[1000];

int min_supp; //��С֧�ֶ�

void InPut()
{
    //n�ǽ��׼��Ĵ�С��n1������ļ�¼�������������뵽D[100]��
    int i,j,k,n,m;
    cin>>min_supp;
    cin>>n;
    D[0].item[0]=n;
    for (i=1;i<=n;i++)
    {
        cin>>m;
        D[i].item[0]=m;
        for (j=1;j<=m;j++)
        {
            cin>>D[i].item[j];
        }
    }
//    int i,j,n,n1;//n�ǽ��׼��Ĵ�С��n1������ļ�¼�������������뵽D[100]��
//    printf("��С֧�ֶ�:");
//    scanf("%d",&min_supp);
//    printf("�������׼�¼��");
//    scanf("%d",&D[0].item[0]);
//    n=D[0].item[0];
//    for(i=1; i<=n; i++)
//    {
//        printf("��%d���������м�����Ʒ��",i);
//        scanf("%d",&n1);
//        D[i].item[0]=n1;
//        for(j=1; j<=n1; j++)
//        {
//            scanf("%d",&D[i].item[j]);
//        }
//
//    }

    cout<<"��������:"<<D[0].item[0]<<endl;
    for (i=1;i<=n;i++)
    {
        cout<<"��"<<i<<"������-->��¼����:"<<D[i].item[0]<<"  �����¼:";
        for (j=1;j<=D[i].item[0];j++)
        {
            cout<<D[i].item[j]<<' ';
        }
        cout<<endl;

    }
//    int i,j,n,n1;//n�ǽ��׼��Ĵ�С��n1������ļ�¼�������������뵽D[100]��
//    printf("��С֧�ֶ�:");
//    scanf("%d",&min_supp);
//    printf("�������׼�¼��");
//    scanf("%d",&D[0].item[0]);
//    n=D[0].item[0];
//    for(i=1; i<=n; i++)
//    {
//        printf("��%d���������м�����Ʒ��",i);
//        scanf("%d",&n1);
//        D[i].item[0]=n1;
//        for(j=1; j<=n1; j++)
//        {
//            scanf("%d",&D[i].item[j]);
//        }
//
//    }

}
//ɨ�����ݼ�D����1���ѡ��C1
void C1()
{


    /* ��D����C�У�D[0]item[0]�ǽ��׼�������D[1]item[0]�ǵ�һ�����׼��������������
    D[1]item[1]��D[1]item[����]�ǵ�һ�����׼��ϵ����ݡ�
    c���ܽ��׼�������ֻ�������C[n][k].item[0]�Ǻ�ѡ��Cn�ĵ�k���֧�ֶȣ�
    c[1][1]item[1]�����c[1][1]item[0]��������ĸ�����c[1][0]item[0]��no�ǲ�ͬ������ĸ�����
    */
    int i,j,k;
    int no=1,temp=0; //no�ǲ��ظ���������ĸ���
    C[1][0].item[0]=0; //1 ��ĸ������ڱ��㷨�У���C[n][k].item[0]�������ѡ��Cn�ĵ�k���֧�ֶ�
    if(D[0].item[0]!=0)
    {
        C[1][1].item[1]=D[1].item[1]; //����һ���������ֵ

    }

    for(i=1; i<=D[0].item[0]; i++) //���׼�
    {

        for(j=1; j<=D[i].item[0]; j++) // ĳ�����׼��еļ�¼
        {
            temp=1;
            for(k=1; k<=no; k++)   //no����ѡ����������ĸ���
            {
                if(C[1][k].item[1]==D[i].item[j])//һ���ѡ���ĵ�k���ֵ���ڵ�i�������е�j���ֵ
                {
                    C[1][k].item[0]++; //һ���ѡ���ĵ�k���֧�ֶȼ�1
                    temp=0;

                }
            }

            if(temp)//��i�������еĵ�j�����ں�ѡ����  ���  �����µ��
            {

                C[1][++no].item[1]=D[i].item[j];
                C[1][no].item[0]=1;
            }

        }

    }
    C[1][0].item[0]=no;//������ĸ���
}

void Cn( int n)
{
//��Ƶ����Ln-1Ϊ������ͨ�����ӵõ�n���ѡ��Cn
    int i,j,k,p,q,s,t,num;
    int no = 0, temp = 0, count;
    C[n][0].item[0] = 0; //��ʼ��
    num = L[n-1][0].item[0]; //num��Ln-1��ļ�¼����
    for(i = 1; i <= num; i++) //ɨ��Ƶ���
    {

        for(j = i+1; j <= num; j++)
        {

            temp = 1; //�����Ƿ�������������
            if(n > 2)//����һ���ʱ���������ظ���
            {
                for(k = 1; k < n-1; k++)
                {
                    if(L[n-1][i].item[k] != L[n-1][j].item[k])//��ͬλ������ͬ����ſ�������
                    {
                        temp = 0;
                        break;
                    }
                }
            }
            if(temp==1)//������������
            {
                no++;
                for(p = 1; p <= n-1; p++)
                    C[n][no].item[p] = L[n-1][i].item[p];  //��n-1��Ƶ����е�ǰn-1�����ѡ��

                C[n][no].item[p] = L[n-1][j].item[p-1];	//����p��ִ��p++֮��ģ�������p��1
                C[n][no].item[0] = 0;
                for(q = 1; q <= D[0].item[0]; q++) // ������֧�ֶ�
                {
                    count = 0; //count��������,�������Ե������ʱ,count��1,��count=nʱ�����Ӽ�����
                    for(s = 1; C[n][no].item[s] != 0; s++) //��n���ѡ���ĵ�no����¼�ĵ�s�����ݵ�ֵ
                    {
                        for(t = 1; t <= D[q].item[0]; t++) //������q����¼
                        {
                            if(C[n][no].item[s] == D[q].item[t]) //��ѡ���е�ֵ�ڼ�¼�и��ü�¼������һ
                            {
                                count += 1;
                                break;
                            }
                        }

                    }
                    if(count == n) //��n���ѡ���ĵ�no����¼
                        C[n][no].item[0] += 1;//�Ӽ�����,��no���֧�ֶȼ�1

                }

                C[n][0].item[0] += 1;
            }
        }
    }
}

void Ln(int n)
{
    int i,j,k;
    j=0;
    L[n][0].item[0]=0; //��n��Ƶ�����0��������ĸ�����0
    for(i=1; i<=C[n][0].item[0]; i++) //ɨ���ѡ������
    {
        if(C[n][i].item[0]>=min_supp) //��n���ѡ���е�i����¼�ĸ���  >  ��С֧�ֶ�
        {
            j+=1;
            for(k=1; k<=n; k++)//��n���ѡ���е�j����¼����k��������
                L[n][j].item[k]=C[n][i].item[k];  //��ѡ����ӵ�Ƶ�����
            L[n][j].item[0]=C[n][i].item[0];  //��� ��n���ѡ���е�j����¼ �ĸ���  ��֧�ֶ�
        }

    }

    L[n][0].item[0]=j; //Ƶ��n��еļ�¼�ĸ���
}

void outPutString(int x)
{
    switch(x)
    {
    case 11:
        cout<<"Cardiacfailure";
        break;
    case 22:
        cout<<"Myocardialinfarction";
        break;
    case 33:
        cout<<"uremia";
        break;
    case 44:
        cout<<"diabetes";
        break;
    case 55:
        cout<<"Renalfailure";
        break;
    case 66:
        cout<<"Other";
        break;
    default:
        cout<<x;

    }
    return;
}

void OutPut(int n)
{
    int i,j,k;
    k=L[n][0].item[0];
    if (k)
    {
        printf("\nƵ���L%d����:\n",n);
        for (i=1;i<=k;i++)
        {
            cout<<"< ";
            for (j=1;j<=n;j++)
            {
                outPutString(L[n][i].item[j]);
                cout<<' ';
            }
            printf(">  ֧�ֶ�:%d\n",L[n][i].item[0]);
        }
    }
    else
    {
        cout<<"��������"<<endl;
    }

//    k=L[n][0].item[0];//n��Ƶ��������k����¼
//    if(k!=0)
//    {
//        printf("\nƵ���L%d����:\n",n);
//        for(i=1; i<=k; i++)
//        {
//
//            for(j=1; j<=n; j++) //n��Ƶ������ÿ����¼��n��������
//                printf(" %d ",L[n][i].item[j]);
//            printf("  ֧�ֶ�:%d\n",L[n][i].item[0]);
//
//        }//for
//
//    }
//    else
//        printf("��������\n");
}

int main()
{
    int i;
    int n=1;
    InPut();
    C1();//��ʼ��,����1���ѡ��C1
    Ln(1);//�õ�1��Ƶ����L1
    while(L[n][0].item[0]!=0)
    {
        n+=1;
        Cn(n);
        Ln(n);
    }
    for(i=1; i<=n; i++)
        OutPut(i);
}
