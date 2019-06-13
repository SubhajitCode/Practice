#include <iostream>
using namespace std;
void printArray(int array[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" "<<flush;
	}
	cout<<endl;

}

void reArrange(int a[],int n)
{
	for(int i=0;i<=n-2;i=i+2)
	{
		int temp=a[n-1],j;
		for(j=n-2;j>=i;j--)
		{
			a[j+1]=a[j];
			
		//	cout <<j<< " "<<i<<" "<<flush;
		}
		a[j+1]=temp;

	}
}
int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int array[n];
		for(int j=0;j<n;j++)
		{
			cin>>array[j];
		}
		reArrange(array,n);
		printArray(array,n);


	}
	return 0;
}
