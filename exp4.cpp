#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
bool vis[31][31];
typedef struct
{
    /* data */
    int x,y;
}node;

int n;
int d[31][31];
void bfs(int a,int b)
{
    queue<node> q;
    node p,head;
    if(d[a][b]==2) {p.x=a;p.y=b;d[a][b]=0;q.push(p);}
    while(!q.empty())
    {
        head=q.front();
        //d[head.x][head.y]=0;
        a=head.x;b=head.y;
        q.pop();

        if(a+1<=n)
        {
            if(d[a+1][b]==2){p.x=a+1;d[a+1][b]=0;q.push(p);}
        }
        if(b+1<=n)
        {
            if(d[a][b+1]==2){p.y=b+1;d[a][b+1]=0;q.push(p);}
        }
        if(a-1>=0)
        {
            if(d[a-1][b]==2){p.x=a-1;d[a-1][b]=0;q.push(p);}
        }
        if(b-1>=0)
        {
            if(d[a][b-1]==2){p.y=b-1;d[a][b-1]=0;q.push(p);}
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    d[i][j]=2;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        {cin>>d[i][j];if(d[i][j]==0) d[i][j]=2;}
    for(int i=1;i<=n;i++)
    {
        bfs(1,i);
        bfs(i,1);
        bfs(n,i);
        bfs(i,n);
    }
    //bfs(0,0);
    for(int i=1;i<=n;i++)
    {for(int j=1;j<=n;j++)
    cout<<d[i][j]<<' ';
    cout<<endl;}
    return 0;
}