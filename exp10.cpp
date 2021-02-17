#include<iostream>
#include<queue>
#include<string>
using namespace std;

string mp[105];
int dp[105][105][20]={0};
int n,m,t;
int r1,c1,r2,c2;
int ans=0;
int dx[4][2]={1,0,0,1,-1,0,0,-1};

typedef struct
{
    int x,y,c;
}node;

void bfs()//宽搜
{
    queue<node> q;
    node p,p1,p2;
    p.x=r1,p.y=c1,p.c=0;
    q.push(p);
    int xx,yy,tt;
    dp[p.x][p.y][0]=1;
    while(!q.empty())
    {
        p1=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            xx=p1.x+dx[i][0];
            yy=p1.y+dx[i][1];
            tt=p1.c+1;
            if(xx>n||xx<1||yy>m||yy<1||mp[xx][yy-1]=='*'||tt>t)
            {
                //ct1++;
                continue;
            }
            if(dp[xx][yy][tt])
            {
                dp[xx][yy][tt]+=dp[p1.x][p1.y][p1.c];
                continue;
            }
                p2.x=xx;
                p2.y=yy;
                p2.c=tt;
                q.push(p2);
                dp[xx][yy][tt]+=dp[p1.x][p1.y][p1.c];
        }
        //if(ct==0) {step++;ct=ct1;ct1=0;}
    }
}

int main()
{
    cin>>n>>m>>t;
    char c;
    for(int i=1;i<=n;i++)
    {
        cin>>mp[i];
    }
    cin>>r1>>c1>>r2>>c2;
    bfs();
    cout<<dp[r2][c2][t];  
    return 0;
}