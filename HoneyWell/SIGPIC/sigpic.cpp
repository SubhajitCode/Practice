#include<bits/stdc++.h>
using namespace std;
const int M=200;
int rec(int minNum,int n,int k,vector<vector<vector<int>>>& dp)  //n=no of people k=computer 
{
    if(k==1)
    {
        if((n>=minNum))
            return 1;
        else
        {
            return 0;
        }
        

    }
        
    if(n<minNum)
        return 0;
    if(k<0)
        return 0;
    if(dp[minNum][n][k]!=-1)
        return dp[minNum][n][k];
    int ans=0;
    for(int i=minNum;(2*i)<=n;i++)
    {
        ans=ans+rec(i,n-i,k-1,dp);
    }
    dp[minNum][n][k]=ans;
    return ans;

}


int main()
{

    vector<vector<vector<int>>> dp(200,vector<vector<int>>(200,vector<int>(200,-1)));
    cout<<rec(1,8,4,dp)<<endl;
    return 0;
}