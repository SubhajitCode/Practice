/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

string dfs( unordered_map<int,set<int>> &adj,int root)
{
    //cout<<(char)(root+'A')<<endl;
    string ans="(";
    ans=ans+(char)(root+'A');
    auto rootSet=adj[root];
    for(auto child:rootSet)
    {
        ans+=dfs(adj,child);
    }
    ans+=")";
    return ans;
    
}
void make_graph(string  pairs)
{
    bool E1=false,E2=false,E3=false,E4=false,E5=false;
    vector<int> parrent(26,-1);
    unordered_map<int,set<int>> adj;
    for(int i=0;i<pairs.size()-1;i++)
    {
        if(isalpha(pairs[i])&&pairs[i+1]==')')
        {
            int child=pairs[i]-'A';
            int parr=pairs[i-1]-'A';
            if(parrent[child]==parr)
                E2=true;
            else if(parrent[child]!=-1&&parrent[child]!=-2)
            {
               // cout<<(char)(parr+'A')<<(char)(child+'A')<<endl;
                E3=true;
            }
            parrent[child]=parr;
            if(parrent[parr]==-1)
                parrent[parr]=-2;
            adj[parr].insert(child);
            if(adj[parr].size()>2)
            {
                //cout<<(char)(parr+'A')<<(char)(child+'A')<<endl;
                E1=true;
            }
        }
    }
    int count=0;
    int root;
    for(int i=0;i<26;i++)
    {
        if(parrent[i]==-2)
        {
            count++;
            root=i;
        }
    }
    if(count>1)
    {
        E4=true;
    }
    if(E1)
    {
        cout<<"E1"<<endl;
    }
     else  if(E2)
    {
        cout<<"E2"<<endl;
    }
    else if(E3)
    {
        cout<<"E3"<<endl;
    }
    else if(E4)
    {
        cout<<"E4"<<endl;
    }
    else if(E5)
    {
        cout<<"E5"<<endl;
    }
    else
    {
        
        string ans=dfs(adj,root);
        cout<<ans<<endl;
    }
    
    
    
}

int main()
{
    string s = "(AY)(AX)(DK)(ZA)(DL)(KH)(ZD)(KI)";
    make_graph(s);
    
    return 0;
}
