
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define PLL pair<LL,LL>
#define PII pair<int,int>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
#define lowbit(x) (x&-x)
#define x first
#define y second
const double eps=1e-8;
clock_t startTime;

double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

// 判断连通块是否能阻止
const int N=2e5+10;
LL n,t;
LL p[N];
struct gs
{
       LL k,c;
}g[N];
bool cmp(gs a,gs b)
{
    return a.c<b.c;
}
void solve()
{
  cin>>n;
  rep(i,1,n)cin>>g[i].k>>g[i].c;
  cin>>t;
  rep(i,1,t)cin>>p[i];
  sort(g+1,g+1+n,cmp);
  LL f=1;
  LL res=0;
  LL sum=0;
  rep(i,1,n)
  {
    int cnt=g[i].k,w=g[i].c;
    // 没有买之前
    int pos=lower_bound(p+1,p+1+t,sum)-p;
    cout<<pos<<endl;
    sum+=cnt;

  }
  //cout<<res<<endl;
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