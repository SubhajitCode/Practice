/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
long groups(int n,std::vector<int> a,vector<int> b )
{
    vector<int> v(n,INT_MAX);
    for(int i=0;i<a.size();i++)
    {
        int x=a[i];
        int y=b[i];
        if(y<x)
            swap(x,y);
       v[x]=min(v[x],y);
    }
    int count=0;
    for(int i=1;i<n;i++)
    {
        int range=n;
        range=min(range,v[i]);
        for(int j=i;j<range;j++)
        {
            count++;
            cout<<"("<<i<<","<<j<<")"<<endl;
            int range2=v[j];
            range=min(range,range2);
            //count++;
        }
    }
    
    return count;
    
    
}
int main()
{
    vector<int > a={1,2},b={3,5};
    cout<<groups(6,a,b);

    return 0;
}

