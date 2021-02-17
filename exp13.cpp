#include<iostream>
#include<cstring>
#include<algorithm>
#define ull unsigned long long
using namespace std;
ull base=131;
int n,ans=0;
int h[10005];
string str[10005];

int hash1(string s)
{
    ull ss=0;
    for(int i=0;i<s.length();i++)
    {
        ss=ss*base+(ull)s[i];
    }
    return ss&0x7fffffff;
}
void func()
{
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        int hs=hash1(s);
        h[i]=hs;
    }
    sort(h,h+n);
}
int main()
{
    cin>>n;
    func();
    for(int i=1;i<=n;i++)
    if(h[i]!=h[i-1]) ans++;
    cout<<ans<<endl;
    return 0;
}