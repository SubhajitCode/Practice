#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> A={2,4,5,8,9};
    int area=33;
    int n=A.size();
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i]*A[j]<=area)
            count++;

        }
    }
    cout<<count<<endl;
    count=0;
    for(int i=0;i<n;i++)
    {
        int find=area/A[i];
        auto it=upper_bound(A.begin(),A.end(),find);
        count+=(it-A.begin());
    }
    cout<<count<<endl;
}