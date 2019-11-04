#include<bits/stdc++.h>
using namespace std;
#define deb(x,y,d) cout<<#x<<":"<<x<<" "<<#y<<":"<<y<<" "<<#d<<":"<<d<<endl;
struct Point
{
    int x;
    int y;
    int d;
    Point(int x,int y,int z):x(x),y(y),d(z)
    {      
    }
};
bool check(vector<vector<int>> &board,int m,int n,int x,int y)
{
    if(x>=m||y>=n||x<0||y<0)
        return false;
    if(board[x][y]==1)
        return false;
    return true;
}
int solve(vector<vector<int>> board,int x,int y)
{
    int m=board.size();
    int n=board[0].size();
    int dx[4]={0,+1,0,-1};
    int dy[4]={+1,0,-1,0};
    bool vis[n][m];
    memset(vis,false,sizeof(vis));
    int maxcoin=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]==2)
                maxcoin++;
        }
    }
    queue<Point> Q;
    Q.push({0,0,0});
    int coin =0;
    while(!Q.empty())
    {
        Point p=Q.front();
        Q.pop();
        int xx=p.x;
        int yy=p.y;
        int d=p.d;
        deb(xx,yy,d);
        if(vis[xx][yy])
            continue;
        vis[xx][yy]=true;
        if(board[xx][yy]==2)
        {
             coin++;
             board[xx][yy]=0;
             memset(vis,false,sizeof(vis));
             while(!Q.empty())
                 Q.pop();
        }
        if(x==xx&&y==yy)
        {
           if(coin==maxcoin)
            return d; 
        }
        for(int i=0;i<4;i++)
        {
            int xxx=xx+dx[i];
            int yyy=yy+dy[i];
            int dd=d+1;
            if(check(board,m,n,xxx,yyy))
                Q.push({xxx,yyy,dd});
        }



    }
    return -1;



}
int main()
{
    vector<vector<int>> board={
        {0,2,2},
        {1,0,2},
        {1,0,2}
    };
    cout<<solve(board,1,1)<<endl;
}