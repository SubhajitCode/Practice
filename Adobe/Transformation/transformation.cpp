/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;
bool checkAnagram(string s1,string s2)
{
    unordered_map<char,int>map;
    for(char ch:s1)
    {
        map[ch]++;
    }
    for(char ch:s2)
    {
        map[ch]--;
    }
    int ans=0;
    for(auto it:map)
    {
        
        ans+=abs(it.second);
    }
    return (ans==0);
}

int transformCost(string s,vector<string> words)
{
    int i=0;
    int cost=0;
    for(string s1:words)
    {
        string s2=s.substr(i,s1.length());
        if(checkAnagram(s2,s1))
        {
            for(int k=0;k<s1.length();k++)
                if(s2[k]!=s1[k])
                    cost++;
        }
        else
        {
            return -1;
        }
         i+=s1.length();
        //cout<<s1<<endl;
    }
    
    return cost;
    
    
}
int main()
{
    vector<string> words={"waht","the","hell"};
    string s="whatthehell";
   cout<<transformCost(s,words)<<endl;
    return 0;
}

