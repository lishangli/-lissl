#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define maxn 30005
int n,m;
int v,w;
typedef struct
{
    /* data */
    int vv,ww,ss;
}node;

int dp[maxn];
node d[30];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>d[i].vv>>d[i].ww;
        d[i].ss=d[i].vv*d[i].ww;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=n;j-d[i].vv>=0;j--)
        {
           
            dp[j]=max(dp[j],dp[j-d[i].vv]+d[i].ss);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}