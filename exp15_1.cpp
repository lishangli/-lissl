#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int mp[100005];
int d1[100005],d2[100005];
int main()
{
    n=1;
    while(cin>>mp[n]) n++;
    n--;
    for(int i=1;i<=n;i++)
    {
        d1[i]=1;
        d2[i]=1;
    }
    for(int i=2;i<=n;i++)
    {
        //d1[i]=1;
        for(int j=1;j<i;j++)
        {
            //d1[j]=1,d2[j]=1;
            if(mp[i]>mp[j]&&d1[i]<d1[j]+1)
            d1[i]=d1[j]+1;
            if(mp[i]<=mp[j]&&d2[i]<d2[j]+1)
            d2[i]=d2[j]+1;
        }
    }
    //cout<<d1[n]<<endl<<d2[n];
    int s1=0,s2=0;
    for(int i=1;i<=n;i++)
    {
        //cout<<mp[i]<<' ';
        s1=max(s1,d1[i]);
        s2=max(s2,d2[i]);
    }
    //cout<<n<<endl;
    cout<<s2<<endl<<s1;
    return 0;
}