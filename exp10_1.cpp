#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct node{
    int x,y,s;	//x、y表示坐标，s表示时间
};
queue<node>q;
int n,m,t,r1,c1,r2,c2,dp[110][110][20];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};	//移动
string s[110];
int main()
{
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    cin>>r1>>c1>>r2>>c2;
    dp[r1][c1][0]=1;	//初始方案数为1
    q.push(node{r1,c1,0});
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            node th;
            th.x=u.x+dx[i];
            th.y=u.y+dy[i];
            th.s=u.s+1;
            if(dp[th.x][th.y][th.s])
            {
                dp[th.x][th.y][th.s]+=dp[u.x][u.y][u.s];
                continue;	//当前状态曾被拓展
            }
            if(th.x<1||th.x>n||th.y<1||th.y>m||s[th.x][th.y-1]=='*'||th.s>t)
                continue;	//越界或不能走或超时，跳过
            dp[th.x][th.y][th.s]+=dp[u.x][u.y][u.s];	//计数
            q.push(th);
        }
    }
    cout<<dp[r2][c2][t]<<endl;
    return 0;
}