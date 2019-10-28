/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int util(vector<int> &arr,int K,int N,int M,int stress,int index)
{
    if(index>=arr.size())
        return stress;
    K=max(0,K);
    if(K>=N)
    {
        if(K-arr[index]>=N)
        {
            return util(arr,K-arr[index],N,M,stress,index+1);
        }
        else
        {
            return util(arr,K-arr[index],N,M,stress+1,index+1);
        }
    }
    
    int ans1=util(arr,K-arr[index],N,M,stress,index+1);
    if(K+arr[index]>=N)
        stress++;
    int ans2=util(arr,K+arr[index],N,M,stress,index+1);
    return max(ans1,ans2);
        
}
int coconut(vector<int> &arr,int K,int N,int M)
{
    int stress=0;
    return util(arr,K,N,M,stress,0);
}
int main()
{
    vector<int> arr={100,200,100,1,1};
    int K=1900,N=2100,M=5;
    cout<<coconut(arr,K,N,M)<<endl;

    return 0;
}
