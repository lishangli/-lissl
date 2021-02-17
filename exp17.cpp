#include<iostream>
using namespace std;
#define maxn 500005
int n,m;

int a[maxn],c[maxn];

int lowbit(int x)
{
    return x&(-x);
}

void update(int x,int y)
{
    while(x<=n)
    {
        c[x]+=y;
        x+=lowbit(x);
    }
}

int ssum(int x)
{
    int res=0;
    while(x>0)
    {
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        update(i,a[i]);
    }
    int p1,x,y;
    for(int i=1;i<=m;i++)
    {
        cin>>p1>>x>>y;
        switch(p1)
        {
            case 1:update(x,y);break;
            case 2:cout<<ssum(y)-ssum(x-1)<<endl;break;
            default:break;
        }
    }

}