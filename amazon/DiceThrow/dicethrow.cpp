#include <bits/stdc++.h>
using namespace std;

long util(int m,int n,int sum,vector<vector<long>> &dp)
{

    if(sum<0)
    {
        return 0;
    }
    if(sum==0)
        return (n==0);
    if(n<0)
        return 0;
    if(n==0)
    {
        if(sum==0)
            return 1;
        else
            return 0;
    }
    if(dp[sum][n]!=-1)
        return dp[sum][n];
    long ans=0;
    for(int i=1;i<=m;i++)
    {
        if(n-1>=0&&sum-i>=0)
            ans=ans+util(m,n-1,sum-i,dp);
    }
    dp[sum][n]=ans;
    return ans;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int m,n,sum;
	    cin>>m>>n>>sum;
	    vector<vector<long>> dp(sum+1,vector<long>(n+1,-1));
	    cout<<util(m,n,sum,dp)<<endl;
	}
	return 0;
}