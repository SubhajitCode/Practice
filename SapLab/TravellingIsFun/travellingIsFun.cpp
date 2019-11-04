#include <bits/stdc++.h>

using namespace std;

int gcd(int m,int n)
{
    if(n>m)
        swap(n,m);
    if(n==1)
        return 1;
    if(n==0)
        return m;
    return(gcd(m%n,n));
}

class unionFind
{
    int *parrent;
    int size=0;
    public:
    unionFind(int n)
    {
        parrent=new int[n];
        size=n;
        for(int i=0;i<n;i++)
        {
            parrent[i]=-1;
        }
    }
    int find(int x)
    {
        int tmp=x;
        while(parrent[x]>0)
        {
            x=parrent[x];
        }
        if(x!=tmp)
            parrent[tmp]=x;
        return x;    
        
    }
    void Union(int x,int y)
    {
        int xset=find(x);
        int yset=find(y);
        if(xset==yset)
            return;
        if(yset>xset)
            swap(yset,xset);
        int tmp=parrent[yset];
        parrent[yset]=xset;
        parrent[xset]+=tmp;
            return;
        
    }
    
};

vector <int> connectedCities(int n, int g, vector <int> originCities, vector <int> destinationCities) {
    // Complete this function
    unionFind U=unionFind(n+1);
    for(int i=g+1;i<=n;i++)
    {
        for(int j=2*i;j<=n;j+=i)
        {
            U.Union(i,j);
        }
        
    }
    vector<int> res(originCities.size());
    for(int i=0;i<originCities.size();i++)
    {
        int x=U.find(originCities[i]);
        int y=U.find(destinationCities[i]);
        if(x==y)
        {
            res[i]=1;
        }
        else
        {
            res[i]=0;
        }
    }
    return res;
    
}

int main() {
    int n;
    cin >> n;
    int g;
    cin >> g;
    int originCities_cnt;
    cin >> originCities_cnt;
    vector<int> originCities(originCities_cnt);
    for(int originCities_i = 0; originCities_i < originCities_cnt; originCities_i++){
        cin >> originCities[originCities_i];
    }
    int destinationCities_cnt;
    cin >> destinationCities_cnt;
    vector<int> destinationCities(destinationCities_cnt);
    for(int destinationCities_i = 0; destinationCities_i < destinationCities_cnt; destinationCities_i++){
        cin >> destinationCities[destinationCities_i];
    }
    vector <int> res = connectedCities(n, g, originCities, destinationCities);
    for (ssize_t i = 0; i < res.size(); i++) {
        cout << res[i] << (i != res.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}