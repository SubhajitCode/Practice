#include <iostream>
using namespace std;
int countSubarray(int arr[],int n,int k)
{
    int sum=0,count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>k)
        {
            sum=sum+((count*(count+1))/2);
            count=0;
            continue;
        }
        count++;
        
    }
    sum=sum+((count*(count+1))/2);
    return(((n*(n+1))/2)-sum);
    
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<countSubarray(arr,n,k)<<endl;
        
    }
	//code
	return 0;
}
