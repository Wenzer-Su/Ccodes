#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
long numbers[15];



//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstdio>
//using namespace std;
//long numbers[20];
//long m=0;
//
//long solve(long n,long maxNum)
//{
//    if (n==0)
//        return 1;
//    long ans=0;
//    for (int i=0;i<m;i++)
//    {
//        if (numbers[i]>n)
//            break;
//        if (numbers[i]>maxNum)
//            break;
//        ans+=solve(n-numbers[i],numbers[i]);
//    }
//    return ans;
//}
//
//int main()
//{
//    long n;
//    cin>>n;
//    long counter=1;
//    while(counter<=n)
//    {
//        numbers[m++]=counter;
//        counter*=2;
//    }
//
////    cout<<"m=="<<m<<endl;
////    for (int i=0;i<m;i++)
////        cout<<numbers[i]<<endl;
////    cout<<endl;
//    cout<<solve(n,n)<<endl;
//    return 0;
//}
