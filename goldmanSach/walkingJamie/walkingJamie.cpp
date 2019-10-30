#include<bits/stdc++.h>
using namespace std;
void util(string &instruction,int pos,int dest,int len,int index,unordered_set<string> &set,string curr)
{
    if(instruction[index]=='r')
    {
        pos++;
    }
    else if(instruction[index]=='l')
    {
        pos--;
    }
    curr+=instruction[index];
    if(pos==dest)
    {
        if(set.find(curr)==set.end())
        {
            set.insert(curr);
            cout<<curr<<endl;

        }
         
    }
        
    if(pos>len)
        return;
    else if(pos<0)
       return;
    
    for(int i=index+1;i<instruction.length();i++)
    {
        util(instruction,pos,dest,len,i,set,curr);
    }



}
int walking(string instruction,int x,int y,int len)
{
    unordered_set<string> set;
    for(int i=0;i<instruction.length();i++)
        util(instruction,x,y,len,i,set,"");
    return set.size();
}
int main()
{
cout<<walking("rrlrlr",1,2,6)<<endl;
return 0;
}