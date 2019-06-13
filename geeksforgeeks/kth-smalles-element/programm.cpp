#include <iostream>
using namespace std;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int left,int right)
{
	if(left>=right)
	{
		return arr[left];
	}
    int r=left+(rand()%(right-left));
    swap(&arr[left],&arr[r]);
    int p=arr[left];
    int i=left+1;
    for(int j=left+1;j<=right;j++)
    {
        if(p>arr[j])
        {
            swap(&arr[i],&arr[j]);
            i++;
        }
        
    }
    i--;
    swap(&arr[left],&arr[i]);
    return i;
}

int Rselect(int arr[],int left,int right,int k)
{
        int pivot=partition(arr, left, right);
        if(k==pivot)
        {
            return arr[pivot];
        }
        else if(pivot>k)
        {
            Rselect(arr,left,pivot-1,k);
        }
        else
        {
            Rselect(arr,pivot+1,right,k);
        }
   
    
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin >>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    cin>>k;
	    int res=Rselect(arr,0,n-1,k-1);
	    cout<<res<<endl;
	    
	}
	return 0;
}
