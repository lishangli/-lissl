#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int mp[201][201];
int dp[201][201];
int r,c,ans=0;
int maxl=0;

int dfs(int x,int y)
{
    if(dp[x][y]) return dp[x][y];
    int xx,yy;
    dp[x][y]=1;
    for(int i=0;i<4;i++)
    {
        
            xx=x+dx[i];
            yy=y+dy[i];
            if(xx>=1&&xx<=r&&yy>=1&&yy<=c&&mp[x][y]>mp[xx][yy])
            { 
                
                dp[x][y]=max(dp[x][y],dfs(xx,yy)+1);
            }
    }
    return dp[x][y];
}

int main()
{
    cin>>r>>c;
    for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++)
    {
        cin>>mp[i][j];
        //dp[i][j]=1;
    }
    for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++)
    {
        ans=max(ans,dfs(i,j));
    }
    cout<<ans;
    return 0;
}