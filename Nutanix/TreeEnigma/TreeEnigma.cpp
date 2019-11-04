#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int name;
    int correct;
    int incorrect;
    vector<Node*> childrens;
    Node(int x):name(x)
    {}
};
Node* watson(vector<int> graph[],vector<int> &arr,vector<int>& brr,int root,bool visited[]) //builds the graph
{
    visited[root]=true;
    Node *rootNode=new Node(root);
    int correct=(arr[root-1]==brr[root-1]);
    int incorrect=(arr[root-1]!=brr[root-1]);
    for(int i=0;i<graph[root].size();i++)
    {
        if(!visited[graph[root][i]])
        {
            visited[graph[root][i]]=true;
            Node *child= watson(graph,arr,brr,graph[root][i],visited);
            rootNode->childrens.push_back(child);
            correct+=child->correct;
            incorrect+=child->incorrect;
        }
    }
    rootNode->correct=correct;
    rootNode->incorrect=incorrect;
    return rootNode;
}
int Lestrade(Node* root,int op1,int op2,vector<int> &arr,vector<int> &brr) //calculates no of ops required greedy
{

    int res=0;
    if(op2%2==1)
    {
        arr[root->name-1]=!arr[root->name-1];
        int tmp=root->incorrect;
        root->incorrect=root->correct;
        root->correct=tmp;
    }

    if(root->correct+2<=root->incorrect && arr[root->name-1]!=brr[root->name - 1])
    {

        op2++;
        res++;
        arr[root->name-1]=brr[root->name - 1];
        int tmp=root->incorrect;
        root->incorrect=root->correct;
        root->correct=tmp;
    }
    else if(arr[root->name-1]!=brr[root->name - 1])
    {
        op1++;
        res++;
        arr[root->name-1]=brr[root->name - 1];
        root->correct++;
        root->incorrect--;
    }

    for(Node* child:root->childrens)
    {
        res+=Lestrade(child,op1,op2,arr,brr);
    }
    cout<<root->name<<" "<<res<<endl;
    return res;

}
void printWatson(Node* root)
{
    cout<<root->name<<" "<<root->correct<<" "<<root->incorrect<<endl;
    for(Node* child:root->childrens)
    {
        printWatson(child);
    }
}
int sherlock(vector<int> graph[],vector<int> &arr,vector<int>& brr)
{
    int root=1;
    bool visited[arr.size()+1];
    memset(visited,false,sizeof(visited));
    Node* rootNode=watson(graph,arr,brr,root,visited);
    printWatson(rootNode);
    cout<<"break"<<endl;
    int ans=Lestrade(rootNode,0,0,arr,brr);
    cout<<"break"<<endl;
    printWatson(rootNode);
    cout<<"break"<<endl;
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" "<<brr[i]<<endl;
    return ans;

}
int main()
{
    
    int N;
    cin>>N;
    vector<int> graph[N+1];
    for(int i=0;i<N-1;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    //cout<<"test"<<endl;
    vector<int>arr;
    vector<int>brr;
    for(int i=0;i<N;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    for(int i=0;i<N;i++)
    {
        int b;
        cin>>b;
        brr.push_back(b);
    }
    //cout<<"test2"<<endl;
    cout<< sherlock(graph,arr,brr)<<endl;

}