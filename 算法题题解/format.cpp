#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define lowbit(x) (x&-x)
#define x first
#define y second
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
const int N=2e5+10;
clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
int v[N],w[N];
int f[N];
void solve()
{
int n,m;
cin>>m>>n;
for(int i=1;i<=n;i++)
{
    cin>>w[i]>>v[i];
}
memset(f,0x3f,sizeof (f));
f[m]=0;// f[j]表示使当前人数变为j的最小花费
for(int j=m;j>=1;j--)
{
    for(int i=1;i<=n;i++)
    {
        if(v[i]<=j)  f[j-j%v[i]]=min(f[j-j%v[i]],f[j]+w[i]);
    }
}
    for(int i=1;i<=m;i++)
    {
        if(f[i]!=f[0])
        {
            cout<<f[i]<<endl;
            return ;
        }
    }

}

int main()
{
    int tt;
    tt=1;
    startTime = clock();
    while(tt--)
    {
        solve();
        

        //printf("%.2lf",getCurrentTime());
    }
}