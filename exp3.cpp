#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

typedef struct
{
    int index,score;
}pp;

bool cmp(pp a,pp b)
{
    if(a.score>b.score) return true;
    else if(a.score==b.score)
        {
            if(a.index<b.index) return true;
            else return false;
        } 
    else return false;
        
        
}
int main()
{
    int n,m;
    cin>>n>>m;
    pp *a=new pp[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].index>>a[i].score;
    }
    sort(a,a+n,cmp);
    int k=floor(m*1.5);
    while(a[k-1].score==a[k].score) k++;
    cout<<a[k-1].score<<' '<<k<<endl;
    for(int i=0;i<k;i++)
    cout<<a[i].index<<' '<<a[i].score<<endl;
    return 0;
}