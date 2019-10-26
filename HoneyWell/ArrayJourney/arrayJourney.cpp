/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int max_points(vector<int> &arr,int k)
{
    int n=arr.size();
    vector<int> maxArr;
    deque<int> dQ;
    int i;
    for( i=0;i<k;i++)
    {
        while(!dQ.empty()&&arr[dQ.back()]<=arr[i])
            dQ.pop_back();
        dQ.push_back(i);
    }
    maxArr.push_back(arr[dQ.front()]);
    for(;i<n;i++)
    {
        while(!dQ.empty()&&dQ.front()<=i-k)
            dQ.pop_front();
        while(!dQ.empty()&&arr[dQ.back()]<=arr[i])
            dQ.pop_back();
        dQ.push_back(i);
        maxArr.push_back(arr[dQ.front()]);
    }
    int m=maxArr.size();
    while(dQ.size()>(n-m))
    {
        dQ.pop_front();
    }
    while(!dQ.empty())
    {
        maxArr.push_back(arr[dQ.front()]);
        dQ.pop_front();
    }
    /*for(int i=0;i<maxArr.size();i++)
        cout<<maxArr[i]<<" ";
    cout<<endl;*/
    for(int i=0;i<n;i++)
    {
        
    }
    return 0;
    
}

int main()
{
    vector<int> arr={10,2,-10,5,20,26};
    cout<<max_points(arr,2)<<endl;
    return 0;
}
