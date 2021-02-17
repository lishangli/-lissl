#include<iostream>
using namespace std;
#define maxn 500005
#define ll long long
typedef struct
{
    int l,r;
    ll sums,lz;
}node;
node a[maxn];
ll c[maxn];
int n,m;
void build(int i,int l,int r)
{
    a[i].l=l,a[i].r=r;
    if(l==r) {
        a[i].sums=c[l];
        return ;}
    int mid=(l+r)>>1;
    build(2*i,l,mid);
    build(2*i+1,mid+1,r);
    a[i].sums=a[i*2].sums+a[i*2+1].sums; 
}

void pushdown(int x)
{
    if(a[x].lz!=0)
    {
        a[2*x].lz+=a[x].lz;
        a[2*x+1].lz+=a[x].lz;
        int mid=(a[x].r+a[x].l)>>1;
        a[2*x].sums+=a[x].lz*(mid-a[2*x].l+1);
        a[2*x+1].sums+=a[x].lz*(a[2*x+1].r-mid);
        a[x].lz=0;
    }
    return ;
}
void update(int i,ll k,int l,int r)
{
    if(l<=a[i].l&&a[i].r<=r)
    {
        a[i].sums+=k*(a[i].r-a[i].l+1);
        a[i].lz+=k;
        return ;
    }
    pushdown(i);
    if(a[2*i].r>=l) update(2*i,k,l,r);
    if(a[2*i+1].l<=r) update(2*i+1,k,l,r);
    a[i].sums=a[2*i].sums+a[2*i+1].sums;
    return ;
}

ll getsum(int i,int l,int r)
{
    if(a[i].l>=l&&a[i].r<=r)
    {
        return a[i].sums;
    }
    ll res=0;
    pushdown(i);
    if(a[2*i].r>=l) res+=getsum(2*i,l,r);
    if(a[2*i+1].l<=r) res+=getsum(2*i+1,l,r);
    return res;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    build(1,1,n);
    int p1,x,y; ll k;
    for(int i=1;i<=m;i++)
    {
        cin>>p1;
        switch(p1)
        {
            case 1:cin>>x>>y>>k;update(1,k,x,y);break;
            case 2:cin>>x>>y;cout<<getsum(1,x,y)<<endl;break;
            default:break;
        }
    }
    return 0;
}