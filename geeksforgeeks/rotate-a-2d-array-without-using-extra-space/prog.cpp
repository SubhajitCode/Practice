#include <bits/stdc++.h>
using namespace std;
int n;
int get_old(vector<vector<int>> &arr,int i,int j)
{
    int val=arr[i][j];
    val=val%100;
    return val;
    
}
int get_new(vector<vector<int>> &arr,int i,int j)
{
    return(arr[i][j]/100);
}
void put_new(vector<vector<int>> &arr,int i,int j,int value)
{
    arr[i][j]=arr[i][j]/100;
}
void put_two_value(vector<vector<int>> &arr,int i,int j,int value)
{
    int old_val=arr[i][j];
    int new_val=old_val+100*value;
    arr[i][j]=new_val;
}

int main() {
	//code
	int t;
	cin >>t;
    while(t--)
    {
        cin>>n;
        vector<vector<int>> arr;
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                int v;
                cin>>v;
                temp.push_back(v);             
            }
            arr.push_back(temp);
                
        }
            
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int idx=n-1-j;
                int value=get_old(arr,idx,i);
                put_two_value(arr,i,j,value);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<get_new(arr,i,j)<<" ";
            }
        }
	    cout<<endl;
        
    }
	return 0;
} 
