#include<bits/stdc++.h>
#define deb(x) cout<<#x<<" : "<<x<<endl;
using namespace std;
int isPower(string A)
{
    int res;
    if((A[A.size()-1]-'0')%2!=0)
    {
        res=0;
        return res;
        
    }
    else if((A.size()==1)&&(A[0]=='1'))
    { 
        res=0;
        return res;
        
    }
    else if((A.size()==1)&&(A[0]=='2'))
    {
        res=1;
        deb(res);
        return res;
    }
    else
    {    
        string temp="";
        int num=0;
        for(int i=0;i<A.size();i++)
        {
            num=num*10+A[i]-'0';
            if(num<2)
            {
                if(i!=0)
                {
                    temp=temp+'0';
                }
                 continue;
            }
            char re=(num/2)+48;
            temp=temp+re;
            num=num%2;
        }
       return isPower(temp);
    }
}

int main()
{
	cout<<isPower("128")<<endl;
	return 0;
}
