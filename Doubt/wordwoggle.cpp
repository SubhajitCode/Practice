#include<bits/stdc++.h>
using namespace std;

bool valid(vector<vector<char>> ch,int i,int j)
{
    int m,n;
    m=ch.size();
    n=ch[0].size();
    
    return (i>=0) && (j>=0) && (i<m) && (j<n);
}

bool DFS(int x,int y, string word,vector<vector<char>> ch, int m ,int n,vector<vector<bool>> vis)
{
    vis[x][y]=true;
    
    int row[]={ 1,-1, 1,-1,0,0,1,-1};
    int col[]={ 1,-1,-1, 1, 1,-1,0,0};
    
    int j=1;        
        for(int i=0; i <8; i++)
        {
            int xx=x+row[i];
            int yy=y+col[i];
        
             if(valid(ch,xx,yy) && j<word.size()&&word[j]== ch[xx][yy] )
             {
                 if(!vis[xx][yy])
                 if(DFS(xx,yy,word, ch, m,n,vis))
                    return true;
                 j++;
             }
        }
    
}

bool findword(string word, vector<vector<char>> ch, int m, int n)
{
    
    int x,y,i,j;
    for(i=0; i<m; i++)
    {
        for( j=0 ;j<n; j++)
        {
            if(word[0]==ch[i][j])
            {
                x=i,y=j;
                break;
            }
        }
        if(word[0]==ch[i][j])
            break;
    }
    
    vector <vector <bool>> vis(m , vector <bool> (n,false));
    
    return (DFS(x,y, word, ch, m ,n, vis));
    
}

void wordboggle(string str[], int n,vector<vector<char>>ch, int m, int k )
{
    for(int i=0; i<k ; i++)
    {
        if(findword(str[i],ch, m,k))
        cout<<str[i]<<" ";
    }
}


int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string str[n];
	    for(int i=0 ;i<n; i++)
	    cin>>str[i];
	    
	    int m,k;
	    cin>>m>>k;
	    vector<vector<char>>ch(m ,vector<char> (k));
	    for(int i=0; i<m; i++)
	        for(int j=0; j<k; j++)
	            cin>>ch[i][j];
	            
	    wordboggle(str ,n ,ch ,m, k );
	    cout<<endl;
	}
	return 0;
}