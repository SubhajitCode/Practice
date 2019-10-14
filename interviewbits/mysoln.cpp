
#define deb(x) cout<<#x<<" : "<<x<<endl
string eveal(string str)
{
    bool op1;
    bool op2;
    bool op3;
    deb(str);
    if(str[0]=='T')
    {
        op1=true;
    }
    else if(str[0]=='F')
    {
        op1=false;
    }
    else
    {
        cout<<"locha"<<endl;
    }
    if(str[2]=='T')
    {
        op2=true;
    }
    else if(str[2]=='F')
    {
        op2=false;
    }
    else
    {
        cout<<"locha2"<<endl;
    }
    if(str[1]=='^')
    {
        op3=op1^op2;
    }
    else if(str[1]=='|')
    {
        op3=op1|op2;
    }
    else if(str[1]=='&')
    {
        op3=op1&op2;
    }
    else
    {
        cout<<"locha3"<<endl;
    }
    
    if(op3)
    {
        return "T";
    }
    else
    {
        return "F";
    }
}
void Util(string A,int &ans)
{
    deb(A);
    int n=A.size();
    if(n==1)
    {
        if(A[0]=='T')
            ans++;
        return;
    }
    for(int i=0;i<=n-3;i=i+2)
    {
        string str1=A.substr(0,i);
        string str=A.substr(i,3);
        string str2=A.substr(i+3,n-i-3);
        string newstr=str1+eveal(str)+str2;
        Util(newstr,ans);
    }
}
int Solution::cnttrue(string A) {
    int ans=0;
    Util(A,ans);
    return ans;
    
}

