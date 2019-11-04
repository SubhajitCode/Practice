#include<bits/stdc++.h> 
using namespace std;
int equilibrium(vector<int> arr)
{
    if(arr.size()==1)
        return 1;
    int sum=0;
    for(int elem :arr)
    {
        sum+=elem;
    }
    int leftSum=0;
    int rightSum=sum;
    for(int i=0;i<arr.size()-1;i++)
    {
        if(leftSum==rightSum)
        {
            return i+1;
        }
        leftSum=leftSum+arr[i];
        rightSum=sum-leftSum-arr[i+1];
    }
    return -1;
}

int main()
{	//code
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> arr;
	    arr.reserve(n);
	    for(int i=0;i<n;i++)
	    {
	        int tmp;
	        cin>>tmp;
	        arr.push_back(tmp);
	    }
	    cout<<equilibrium(arr)<<endl;
	}
	return 0;
}