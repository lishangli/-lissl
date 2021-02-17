#include<iostream>
#include<algorithm>
using namespace std;

int n;
int main()
{
    int n;
    cin>>n;
    int d[1005]={0};
    for(int i=0;i<n;i++)
    {
        int j;
        cin>>j;
        d[j]++;
    }
    int *a=new int[n];
    int k=0;
    for(int i=1;i<=1000;i++)
    {
        if(d[i]>0) a[k++]=i;
    }
    cout<<k<<endl;
    for(int i=0;i<k;i++)
    {
        cout<<a[i]<<' ';
    }
    return 0;
}