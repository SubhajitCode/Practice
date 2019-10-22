#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void construct_left(vector<long>&arr,vector<long>&left)
{
    stack<long> stack;
    while(!stack.empty())
    stack.pop();
    for(int i=0;i<arr.size();i++)
    {
        if(stack.empty())
        {
            stack.push(i);
            left[i]=-1;
        }
        else if(arr[stack.top()]<arr[i])
        {
            left[i]=stack.top();
            stack.push(i);
        }
        else
        {
            while(!stack.empty()&&arr[stack.top()]>=arr[i])
            {
                stack.pop();
            }
            if(stack.empty())
            {
                stack.push(i);
                left[i]=-1;
            }
            else
            {
                left[i]=stack.top();
                stack.push(i);
            }

        }
        cout<<left[i]<<" ";

    }
    cout<<"left"<<endl;
}

void construct_right(vector<long>&arr,vector<long>&left)
{
    stack<long> stack;
    while(!stack.empty())
        stack.pop();
    int n=arr.size();
    for(int i=n-1;i>=0;i--)
    {
        
        if(stack.empty())
        {
            stack.push(i);
            left[i]=-1;
        }
        else if(arr[stack.top()]<arr[i])
        {
            left[i]=stack.top();
            stack.push(i);
            
        }
        else
        {
            while(!stack.empty()&&arr[stack.top()]>=arr[i])
            {
                stack.pop();
            }
            if(stack.empty())
            {
                stack.push(i);
                left[i]=-1;
            }
            else
            {
                left[i]=stack.top();
                stack.push(i);
            }

        }
        cout<<left[i]<<" ";

    }
    cout<<"right"<<endl;
}

// Complete the riddle function below.
vector<long> riddle(vector<long> arr) {
    // complete this function
    int n=arr.size();
    vector<long> res(n,0);
    vector<long> left(n,0);
    vector<long> right(n,0);
    construct_left(arr,left);
    construct_right(arr,right);
    for(int i=0;i<n;i++)
    {
        int len=0;
        if(left[i]==-1&&right[i]==-1)
        {
                len=n;
        }
        else if(left[i]==-1)
        {
            len=right[i];
        }
        else if(right[i]==-1)
        {
            len=n-left[i]-1;
        }
        else
        {
            len=right[i]-left[i]-1;
        }

        res[len-1]=max(res[len-1],arr[i]);
        
    }
    for(int i=n-2;i>=0;i--)
    {
        res[i]=max(res[i],res[i+1]);
    }
    
    return res;

    
   

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<long> res = riddle(arr);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
