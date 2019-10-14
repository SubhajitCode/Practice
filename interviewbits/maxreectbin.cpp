#define deb(x) cout<<#x<<"  "<<x<<endl
#define debvec(x) cout<<#x<<endl; for(int j=0;j<x.size();j++) cout<<x[j]<< " ";cout<<endl
int largestRectInHist(vector<int> &hist)
{
    stack<int> stack;
    int res=0;
    int i;
    for( i=0;i<hist.size();i++)
    {
        if(stack.empty())
        {
            stack.push(i);
        }
        else if(hist[stack.top()]<=hist[i])
        {
            stack.push(i);
        }
        else
        {
            int tp=stack.top();
            stack.pop();
            int endIndex;
            int area;
            if(stack.empty())
            {
                endIndex=i;
                res=hist[tp]*(endIndex);
                
            }
            else
            {
                endIndex=i;
                area=(endIndex - stack.top() -1)*hist[tp];
            }
            res=max(res,area);
            deb(i);deb(area);deb(hist[tp]);deb()
            
        }
    }
    while(!stack.empty())
    {
        int tp=stack.top();
            stack.pop();
            int endIndex;
            int area;
            if(stack.empty())
            {
                endIndex=i;
                res=hist[tp]*(endIndex);
                
            }
            else
            {
                endIndex=i;
                area=(endIndex-stack.top() -1)*hist[tp];
            }
            res=max(res,area);
    }
    return res;
    
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int m=A.size();
    int n=A[0].size();
    
    vector<vector<int>> dp(A);
    int maxval=0;
   for(int i=0;i<m;i++ )
   {
       for(int j=0;j<n;j++)
       {
           if(dp[i][j]==1&&i!=0)
           {
               dp[i][j]=dp[i-1][j]+dp[i][j];
           }
       }
   }
    for(int i=0;i<dp.size();i++ )
   {
       debvec(dp[i]);
       int tmp=largestRectInHist(dp[i]);
       maxval =max(maxval,tmp);
       deb(tmp);
   }
   return maxval;
    
}

