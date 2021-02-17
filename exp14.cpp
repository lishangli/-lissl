#include<iostream>
#include<cmath>
using namespace std;
int n;
int mp[1005][1005];
int dp[1005][1005];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        cin>>mp[i][j];
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+mp[i][j];
    }
    cout<<dp[1][1]<<endl;
    return 0;
}