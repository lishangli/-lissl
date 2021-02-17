#include<iostream>
#include<algorithm>
using namespace std;

int n,m,res=0;
int a[355],b[5];
int dp[45][45][45][45];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dp[0][0][0][0]=a[1];
    int index;
    for(int i=1;i<=m;i++)
    {
        cin>>index;
        b[index]++;
    }
    for(int i=0;i<=b[1];i++)
    {
        for(int j=0;j<=b[2];j++)
        {
            for(int k=0;k<=b[3];k++)
            {
                for(int p=0;p<=b[4];p++)
                {
                    int r=i+j*2+k*3+p*4+1;
                    if(i!=0) dp[i][j][k][p]=max(dp[i][j][k][p],dp[i-1][j][k][p]+a[r]);
                    if(j!=0) dp[i][j][k][p]=max(dp[i][j][k][p],dp[i][j-1][k][p]+a[r]);
                    if(k!=0) dp[i][j][k][p]=max(dp[i][j][k][p],dp[i][j][k-1][p]+a[r]);
                    if(p!=0) dp[i][j][k][p]=max(dp[i][j][k][p],dp[i][j][k][p-1]+a[r]);
                }
            }
        }
    }
    cout<<dp[b[1]][b[2]][b[3]][b[4]];
    return 0;
}