#include<iostream>
#include<vector>
using namespace std;
void printarry(int arr[],int n)
{
	for(int i=0;i<(n);i++)
		cout<<arr[i]<<" ,";
}

void assign(int arr[],int n)
{
        for(int i=0;i<(n+15);i++)
                arr[i]=i;

}
int main()
{

	int arr[10];
	int n=10;
	for(int i=0;i<n;i++)
		arr[i]=i;
	printarry(arr,n);
	assign(arr,n);
	printarry(arr,n);
	return 1;
}
