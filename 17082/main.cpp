#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;



int solution(int a[],int b[],int a_begin,int a_end,int b_begin,int b_end,int k)
{
    if (a_begin>a_end)
    {
        //��ʱa����Ϊ�գ����еĲ��Ҷ���b������
        //���������0��ʼ�㣬����Ҫb_begin+k-1
        return b[b_begin+k-1];
    }
    if (b_begin>b_end)
    {
        //��ʱb����Ϊ�գ����еĲ��Ҷ���a������
        return a[a_begin+k-1];
    }

    //a.b������м�λ��
    int a_mid=(a_begin+a_end)/2;
    int b_mid=(b_begin+b_end)/2;


    /*
    ��ʾ�벿�����ݵ�����
    ���ڴ�0��ʼ�㣬����Ҫ+1
    ��0--3��ʵ����4��Ԫ�أ�����3-0+1
    */
    int half_len=(a_mid-a_begin+1)+(b_mid-b_begin+1);

    /*
    �����������λ��������֧
    ���������ϴ��ߵĺ��λ��߽�С�ߵ�ǰ���
    */
    if (a[a_mid]<b[b_mid])
    {
        //��ʱa��ǰ��ζ�������b[mid]�����
        if (k<half_len)
        {
            /*
            ��ʱ��kСһ��С��b[mid]�����Կ�������b���Ұ벿��
            ��Ϊk<half_len�����Ե�kС�ض�С��b[mid]������b_mid-1
            */
            //������b���Ұ벿�֣�������aȫ����b[0--mid-1]
             return solution(a,b,a_begin,a_end,b_begin,b_mid-1,k);

        }
        else
        {
            /*
            ��ʱ��kСһ������a[mid]����������a����벿�֣����a_mid+1
            ����a[mid+1--end]��bȫ��
            */
            //kҪȥ��a[0--mid]ȫ�Σ���Ϊ��0��ʼ������+1��ͬ����һ��
             return solution(a,b,a_mid+1,a_end,b_begin,b_end,k-(a_mid-a_begin+1));
        }

    }
    else
    {
        //��ʱb��ǰ��ζ�λ��a[mid]�����
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
    //������ֵ�Ժ��ٷ���ռ䣬��ʡ�ڴ�
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
���裺X����ΪX[xBeg��xEnd]����Y����ΪY[yBeg��yEnd]��

������X��Y������2�Σ���ȡX�����м�λ��Ϊ xMid (xMid = xBeg+(xEnd-xBeg)/2)��Ҳͬ��ȡ����Y�м�λ��ΪyMid��
�Ƚ�X[xMid]��Y[yMid]�Ĵ�С����ʱ��¼X��κ�Y���Ԫ�ظ����ϼ�ΪhalfLen����halfLen = xMid-xBeg+yMid-yBeg+2��

��X[xMid] < Y[yMid]ʱ���ںϲ��������У�ԭX[xBeg��xMid]����Ԫ��һ����Y[yMid]����࣬
��1�� ��k < halfLen�����ʱ��k���Ԫ��һ���������Y[yMid]���Ԫ�أ�
���Ժ�û�б�Ҫ���� Y[yMid��yEnd]��ЩԪ�أ�����Y�������ݡ�
��ʱֻ��ݹ�Ķ�X����+Y���е�ǰ��Σ�ȥ������kС������

��2�� ��k >= halfLen�����ʱ��k���Ԫ��һ������С��X[xMid]���Ԫ�أ�
���Ժ�û�б�Ҫ���� X[xBeg��xMid]��ЩԪ�أ�����Xǰ������ݡ�
��ʱֻ��ݹ�Ķ�X���еĺ���+Y���У�ȥ������ k-(xMid-xBeg+1��С������

��X[xMid] >= Y[yMid]ʱ���ںϲ��������У�ԭY[yBeg��yMid]������Ԫ��һ����X[xMid]����࣬
��1�� ��k < halfLen�����ʱ��k���Ԫ��һ���������X[xMid]���Ԫ�أ�
���Ժ�û�б�Ҫ���� X[xMid��xEnd]��ЩԪ�أ�����X�������ݡ�
��ʱֻ��ݹ�Ķ�X���е�ǰ���+Y���У�ȥ������kС������

��2�� ��k >= halfLen�����ʱ��k���Ԫ��һ������С��Y[yMid]���Ԫ�أ�
���Ժ�û�б�Ҫ���� Y[yBeg��yMid]��ЩԪ�أ�����Yǰ������ݡ�
��ʱֻ��ݹ�Ķ�X����+Y���еĺ��Σ�ȥ������ k-(yMid-yBeg+1��С������

�ݹ�ı߽磬�����д��

if (xBeg > xEnd) return Y[yBeg + k - 1]; //X����Ϊ��ʱ��ֱ�ӷ���Y���еĵ�kСԪ�ء�
if (yBeg > yEnd) return X[xBeg + k - 1]; //Y����Ϊ��ʱ��ֱ�ӷ���X���еĵ�kСԪ�ء�
Ч�ʷ�����

T(m,n)��ʾ�Գ���Ϊm�������X���кͳ���Ϊn�������Y���У�������kСԪ�صĸ��Ӷȡ�
T(m,n)=1 m=0��n=0
T(m,n) <= max{T(m/2,n), T(m,n/2)} + O(1)

��T(m,n) = O(max{logm, logn})

*/
