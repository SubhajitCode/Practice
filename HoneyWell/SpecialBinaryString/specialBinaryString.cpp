
#include<bits/stdc++.h>
using namespace std;
string makeSpecial(string str)
{
    string res="";
    vector<string> resVec;
    int count=0;
    int j=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='1')
        {
            count++;
        }
        else
        {
            count--;
        }
        if(count==0)
        {
            int length=i-j-1;
            resVec.push_back('1'+makeSpecial(str.substr(j+1,length))+'0');
            j=i+1;
        }
        
    }
    sort(resVec.begin(),resVec.end(),greater<string>());
    for(auto s:resVec)
        res+=s;
    return res;

}

int main()
{
    cout<<makeSpecial("11011000")<<endl;
    return 0;
}