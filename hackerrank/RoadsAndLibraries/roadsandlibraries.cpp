#include <bits/stdc++.h>

using namespace std;
#define deb(x) cout<<#x<<" : "<<x<<endl
vector<string> split_string(string);

class unionfind
{
    private:
    int *parrent;
    int size;
    public:
    unionfind(int sz):size(sz)
    {
        parrent=new int[sz];
        for(int i=0;i<sz;i++)
            parrent[i]=-1;
    }
    int find(int i)
    {
        //deb(i);
        int j=i;
        while(parrent[i]>0)
        {
           // deb(i);
            i=parrent[i];
        }
        if(i!=j)
            parrent[j]=i;
        return i;
    }

    void myUnion(int i,int j)
    {
            int xset =find(i);
            int yset =find(j);
            if(xset==yset)
                return;
            if(parrent[xset]>parrent[yset])
            {
                swap(xset,yset);
            }
            int tmp=parrent[yset];
            parrent[yset]=xset;
            parrent[xset]=parrent[xset]+tmp;
    }
    long components()
    {
        long sum=0;
        for(int i=1;i<size;i++)
        {
           // deb(parrent[i]);
            if(parrent[i]<0)
            {
                sum++;
            }
        }
        return sum;

    }

};

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    unionfind U= unionfind(n+1);

    //int roads=0;
    for(auto city:cities)
    {
        int u=city[0];
        int v=city[1];
        U.myUnion(u,v);
    }
    long component=U.components();
    deb(component);
    long roads=n-component;
    long cost=component*c_lib+roads*c_road;
    while(roads>0)
    {
        roads--;
        component++;
        cost=min(cost,component*c_lib+roads*c_road);
    }
    return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
