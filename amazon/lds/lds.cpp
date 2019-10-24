#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int n;
    cin>>n;
    
    vector<int> inp;
    //inp.reserve(n+1);
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        inp.push_back(tmp);
    }
    
    vector<int> lds;
   // lds.reserve(n);
    for(int i=0;i<n;i++)
    {
        auto it=lower_bound(lds.begin(),lds.end(),inp[i],greater<int>());
        if(it==lds.end())
            lds.push_back(inp[i]);
        else
            *it=inp[i];
            
    }
    cout<<lds.size()<<endl;
    return 0;
}
