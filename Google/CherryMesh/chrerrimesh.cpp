#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int cases=0;
    while(t--)
    {
        int n=0;
        cases++;
        int N,M;
        cin>>N>>M;
        bool visited[N+1];
	vector<int> adj[N+1];
        memset(visited,false,sizeof(visited));
        int comp=0;
        for(int i=0;i<M;i++)
        {
            int c,d;
            cin>>c>>d;
	    adj[c].push_back(d);
	    adj[d].push_back(c);
	}
	    for(int j=1;j<N+1;j++)
	    {
	    	if(visited[j])
			continue;
		comp++;
		queue<int> Q;
		Q.push(j);
		while(!Q.empty())
		{
			int u=Q.front();
			Q.pop();
			if(visited[u])
				continue;
			visited[u]=true;
			for(int k=0;k<adj[u].size();k++)
			{
				int v=adj[u][k];
				Q.push(v);
			}

		}
	    
	    }
	int red=2*(comp-1);
	int black=N-1-(comp-1);
	int ans=red+black;
        //int n=prims(adj,N+1);
        cout<<"Case #"<<cases<<": "<<ans<<endl;
    }
    
    
    
    return 0;
}


