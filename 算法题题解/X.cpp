#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
#define PLL pair<LL,LL>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
#define lowbit(x) (x&-x)
const double eps=1e-8;
bool cmp(PLL a,PLL b)
{
  return a.first<b.first;
}
clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
LL x,y,P;
const int M=330;

LL f[M][M],h[M][M];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
short dp(LL x,LL y)
{
    if(f[x][y]) return f[x][y];
    f[x][y]=-1;
    int tv=1;
    for(int i=0;i<4;i++)
    {
      int a=x+dx[i],b=y+dy[i];
      if(a>=1&&a<=n&&b>=1&&b<=m&&h[a][b]<h[x][y])
      {
        tv=max(tv,dp(a,b)+1);
      }
    }
    return f[x][y]=tv;
    
}

void solve()
{
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=n;i++)
   {
    for(int j=1;j<=m;j++)
    {
      cin>>h[i][j];
    }
   }
   int ans=0;
   for(int i=1;i<=n;i++)
   {
    for(int j=1;j<=m;j++)
    {
      ans=max(ans,dp(i,j));
    }
   }
   cout<<ans<<endl;
}

int main()
{
    int tt;
    cin>>tt>>P;
    startTime = clock();
    while(tt--)
    {
        solve();
        //printf("%.2lf",getCurrentTime());
    }
}
