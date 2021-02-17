#include<iostream>
#include<cstdio>
using namespace std;
long long l,n,m;
long long d[50005],ans;
bool check(long long mid)
{
    int temp=0,now=0;
    for(int i=1;i<=n;i++)
    {
        if(d[i]-d[now]<mid) temp++;
        else now=i;
    }
    if(temp>m) return false;
    return true;
}
int main()
{
    scanf("%d %d %d",&l,&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&d[i]);
    }
    int lb=0,rb=l;
    while(lb<=rb)
    {
        long long mid=(lb+rb)>>1;
        if(check(mid)) ans=mid,lb=mid+1;
        else rb=mid-1;
    }
    printf("%d",ans);
    return 0;
}