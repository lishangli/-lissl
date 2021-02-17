#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int mp[105];
int d1[105],d2[105];
int main()
{
    cin>>n;
    int mi=1;
    int len1=1,len2=1;
    //d1[1]=mp[1];
    for(int i=1;i<=n;i++)
    {
        cin>>mp[i];
        //if(mp[mi]<mp[i]) mi=i;
    }
   // cout<<mi<<endl;
    int maxl=0;
    for(int k=1;k<=n;k++)
    {
        memset(d1,0,sizeof(d1));
        memset(d2,0,sizeof(d2));
        d1[1]=mp[1];
        d2[1]=mp[k];
        len1=1,len2=1;
    for(int i=2;i<=k;i++)
    {
        if(d1[len1]<mp[i]) d1[++len1]=mp[i];
        else
        {
            int p1=lower_bound(d1+1,d1+len1+1,mp[i])-d1;
            d1[p1]=mp[i];
        }
    }
    for(int i=k+1;i<=n;i++)
    {
        if(d2[len2]>mp[i]) d2[++len2]=mp[i];
        else
        {
            int p2=lower_bound(d2+1,d2+len2+1,mp[i],greater<int>())-d2;
            d2[p2]=mp[i];
        }
    }
    maxl=max(maxl,len1+len2-1);
    }
    cout<<n-maxl;
    return 0;
}