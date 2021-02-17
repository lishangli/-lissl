#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 205

int n,m,t;
int dp[maxn][maxn];
int ww[maxn],tt[maxn];
int main()
{
    cin>>n>>m>>t;
    //int ww,tt;
    for(int i=1;i<=n;i++)
    {
        cin>>ww[i]>>tt[i];
        //dp[ww][tt]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=ww[i];j--)
        {
            for(int k=t;k>=tt[i];k--)
            {
                dp[j][k]=max(dp[j-ww[i]][k-tt[i]]+1,dp[j][k]);
            }
        }
    }
    cout<<dp[m][t]<<endl;
}