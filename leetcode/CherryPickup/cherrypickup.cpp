//#define deb(x) cout<<#x<<" : "<<x<<endl

class Solution {
public:
    
    int cost(vector<vector<int>>& grid,vector<vector<vector<int>>>& dp,int row1,int col1,int row2,int col2)
    {
        if(row1==row2&&col1==col2)
        {
            if(grid[row1][col1]==1)
            {
               // grid[row1][col1]=0;
                return 1;
            }
            else
                return 0;
            
        }
        int ans=0;
        if(grid[row1][col1]==1)
        {
            //grid[row1][col1]=0;
            ans++;
        }
        if(grid[row2][col2]==1)
        {
            //grid[row2][col2]=0;
            ans++;
        }
        return ans;
            
    }
    bool check(vector<vector<int>>& grid,vector<vector<vector<int>>>& dp,int row1,int col1,int row2,int col2)
    {
        //deb(7);
        int n=grid.size();
        if(row1>=n||row2>=n||col1>=n||col2>=n)
            return false;
        if(grid[row1][col1]==-1)
        {
            return false;
        }
        if(grid[row2][col2]==-1)
        {
            return false;
        }
        return true;
        
        
    }
    
    int util(vector<vector<int>>& grid,vector<vector<vector<int>>>& dp,int row1,int col1,int row2,int col2)
    {
        
        //int col2=row1+col1-row2;
        int n=grid.size();
        if(row1==row2&&col1==col2&&row1==n-1&&col1==n-1)
            return 0;
        if(!check(grid,dp,row1,col1,row2,col2))
            return 0;
        if(dp[row1][col1][row2]!=-1)
            return dp[row1][col1][row2];
 
        
        int ch1=INT_MIN,ch2=INT_MIN,ch3=INT_MIN,ch4=INT_MIN;
        //deb(1);
        if(check(grid,dp,row1+1,col1,row2+1,col2))
        {
            
            
            ch1=cost(grid, dp, row1+1, col1, row2+1, col2)+util(grid,dp,row1+1,col1,row2+1,col2);
        }
        //deb(2);
        if(check(grid,dp,row1+1,col1,row2,col2+1))
        {
            
            ch2=cost(grid, dp, row1+1, col1, row2, col2+1)+util(grid,dp,row1+1,col1,row2,col2+1);
        }
        //deb(3);
        //cout<<row1<<col1<<row2<<col2<<endl;
        if(check(grid,dp,row1,col1+1,row2,col2+1))
        {
            //deb(6);
            ch3=cost(grid, dp, row1, col1+1, row2, col2+1)+util(grid,dp,row1,col1+1,row2,col2+1);
        }
        //deb(4);
        
        if(check(grid,dp,row1,col1+1,row2+1,col2))
        {
            
            ch4=cost(grid, dp, row1, col1+1, row2+1, col2)+util(grid,dp,row1,col1+1,row2+1,col2);
        }
        //deb(5);
        
        dp[row1][col1][row2]= max(ch1,max(ch2,max(ch3,ch4)));
            return(dp[row1][col1][row2]);
        
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n=grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        int ans=0;
        if(grid[0][0]==1)
        {
             ans++;
            grid[0][0]=0;
        }
        if(grid[n-1][n-1]==1)
        {
            ans++;
            grid[n-1][n-1]=0;
        }
        ans=ans+util(grid,dp,0,0,0,0);
        return max(ans,0);
           
        
    }
};