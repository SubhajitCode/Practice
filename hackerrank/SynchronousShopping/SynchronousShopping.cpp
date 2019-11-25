#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'shop' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. STRING_ARRAY centers
 *  4. 2D_INTEGER_ARRAY roads
 */
#define INF 9999999
typedef pair<int,int> pp;
int shop(int n, int k, vector<string> centers, vector<vector<int>> roads) {

    vector<int> fishes(n+1);
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=1;i<=n;i++)
    {
        fishes[i]=0;
        string tmp=centers[i-1];
        stringstream ss(tmp);
        string nums;
        ss>>nums;
        while(ss>>nums)
        {
            int num=stoi(nums);
            fishes[i]|=1<<num;
        }  
    }
    for(auto road:roads)
    {
        int u=road[0];
        int v=road[1];
        int w=road[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<vector<long long>> bitmask(n+1,vector<long long>(2048,INT_MAX));
    //int bitmask[n+1][2048];
   // memset(bitmask,INF,sizeof(bitmask));
    int fish=fishes[1];
    bitmask[1][fish]=0;
    priority_queue<pair<int,pp>,vector<pair<int,pp>>,greater<pair<int,pp>>> pq;
    pq.push({0,{1,fish}});
    while(!pq.empty())
    {
        auto temp=pq.top();
        int weight=temp.first;
        int u=temp.second.first;
        int fish_u=temp.second.second;
        pq.pop();
        for(auto elem:adj[u])
        {
            int v=elem.first;
            int w=elem.second;
            int fish_v=fish_u|fishes[v];
            if(bitmask[v][fish_v]>bitmask[u][fish_u]+w)
            {
                bitmask[v][fish_v]=bitmask[u][fish_u]+w;
                pq.push({bitmask[v][fish_v],{v,fish_v}});
            }
        }
    }
    long long ans=INT_MAX;
   /* for(int i=0;i<1024;i++)
    {
        if(bitmask[n][i]<INF)
        {
            bitset<10> bs(i);
            cout<<"fish : "<<bs<<" dist : "<<bitmask[n][i]<<endl;
        }
    }*/

    for(int i=0;i<2*1024;i++)
    {
        for(int j=0;j<2*1024;j++)
        {

            if(__builtin_popcount((i|j))==k)
            {
                
                ans=min(ans,max(bitmask[n][i],bitmask[n][j]));
            }

        }
    }
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int k = stoi(first_multiple_input[2]);

    vector<string> centers(n);

    for (int i = 0; i < n; i++) {
        string centers_item;
        getline(cin, centers_item);

        centers[i] = centers_item;
    }

    vector<vector<int>> roads(m);

    for (int i = 0; i < m; i++) {
        roads[i].resize(3);

        string roads_row_temp_temp;
        getline(cin, roads_row_temp_temp);

        vector<string> roads_row_temp = split(rtrim(roads_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int roads_row_item = stoi(roads_row_temp[j]);

            roads[i][j] = roads_row_item;
        }
    }

    int res = shop(n, k, centers, roads);

    fout << res << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
