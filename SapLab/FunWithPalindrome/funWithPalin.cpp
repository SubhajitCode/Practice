#include<bits/stdc++.h>
using namespace std;
int multiplyPalindrome(string s) {
    int maxnum=0;
    int n=s.size();
    int dp[n][n];
    for(int i=0;i<n;i++)
        dp[i][i]=1;
    for(int cl=2;cl<n+1;cl++)
    {
        for(int i=0;i+cl-1<n;i++)
        {
            int j=i+cl-1;
            if(s[i]==s[j])
            {
                if(cl==2)
                {
                    dp[i][j]=2;
                }
                else
                {
                    dp[i][j]=dp[i+1][j-1]+2;
                }
                
            }
            else
            {
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
            
        }
    }
    for(int i=0;i<n-1;i++)
    {
        maxnum=max(maxnum,dp[0][i]*dp[i+1][n-1]);
    }
    return maxnum;
}

int main()
{
    string s="attract";
    cout<<multiplyPalindrome(s)<<endl;
    s="acdapmpomp";
    cout<<multiplyPalindrome(s)<<endl;
}