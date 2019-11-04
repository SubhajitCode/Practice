#include<bits/stdc++.h>
using  namespace std;
class Solution {
public:
    bool util(string s,string p,int i,int j,vector<vector<int>> &dp)
    {
        if(i>s.length()||j>p.length())
            return false;
        if(j==p.length())
            return (i==s.length());
        if(i==s.length())
        {
            if(j==p.length())
                return 1;
            else if(j+1<p.length()&&p[j+1]=='*')
                return util(s,p,i,j+2,dp);
            else 
                return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]!=p[j]&&p[j]!='.')
        {
            if(j+1<p.length()&&p[j+1]=='*')
            {
                dp[i][j]=util(s,p,i,j+2,dp);
            }
            else
            {
                dp[i][j]=0;
            }
        }
        else
        {
            if(j+1<p.length()&&p[j+1]=='*')
            {
                dp[i][j]=util(s,p,i,j+2,dp)|util(s,p,i+1,j,dp);
            }
            else
            {
                dp[i][j]=util(s,p,i+1,j+1,dp);
            }
            
        }
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        
        int n= s.length();
        int m=p.length();
        /*if(p.empty())
            return s.empty();*/
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return util(s,p,0,0,dp);
        
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);
        
        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}