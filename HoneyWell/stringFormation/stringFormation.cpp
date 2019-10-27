#include<bits/stdc++.h>
using namespace std;
int util(vector<string> dict,string target,int index,int tindex,int match) //match standsfor no of charecter  matched with taget string
{
    
    int m=dict[0].size();
    int n=target.size();
    if(match==n)
    {
        return 1;
    }
    if(index>=m||tindex>=n)
        return 0;
    int ans=0;
    for(int i=index;i<m;i++)
    {
        for(string str:dict)
        {
            if(str[i]==target[tindex])
            {
                ans+=util(dict,target,i+1,tindex+1,match+1);
            }
        }
    }
    return ans;

    
}
int stringFormation(vector<string> dict,string target)
{
    return util(dict,target,0,0,0);
}
int main()
{
    vector<string> dict={"valya","lyglb","vldoh"};
    string target="val";
    cout<<stringFormation(dict,target)<<endl;
}