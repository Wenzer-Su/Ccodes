#include <iostream>
 
using namespace std;
 
int Q(int n, int m);
int EVEN(int n, int m);
int ODD(int n, int m);
 
// 最大加数不超过m的划分数；不超过m个正整数之和的划分数
int Q(int n, int m){
    if((n < 1) || (m < 1)){
        return 0;
    }
    
    if((n == 1) || (m == 1)){
        return 1;
    }
    
    if(n < m){
        return Q(n, n);
    }
    
    if(n == m){
        return Q(n, m-1) + 1;
    }
    
    return Q(n, m-1) + Q(n-m, m);
}
 
// 正偶整数之和的划分数
int EVEN(int n, int m){
    if(m > n || m <= 0){
        return 0;
    }
    
    if(((n == 1) && (m == 1)) || ((n == 2) && (m == 2))){
        return 0;
    }
    
    if((n == 2) && (m == 1)){
        return 1;
    }
    
    return ODD(n-m, m);
}
 
// 正奇整数之和的划分数
int ODD(int n, int m){
    if(m > n || m <= 0){
        return 0;
    }
    
    if((n == 2) && (m == 1)){
        return 0;
    }
    
    if(((n == 1) && (m == 1)) || ((n == 2) && (m == 2))){
        return 1;
    }
    
    return ODD(n-1, m-1) + EVEN(n-m, m);
}
 
int main()
{
    int n,m;
    cin >> n;
    cin >> m;
    
    int res1 = Q(n,m);//（1）（2）问答案相同
    int res2 = 0;//（3）（4）问答案相同
    for(int i=1;i<=n;i++){
        res2 += ODD(n,i);
    }
    
    cout << res1 << " " << res1 << " " << res2 << " " << res2;
    
    cout << endl;
    return 0;
}

/*
https://blog.csdn.net/u013571487/article/details/41311247?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522163369703016780357255154%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=163369703016780357255154&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~baidu_landing_v2~default-2-41311247.first_rank_v2_pc_rank_v29&utm_term=10302+%E6%95%B4%E6%95%B0%E7%9A%84%E7%89%B9%E6%AE%8A%E5%88%92%E5%88%86&spm=1018.2226.3001.4187
*/