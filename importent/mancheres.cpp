#include <bits/stdc++.h>
using namespace std;
#define SIZE 100000 + 1

int P[SIZE * 2];

// Transform S into new string with special characters inserted.
string convertToNewString(const string &s) {
    string newString = "@";

    for (int i = 0; i < s.size(); i++) {
        newString += "#" + s.substr(i, 1);
    }

    newString += "#$";
    return newString;
}

string longestPalindromeSubstring(const string &s) {
    string Q = convertToNewString(s);
    int C=0,R=-1,rad;
    int P[N];
    for(int i=0;i<Q.size();i++)
    {
        
        if(i<=R)
        {
            int mirror=2*C-i;
            rad=min(Q[mirror],)
        }
        else
        {
            rad=0;
        }
        
    }
}

int main() {
    cout<<"enteryour string : "<<endl;
    string s;
    cin>>s;
	cout << longestPalindromeSubstring(s)<<endl;
    return 0;
}
