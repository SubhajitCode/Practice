//https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0/?ref=self 
#include <bits/stdc++.h> 
using namespace std;
void build_segtree(int arr[],int seg[],int n)
{
	// insert leaf nodes in tree
    for (int i=0; i<n; i++)
        seg[n+i] = arr[i];

    // build the tree by calculating parents
    for (int i = n - 1; i > 0; --i)
        seg[i] = max(seg[i<<1] ,seg[i<<1 | 1]);

}

int query(int seg[],int l, int r,int n)
{
    int res = INT_MIN;

    // loop to find the sum in the range
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l&1)
            res = max(res,seg[l++]);

        if (r&1)
            res = max(res,seg[--r]);
    }

    return res;
}
int main()
{
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;

		int arr[n],seg[4*n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		build_segtree(arr, seg,n);
		for(int i=0;i<n-k+1;i++)
			cout<<query(seg,i, i+k,n)<<" ";
		cout<<endl;
	}
}
