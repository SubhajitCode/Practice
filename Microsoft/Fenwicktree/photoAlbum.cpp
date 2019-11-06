#include<bits/stdc++.h>
using namespace std;
class FenWick
{
    int *BIT;
    int size;
    public:
    FenWick(int siz):size(siz+2)
    {
        BIT=new int[size];
        for(int i=0;i<size;i++)
            BIT[i]=0;
    }
    void update(int x,int delta)
    {
        //cout<<x<<endl;
        for(;x>0&&x<=size;x+=(x&(-x)))
        {
            BIT[x]+=delta;
        }
    }
    void insert(int x)
    {
        update(x,1);
    }
    void remove(int x)
    {
        update(x,-1);
    }
    int query(int x)
    {
        //cout<<x<<endl;
        int sum=0;
        for(;x>0;x-=(x&(-x)))
        {
            sum+=BIT[x];
        }
        return sum;
    }
    int kth_elemnt(int k)
    {
        int l=0,h=size;
        while(l<h)
        {
            int mid=(l+h)/2;
            int midval=query(mid);
            if(k<=midval)
            {
                h=mid;
            }
            else
            {
                l=mid+1;
            }
            
        }
        return l;

    }
};
int main()
{
    vector<int> arr={0,1,2,3,4};
    vector<int> brr={0,1,2,1,2};
    vector<int> res1,res2(arr.size());
    int n=arr.size();
    //naive solution
    for(int i=0;i<n;i++)
    {
        res1.insert(res1.begin()+brr[i],arr[i]);
    }
    for(int i=0;i<res1.size();i++)
        cout<<res1[i]<<" ";
    cout<<endl;
    //fenwick solution
    FenWick fw=FenWick(n);
    for(int i=0;i<n;i++)
    {
        fw.insert(i);
    }
    for(int i=n-1;i>=0;i--)
    {
        int index=brr[i];
        index=fw.kth_elemnt(index);//find keth order statistics (log2 (N)^2)
        res2[index]=arr[i];
        fw.remove(index);//remove from tree
    }
    for(int i=0;i<res2.size();i++)
        cout<<res2[i]<<" ";
    cout<<endl;
    
    
}