#include<bits/stdc++.h>
using namespace std;
int res=0;
int dfs(vector<int> adj[],int u,int pu)
{
    bool flag0=false,flag1=false,flag2=false;
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(v==pu)
            continue;
        int val=dfs(adj,v,u);
        //0 leaf
        //1 parent of leaf or covered
        //2 parent and uncovered 
        if(val==0)
        {
            flag0|=true;
            //child is leaf should res++  return 1
        }
        else if(val==1)
        {
            flag1|=true;
            //child is covered and a parent so  return 2;
        }
        else if(val==2)
        {
           flag2|=true;
           //child is uncovered do nothing
        }
        
    }
    if(flag0)
    {
        res++;
        return 1;
    }
    if(flag1)
    {
        return 2;
    }
    return 0;
}

int main()
{
    int n,m;
	cin>>n>>m;
    vector<int> adj[n+1];
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
    int ans=dfs(adj,1,0);
    if(ans==0)
        res++;
    cout<<res<<endl;

}