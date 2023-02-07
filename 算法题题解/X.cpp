#include<bits/stdc++.h>
using namespace std;
#define LL long long 
#define PLL pair<LL,LL>
#define PII pair<int,int >
#define fir first
#define sec second
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
#define lowbit(x) (x&-x)
const double eps=1e-8;
clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
const int N=1e6+10;
int n,m;
LL mx,my;
LL tr1[N],tr2[N];
LL a[N];
PLL p[N];
LL ans[N];
bool cmp(PLL a,PLL b)
{
  if(a.fir!=b.fir) return a.fir<b.fir;
  return a.sec<b.sec;
}
void add(LL x,LL d,int status)
{
   while(x<=mx) tr1[x]+=d,x+=lowbit(x);
}
LL query(LL r,int status)
{

  LL res=0;
  while(r) res+=tr1[r],r-=lowbit(r);
  return res;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]++,mx=max(mx,a[i]);
    for(int i=1;i<=n;i++)
    { 
      ans[i]+=query(a[i],0);
      add(1,1,0),add(a[i],-1,0);
    }
    rep(i,1,mx) tr1[i]=0;
    for(int i=n;i>=1;i--)
    {
       ans[i]+=query(a[i],0);
       add(a[i]+1,1,0);
    }
    LL res=0;
    rep(i,1,n)
    {
      
      res+=ans[i]*(ans[i]+1);
    }
    cout<<res/2<<endl;
    
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
    return 0;
}
