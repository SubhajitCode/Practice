#include<bits/stdc++.h>
using namespace std;
struct treeNode
{
    int key;
    int right_size;
    int data;
    int index;
    treeNode* left;
    treeNode* right;
    treeNode(int x,int y,int i)
    {
        key=x;
        data=y;
        index=i;
        right_size=0;
        left=NULL;
        right=NULL;
    }
    treeNode* insert(int Key,int data,int i)
    {
        if(this==NULL)
        {
            treeNode *curr=new treeNode(Key,data,i);
            return curr;
        }
        if(this->key<=Key)
        {
            //cout<<this->key<<" "<<Key<<endl;
            this->right_size++;
            this->right=this->right->insert(Key,data,i);
        }
        else
        {
            this->left=this->left->insert(Key,data,i);
        }
        return this;
        
    }
    void print()
    {
        if(this==NULL)
            return;
        cout<<"{"<<this->data<<"," <<this->key<<","<<this->right_size<<"}"<<endl;
        this->left->print();
        this->right->print();
    }
    treeNode* find(int i,int k)
    {
        if(this==NULL)
            return NULL;
        if(this->index==i)
            return this;
        if(k>=this->key)
            return this->right->find(i,k);
        else 
            return this->left->find(i,k);
    }

};
int main()
{
    vector<int> arr={0,1,2,3,4};
    vector<int> brr={0,1,2,1,2};
    vector<int> res1,res2(arr.size());
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        res1.insert(res1.begin()+brr[i],arr[i]);
    }
    for(int i=0;i<res1.size();i++)
        cout<<res1[i]<<" ";
    cout<<endl;
    treeNode *root=new treeNode(arr[0],brr[0],0);
    for(int i=1;i<n;i++)
    {
        root->insert(brr[i],arr[i],i);
    }

    root->print();
    for(int i=n-1;i>=0;i--)
    {
        treeNode* tmp=root->find(i,brr[i]);
        res2[brr[i]+tmp->right_size]=arr[i];

    }
    cout<<endl;
    for(int i=0;i<res1.size();i++)
        cout<<res1[i]<<" ";
    cout<<endl;
}