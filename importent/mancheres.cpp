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
    for(int i=0;i<Q.size();i++)
    {
        
        if(i<=R)
        {
            int mirror=2*C-i;
            /*
            rad=radius from i can be 
            case a) =P[mirror] if P[mirror]<(R-i)
                    else i+rad will extend beyond R
            case b) R-i else 

            */
            rad=min(P[mirror],R-i);
        }
        else
        {
            rad=0;
        }
        while((i+rad+1)<Q.length()&&(i-rad-1)>=0&&Q[i+rad+1]==Q[i-rad-1])
        {
            rad++;
        }
        P[i]=rad;
        if(i+rad-1>R)
        {
            C=i;
            R=i+rad-1;
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
