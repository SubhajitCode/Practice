#include<bits/stdc++.h>
using namespace std;
class unionFind
{
    vector<int > parrent;
    int size=0;
    public:
   /* unionFind(const unionFind &oldOne)
    {
        
    }*/
    unionFind(int n)
    {
        parrent=vector<int>(n);
        size=n;
        for(int i=0;i<n;i++)
        {
            parrent[i]=-1;
        }
    }
    int find(int x)
    {
       int tmp=x;
        while(parrent[x]>0)
        {
            x=parrent[x];
        }
        if(x!=tmp)
            parrent[tmp]=x;
        return x;   
        
    }
    void Union(int x,int y)
    {
        int xset=find(x);
        int yset=find(y);
        if(xset==yset)
            return;
        if(xset>yset)
            swap(yset,xset);
        int tmp=parrent[yset];
        parrent[yset]=xset;
        parrent[xset]+=tmp;
            return;
        
    }
    void print()
    {
       for(int i=0;i<size;i++)
        cout<<parrent[i]<<" ";
        cout<<endl; 
    }
    
};
int sharedInterest(vector<int> friends_from,vector<int> friends_to,vector<int> friend_edges,int size)
{
    int n=friends_from.size();
    vector<unionFind> U(200,unionFind(size+1));
    for(int i=0;i<n;i++)
    {
        int x=friends_from[i];
        int y=friends_to[i];
        int token=friend_edges[i]; 
        U[token].Union(x,y);
    }
    int max_count=0;
    int max_res=0;
   for(int i=1;i<=size;i++)
   {
       for(int j=i+1;j<=size;j++)
       {
           int count=0;
           for(int t=0;t<200;t++)
           {
               if(U[t].find(i)==U[t].find(j))
               {
                   count++;
               }
           }
           if(count>max_count)
           {
               max_count=count;
               max_res=i*j;
           }
           else if(count==max_count&&count!=0)
           {
               max_res=max(i*j,max_res);
           }
       }
   }
    return max_res;
}

int main()
{
    vector<int> friends_from={1,1,2,2,2};
    vector<int> friends_to={2,2,3,3,4};
    vector<int> friend_edges={1,2,1,3,3};
    cout<<sharedInterest(friends_from,friends_to,friend_edges,4)<<endl;

}