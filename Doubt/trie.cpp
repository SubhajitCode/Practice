#define deb(x) cout<<#x<<" : "<<x<<endl
#include<bits/stdc++.h>
using namespace std;
class Trie
{
    public:
    unordered_map<char,Trie*> trieMap;
    bool isEnd=false;
    Trie()
    {
        trieMap.clear();
        isEnd=false;
    }
};
void insert(Trie* root,string key)
{
    Trie* pCrawl=root;
    for(int i=0;i<key.length();i++)
    {
        if(pCrawl->trieMap.find(key[i])==pCrawl->trieMap.end())
        {
            pCrawl->trieMap[key[i]]=new Trie();
        }
        pCrawl=pCrawl->trieMap[key[i]];
    }
    pCrawl->isEnd=true;
    
}
bool search(Trie* root,string key)
{
    Trie* pCrawl=root;
    for(int i=0;i<key.length();i++)
    {
        if(pCrawl->trieMap.find(key[i])==pCrawl->trieMap.end())
            return false;
	else
	{
		cout<<"found"<<i<<" "<<key[i]<<endl;
	}

	pCrawl=pCrawl->trieMap[key[i]];
    }
    return true;
}
vector<string> tokenize(string input)
{
    string temp="";
    vector<string> tokens;
    for(int i=0;i<input.size();i++)
    {
        if(input[i]=='_')
        {
            tokens.push_back(temp);
            temp="";
        }
        else
        {
            temp+=input[i];
        }
    }
    if(temp!="")
    {
        tokens.push_back(temp);
    }
    return tokens;
}
int main()
{
	string str1="my";
	string str2="name";
	string str3="subhajit";
	string key="name";
	Trie* root=new Trie();
	insert(root,str1);
	insert(root,str2);
	if(search(root,key))
		cout<<"yes"<<endl;
	else
		cout<<"No"<<endl;

return 0;
}
