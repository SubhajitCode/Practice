#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<#x<<" : "<<x<<endl
#define debvec(x) for(int i=0;i<x.size();i++) cout<<x[i]<<", ";cout<<endl;
int Util(vector<int> A,int count,int K,int ans,int pos)
{
	deb(count);deb(ans);debvec(A);
    if(count<=K)
        return ans;
    int change=INT_MAX;
    for(int i=pos;i<A.size();i++)
    {
        int change1=INT_MAX,change2=INT_MAX;
        if(i==0)
        {
            if(A[i]!=A[i+1])
            {
                A[i]=A[i+1];
                change1=Util(A,count-1,K,ans+1,i);
                
            }
        }
        else if(i==A.size()-1)
        {
            if(A[i]!=A[i-1])
            {
                A[i]=A[i-1];
                change1=Util(A,count-1,K,ans+1,i);
            }
        }
        else
        {
            //case1
            if(A[i]!=A[i+1])
            {
                A[i]=A[i+1];
                if(A[i]==A[i-1])
                {
                    change1=Util(A,count-2,K,ans+1,i);
                }
                else
                {
                    change1=Util(A,count-1,K,ans+1,i);
                }
            }
            if(A[i]!=A[i-1])
            {
                A[i]=A[i-1];
                if(A[i]==A[i+1])
                {
                    change2=Util(A,count-2,K,ans+1,i);
                }
                else
                {
                    change2=Util(A,count-1,K,ans+1,i);
                }
            }
        }
        change =min(min(change,change1),change2);
    }
    if(change==INT_MAX)
	    return ans;
    return change+ans;
}

int main()
{
    int t;
    cin>>t;
    int test_case=0;
    while(t--)
    {
        test_case++;
        int N,K;
        cin>>N>>K;
        vector<int> input(N,0);
        for(int i=0;i<N;i++)
        {
            int tmp;
            cin>>tmp;
            input[i]=tmp;
        }
        int count=0;
        for(int i=0;i<N-1;i++)
        {
            if(input[i]!=input[i+1])
            count++;
            
        }
        int res=Util(input,count,K,0,0);
	cout<<"Case #"<<test_case<<": " <<res<<endl;
        
        
        
    }
    
    return 0;
}
