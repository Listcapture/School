//求区间最大
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10,M=26;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
#define lowbit(x) (x&-x)
const double eps=1e-8;
int n,m;
int f[N][M],a[N],b[N];

void init()
{
  rep(i,1,n)
  rep(j,0,M-1)
  f[i][j]=0;
  rep(i,1,n) f[i][0]=b[i];
  rep(j,1,M-1)
  {
    rep(i,1,n+1-(1<<j))
    {
      f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    }
  }
}
int query(int l,int r)
{
  int len=(r-l+1);
  int k=log(len)/log(2);
  return max(f[l][k],f[r-(1<<k)+1][k]);
}
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
       init();
    }
}


