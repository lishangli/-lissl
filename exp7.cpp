#include<iostream>
#include<cstring>
#include<cstdio>
//#include<string>
using namespace std;
int n;
string str[25];
int ss[25][25];
int vis[25];
int ansl=0;
void mt()
{
    for(int i=0;i<n;i++)
    {
        int len=str[i].length(); 
        for(int j=0;j<n;j++)
        {
               int len1=str[j].length();
                int p,q,k;
                for(k=len-1;k>=0;k--)
                {
                    p=0;
                    q=k;
                    while(str[i][q]==str[j][p]&&q<len&&p<len1) {q++;p++;}
                    if(q==len&&str[i][q-1]==str[j][p-1]) break;
                }
                if(p==len1||(q-k)==len||q<len) ss[i][j]=0;
                else ss[i][j]=p;
        }
    }
}
void dfs(int x,int ans)
{
    for(int i=0;i<n;i++)
    {
        if(ss[x][i]>0&&vis[i]<2) {vis[i]++;dfs(i,ans+str[i].length()-ss[x][i]);vis[i]--;}
    }
    if(ansl<ans) ansl=ans;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>str[i];
    char c;
    cin>>c;
    mt();
    for(int i=0;i<n;i++)
    {
        if(str[i][0]==c)
        {
            vis[i]++;
            dfs(i,str[i].length());
            vis[i]--;
        }
    }
    printf("%d",ansl);
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<ss[i][j];
        cout<<endl;
    }*/
    return 0;
}