int Solution::isMatch(const string A, const string B) {
    int m=A.size();//i
    int n=B.size();//j
    bool dp[m+1][n+1];
    //bool flag[n+1];
    memset(dp,0,sizeof(dp));
    //memset(flag,0,sizeof(flag));
    dp[0][0]=1;
    for(int j=1;j<=n;j++)
    {
        if(B[j-1]=='*')
            dp[0][j]=dp[0][j-1];
        
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(A[i-1]==B[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else if(B[j-1]=='?')
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else if(B[j-1]=='*')
            {
                dp[i][j]=dp[i][j-1]|dp[i-1][j-1]|dp[i-1][j];
            }
            else
            {
                dp[i][j]=0;
                //return 1;
            }
        }
    }
   /*
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    return dp[m][n];
    
    
}

