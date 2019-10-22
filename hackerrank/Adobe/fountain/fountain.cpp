/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int fountain(vector<int> &arr)
{
    int n=arr.size();
    vector<int> extent(n,0);
    for(int i=0;i<n;i++)
    {
        int left=max(0,i-arr[i]);
        int right=min(n,i+arr[i]);
        extent[left]=max(right,extent[left]);
    }
    int right=extent[0];
    int next_right=right;
    int count=1;
    for(int i=0;i<n;i++)
    {
        next_right=max(next_right,extent[i]);
        if(i==right+1)
        {
            count++;
            right=next_right;
        }
    }
    return count;
}
