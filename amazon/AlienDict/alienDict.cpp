class Graph
{
    int V;
    vector<int> *adj;
    void topologicalSortUtil(int v,bool visited[],stack<int> &stack)
    {
        visited[v]=true;
        for(auto it:adj[v])
        {
            if(!visited[it])
            {
                topologicalSortUtil(it,visited,stack);
            }
            
        }
        stack.push(v);
    }
    public:
    Graph(int v):V(v)
    {
        adj=new vector<int>[v];
    }
    
    void addEdge(int v,int w)
    {
        adj[v].push_back(w);
    }
    string topologicalSort()
    {
        stack<int> stack;
        bool *visited=new bool[V];
        for(int i=0;i<V;i++)
            visited[i]=false;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
                topologicalSortUtil(i,visited,stack);
        }
        
        string res="";
        while(!stack.empty())
        {
            char ch='a'+stack.top();
            res=res+ch;
            stack.pop();
        }
        return res;
    }
};

string printOrder(string dict[], int N, int k)
{
   //Your code here
   Graph g(k);
   for(int i=0;i<N-1;i++)
   {
        string word1=dict[i];
        string word2=dict[i+1];
       for(int j=0;j<min(word1.size(),word2.size());j++)
       {

           if(word1[j]!=word2[j])
           {
               g.addEdge(word1[j]-'a',word2[j]-'a');
               break;
           }
       }
   }
   return g.topologicalSort();
   
   
}