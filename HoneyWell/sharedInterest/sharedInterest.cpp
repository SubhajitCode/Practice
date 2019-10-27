#include<bits/stdc++.h>
using namespace std;

int sharedInterest(vector<int> friends_from,vector<int> friends_to,vector<int> friend_edges)
{
    int n=friends_from.size();
    map<pair<int,int>,int> map;
    for(int i=0;i<n;i++)
    {
        int x=friends_from[i];
        int y=friends_to[i];
        if(y>x)
            swap(x,y); //maintain the order
        map[make_pair(x,y)]++;
        
    }
    int max_count=INT_MIN;
    int max_res=0;
    for(auto p:map)
    {
        pair<int,int> vertices=p.first;
        int count=p.second;
        if(max_count<count)
        {
            max_count=count;
            max_res=(vertices.first)*(vertices.second);

        }
        else if(max_count==count)
        {
            max_res=max(max_res,(vertices.first)*(vertices.second));
        }

    }
    return max_res;
}

int main()
{
    vector<int> friends_from={1,1,2,2,2};
    vector<int> friends_to={2,2,3,3,4};
    vector<int> friend_edges={2,3,1,3,4};
    cout<<sharedInterest(friends_from,friends_to,friend_edges)<<endl;

}