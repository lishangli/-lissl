#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#include<cstdio>
using namespace std;

typedef struct
{
    int x,y;
}node;
const int dx[4]={1,-1,2,-2};
const int dy[4]={1,-1,2,-2};
int d[401][401];
int n,m,xr,yr;
//判断是否越界
bool test(int nx,int ny)
{
    if(nx<=n&&ny<=m&&nx>=1&&ny>=1) return true;
    return false;
}
//广度优先搜索
void bfs(int a,int b)
{
    d[a][b]=0;
    queue<node> q;
    node p,h;
    p.x=a,p.y=b;
    q.push(p);
    while(!q.empty())
    {
        h=q.front();
        q.pop();
        for(int i=0;i<4;i++)//广度遍历
        {
            for(int j=0;j<4;j++)
            {
                if(abs(dx[i])!=abs(dx[j])){
                int nx=h.x+dx[i];
                int ny=h.y+dy[j];
                if(test(nx,ny))
                {
                    if(d[nx][ny]==-1)
                    {
                        p.x=nx,p.y=ny;
                        q.push(p);
                        d[p.x][p.y]=d[h.x][h.y]+1;
                    }
                }
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m>>xr>>yr;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    d[i][j]=-1;
    bfs(xr,yr);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        printf("%-5d",d[i][j]);
        printf("\n");
    }
    return 0;
}