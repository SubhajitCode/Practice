#include<bits/stdc++.h>
using namespace std;
int util(vector<string> dict,string target,int i,int j)//i=index of dict  j=index of target
{
    int m=dict[0].size();
    int n=target.size();
    if(i>=m||j>=n)
        return 0;
    if(j==n-1)
    {
        int ans=0;
        for(string str:dict)
        {
            if(str[i]==target[j])
            {
                ans=ans+1+util(dict,target,i+1,j);
                cout<<str<<" "<<i<<" "<<endl;
            }/*
            else
            {
                ans=ans+util(dict,target,i+1,j);
            }*/
            
        }
        return  ans;

    }
    int ans=0;
    for(string str:dict)
    {
        if(str[i]==target[j])
        {
            ans=ans+util(dict,target,i+1,j+1);
        }
        else
        {
            ans=ans+util(dict,target,i+1,j);
        }
        

    }
    return ans;
    
}
int stringFormation(vector<string> dict,string target)
{
    /*unordered_set<char> set;
    for(auto ch:target)
        set.insert(ch);
    vector<string> dict2;
    for(string str:dict)
    {
        string newstr="";
        for(int i=0;i<str.size();i++)
        {
            if(set.find(str[i])!=set.end())
            {
                newstr+=str[i];
            }
            re
        }
    }
    */

    return util(dict,target,0,0);
}
int main()
{
    vector<string> dict={"adc","aec","efg"};
    string target="ac";
    cout<<stringFormation(dict,target)<<endl;
}