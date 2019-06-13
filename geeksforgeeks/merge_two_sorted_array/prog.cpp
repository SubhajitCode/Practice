#include <bits/stdc++.h>
using namespace std;
int maximum=INT_MIN;
void put_two_values(int arr[],int pos,int value)
{
    arr[pos]=arr[pos]+maximum*value;
}
int get_old(int arr[],int pos)
{
    return(arr[pos]%maximum);
}
void set_all_new(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]>maximum)
            arr[i]=arr[i]/maximum;
    }
}

void merge(int arr[],int x,int y)
{
    int i=0,j=0,k=0;;
    while(i<x&&j<y)
    {
        int xi=get_old(arr,i);
        int yj=get_old(arr,j);
        if(yj>xi)
        {
            put_two_values(arr,k,xi);
            i++;
            k++;
        }
        if(yj<xi)
        {
            put_two_values(arr,k,yj);
            j++;
            k++;
        }
    }
    set_all_new(arr,x+y);
}
int main() {
	//code
	int t;
	cin >>t;
	while(t--)
	{
	    int x,y;
	    cin >>x>>y;
	    int n=x+y;
	    int arr[n];
	    int local_max=INT_MIN;
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	        if(arr[i]>local_max)
	        {
	            local_max=arr[i];
	        }
	    }
	    maximum=local_max;
	    merge(arr,x,y);
	    for(int i=0;i<n;i++)
	    {
	        cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
