#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int mp[100005];
int d1[100005];
int d2[100005];
int n;

int  main()
{
    /*char c;
    cin>>mp[++n];
    while((getchar())!='\n')  cin>>mp[++n];*/
    while (cin >> mp[++n]); n--;	
    int len1=1,len2=1;
    d1[1]=mp[1],d2[1]=mp[1];
    for(int i=2;i<=n;i++)
    {
        if(d1[len1]>=mp[i]) d1[++len1]=mp[i];
        else
        {
            int p1=upper_bound(d1+1,d1+len1+1,mp[i],greater<int>())-d1;
            d1[p1]=mp[i];
        }
        if(d2[len2]<mp[i]) d2[++len2]=mp[i];
        else
        {
            int p2=lower_bound(d2+1,d2+len2+1,mp[i])-d2;
            d2[p2]=mp[i];
        }
    }
    cout<<len1<<endl<<len2;
    return 0;
}