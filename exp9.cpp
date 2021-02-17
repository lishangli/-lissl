#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int mp[505][505];
bool vis[505][505];
int dx[4][2]={1,0,0,1,-1,0,0,-1};
int n,m;
int ans=0;

typedef struct
{
    /* data */
    int x,y;
}node;

void bfs(int xl,int yl)
{
    queue<node> p;
    node q;
    q.x=xl,q.y=yl;
    p.push(q);
    while(!p.empty())
    {
        q=p.front();
        //int xx=q.x,yy=q.y;
        for(int i=0;i<4;i++)
        {
            int xx=q.x+dx[i][0];
            int yy=q.y+dx[i][1];
            if(mp[q.x][q.y]>mp[xx][yy]&&vis[xx][yy]==false)
            {
                vis[xx][yy]=true;
                if(xx==n) ans++;
                node r;
                r.x=xx;
                r.y=yy;
                p.push(r);
            }
        }
    }

}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>mp[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            ans=0;
            for(int k=1;k<n;k++)
            {
                if(!vis[1][k])
                {
                    vis[1][k]=true;
                    bfs(1,k);
                    //vis[1][]
                }
            }
        }
    }
}