#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 25005
int d[25][105];
int dp[maxn];
int t,n;
int res[25];
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        memset(dp,0,sizeof(dp));
        int p=1;
        int maxs=0;
        while(p<=n)
        {
            cin>>d[i][p];
            maxs=max(d[i][p],maxs);
            p++;
        }
        sort(d[i]+1,d[i]+n+1);
        int resl=0;

        for(int j=1;j<=n;j++)
        {
            if(dp[d[i][j]]) continue;
            resl++;
            dp[d[i][j]]=1;
            for(int k=d[i][j];k<=maxs;k++)
            {
                if(dp[k-d[i][j]]) dp[k]=1;
            }
        }
        cout<<resl<<endl;
    }
    return 0;
}