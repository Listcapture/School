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
const int N=3e4+10;
int n,m;
LL a[N],tr1[N],tr2[N];
PLL p[N];
LL my=0,mx=0;
int ans[N];

void add(LL x,LL d,int status)
{
  if(status==0) while(x<=mx+1) tr1[x]+=d,x+=lowbit(x);
  else while(x<=my) tr2[x]+=d,x+=lowbit(x);
}
LL query(LL r,int status)
{

   LL res=0;
   if(status==0){ while(r) res+=tr1[r],r-=lowbit(r);}
   else    {while(r) res+=tr2[r],r-=lowbit(r); }

   return res;
}
bool cmp(PLL a,PLL b)
{
    if(a.fir!=b.fir) return a.fir<b.fir;
    return a.sec<b.sec;
}
void solve()
{
   scanf("%d",&n);
   my=0;
   rep(i,1,n)
   {
      scanf("%lld%lld",&p[i].fir,&p[i].sec);
      p[i].fir=p[i].fir+1,p[i].sec=p[i].sec+1;
      my=max(my,p[i].sec);
   }
  // cout<<mx<<" "<<my<<endl;
   sort(p+1,p+1+n,cmp);
   rep(i,1,n)
   {
     ans[query(p[i].sec,1)]++;
     add(p[i].sec,1,1);
   }
   rep(i,0,n-1) printf("%lld\n",ans[i]);
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
