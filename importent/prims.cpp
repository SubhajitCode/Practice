int prims(int start,vector<pair<int,int>> adj[],int A)
{
    vector<bool>visited(A+1,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pQ;
    pQ.push(make_pair(0,start));
    int minCost=0;
    pair<int,int> p;
    while(!pQ.empty())
    {
        p=pQ.top();
        pQ.pop();
        int vertex=p.second;
        int weight=p.first;
        if(visited[vertex])
            continue;
        visited[vertex]=true;
        
        minCost+=weight;
        for(int i = 0;i < adj[vertex].size();i++)//i<=V
        {
            int y = adj[vertex][i].second;
            if(!visited[y])
                pQ.push(adj[vertex][i]);
        }
    }
    return minCost;
    
}