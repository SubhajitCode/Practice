#include<bits/stdc++.h>
using namespace std;
bool happyCheck(vector<int> input,int K)
{
    int size=input.size();
    int count=0;
    for(int i=0;i<size-1;i++)
    {
        if(input[i]!=input[i+1])
        {
            count++;
        }
        if(count>K)
            return false;
    }
    return true;
}
int flatten(vector<int> input,int K)
{
    int N=input.size();
    int total=pow(2,N);
    int minNum=INT_MAX;
    for(int mask=0;mask<total;mask++)
    {
        int tmp=1;
        vector<int> input_cpy(input);
        for(int i=0;i<N;i++)
        {
            tmp=1<<i;
            if(mask&tmp)
            {
                input_cpy.erase(input_cpy.begin()+input_cpy.size()-1-i);
            }
        }
        if(happyCheck(input_cpy,K))
        {
            int size=input_cpy.size();
            int removed=N-size;
            minNum=min(removed,minNum);
        }
    }

    return minNum;
}
int main()
{
    int test_case=0;
    int t;
    cin>>t;
    while(t--)
    {
        test_case++;
        int N,K;
        cin>>N>>K;
        vector<int> input(N);
        for(int i=0;i<N;i++)
        {
            int tmp;
            cin>>tmp;
            input[i]=tmp;
        }
        int res=flatten(input,K);
        cout<<"Case #"<<test_case<<": "<<res<<endl;


    }
}