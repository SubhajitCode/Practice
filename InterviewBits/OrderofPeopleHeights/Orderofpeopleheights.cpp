typedef pair<int,int> pii;
void find_pos(vector<pii> &vec,vector<int> &ans,int pos)
{
    auto P=vec[pos];
    int num=P.first;
    int pos2=P.second+1;
    int offset=0;
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]==-1)
          pos2--;
         if(pos2==0)
         {
                ans[i]=num;
                break;
         }
        
    }
}
vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    vector<pii> vec;
    vector<int> ans(A.size(),-1);
    for(int i=0;i<A.size();i++)
    {
        vec.push_back({A[i],B[i]});
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++)
    {
       find_pos(vec,ans,i);
    }
    return ans;
}
