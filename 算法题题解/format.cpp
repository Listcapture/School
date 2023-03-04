#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#pragma GCC optimize(2)
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
const int N=4e5+10;
LL n;
const int P=998244353;
LL p[N],q[N];
LL pos[N],qos[N];
LL calc(int a)
{
    return (LL)a*(a+1)/2;
}
int insect(int a,int b,int c,int d)
{
    return max(min(b,d)-max(a,c)+1,0);
}
void solve()
{
   cin>>n;
   rep(i,1,n)cin>>p[i],pos[p[i]]=i;
   rep(i,1,n)cin>>q[i],qos[q[i]]=i;
   LL ans=0;
   LL plx=n,prx=1,qlx=n,qrx=1;
   LL minp=1,maxp=n;
   LL minq=1,maxq=n;
   for(int mex=1;mex<=n-1;mex++)
   {
    //  plx ,prx   -- qlx, qrx
    // plx,prx pos[mex] qlx ,qrx,qos[mex];
      plx=min(plx,pos[mex]),prx=max(prx,pos[mex]);
      qlx=min(qlx,qos[mex]),qrx=max(qrx,qos[mex]);
      LL minp,maxp,minq,maxq;
      if(pos[mex+1]>prx) minp=1,maxp=pos[mex+1]-1;
      else minp=pos[mex+1]+1,maxp=n;
      if(qos[mex+1]>qrx) minq=1,maxq=qos[mex+1]-1;
      else minq=qos[mex+1]+1,maxq=n;
      ans+=max(min(plx,qlx)-max(minp,minq)+1,0LL)*max(min(maxp,maxq)-max(prx,qrx)+1,0LL);
      
   }
   // 特判1
   //cout<<ans<<endl;
   LL k1=pos[1],k2=qos[1];
   // 1,k1-1 k1+1, n
   // 1,k2-1,k2+1,n
   int ll=min(k1-1,k2-1),rr=min(n-k1,n-k2);
   if(k1!=k2) ans+=calc(abs(k1-k2)-1);
   ans+=calc(ll)+calc(rr);
   // 特判n+1
   ans++;
   cout<<ans<<endl;
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