/*
    coder:lsl
    datess :2021/2/17/ 17:05
    p1868 饥饿的奶牛
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 3000005

int n;
int dp[maxn];
int r,l;
vector<int> mp[maxn];

int main()
{
    cin>>n;
    int maxl=0;
    
    for(int i=1;i<=n;i++)
    {
        cin>>r>>l;
        mp[l].push_back(r);
        maxl=max(l,maxl);
    }
    for(int i=1;i<=maxl;i++)
    {
        dp[i]=dp[i-1];
        for(int j=0;j<mp[i].size();j++)
        {
            int rr=mp[i][j];
            dp[i]=max(dp[i],dp[rr-1]+i-rr+1);
        }
    }
    cout<<dp[maxl];
    return 0;
}