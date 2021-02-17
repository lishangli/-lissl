#include<iostream>
using namespace std;

long long d[1005];
bool vis[1005];
long long sum[1005];
int n,c;
long long ansl=0;
void dfs(int x,long long ca)
{
    if(ca>c) return ;
    if(ca+sum[x-1]<=c)
    {
        if(ansl<ca+sum[x-1]) ansl=ca+sum[x-1];
        return ;
    }
    if(ansl<ca) ansl=ca;
    for(int i=x-1;i>=1;i--)
    {
            dfs(i,ca+d[i]);
    }
}

int main()
{
    cin>>n>>c;
    int p=0;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i];
        sum[i]=sum[i-1]+d[i];
    }
    dfs(n+1,0);
    cout<<ansl;
    return 0;
    
}