class Solution {
public:
    int util(vector<int>& arr,vector<vector<int>>& dp,int i,int j)
    {
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        long long ans=INT_MAX;
        
        for(int k=i;k<=j-1;k++)
        {
            long long ans2=util(arr,dp,i,k)+util(arr,dp,k+1,j)+((*max_element(arr.begin()+i,arr.begin()+k+1))*(*max_element(arr.begin()+k+1,arr.begin()+j+1)));
            ans=min(ans2,ans);
        }
        dp[i][j]=ans;
        return ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return util(arr,dp,0,n-1);
        
        
    }
};