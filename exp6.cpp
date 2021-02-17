#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
#define inf 0x7fffffff
int d[105][105]={0};
int v[105][105];
int dx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int m,n,ans=inf;

void dfs(int xl,int yl,int suml,bool frog)
{
     if(xl<1||yl<1||xl>m||yl>m) return ;
     if(suml>=v[xl][yl]) return ;
     v[xl][yl]=suml;
     if(xl==m&&yl==m)
     {
         if(suml<ans) ans=suml;
         return ;
     }
     for(int i=0;i<4;++i)
     {
         int xx=xl+dx[i][0];
         int yy=yl+dx[i][1];
         if(d[xx][yy])
         {
             if(d[xl][yl]==d[xx][yy])
                dfs(xx,yy,suml,false);
             else
             {
                dfs(xx,yy,suml+1,false);
             }

         }
         else
         {
             if(!frog)
             {
                 d[xx][yy]=d[xl][yl];
                 dfs(xx,yy,suml+2,true);
                 d[xx][yy]=0;
             }
         }
         
     }

}
int main()
{
    memset(v,0x7f,sizeof(v));
    cin>>m>>n;
    int x,y,c;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>c;
        d[x][y]=c+1;
    }
    dfs(1,1,0,false);
    //return 0;
    printf("%d",ans==inf?-1:ans);
    return 0;
}