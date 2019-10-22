class Solution {
public:
    int kadane(vector<int> &arr,int &start,int &end,int K)
    {
       /* for(int i=0;i<arr.size();i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        */
        int global_max=INT_MIN;
        int curr_sum=0;
        
        for(int i=0;i<arr.size();i++)
        {
            
            curr_sum=curr_sum+arr[i];
            if(curr_sum<0)
            {
                start=i+1;
                curr_sum=0;
            }
            else if(global_max<curr_sum&&curr_sum<=K)
            {
                end=i;
                global_max=curr_sum;
            }
                
        }
        if(end!=-1)
            return global_max;
        start=0,end=0,global_max=arr[0];
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>global_max&&arr[i]<=K)
            {
                start=i;
                end=i;
                global_max=arr[i];
            }
        }
        return global_max;
            
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int K) {
        int row=matrix.size();
        int col=matrix[0].size();
        int maxSum = INT_MIN, finalLeft, finalRight,  
                          finalTop, finalBottom,start=0,end=-1;
       
        for(int i=0;i<col;i++)
        {
             vector<int> tmp(row,0);
            
            for(int j=i;j<col;j++)
            {
                
               
                for(int k=0;k<row;k++)
                    tmp[k]=tmp[k]+matrix[k][j];
                start=0;end=-1;
                int sum=kadane(tmp,start,end,K);
                //cout<<sum<<endl;
                if(sum>=maxSum&&sum<=K)
                {
                    finalLeft=i;
                    finalRight=j;
                    finalTop=start;
                    finalBottom=end;
                    maxSum=sum;
                    
                }
                
            }
        }
        
        return maxSum;
        
    }
};