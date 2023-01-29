#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
#define lowbit(x) (x&-x)
const double eps=1e-8;
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
LL qp(LL a,LL b,LL p)
{  
    LL ans=1;
    for(;b;b>>=1)
    {
        if(b&1)
        {
            ans=(ans*a)%p;
        }
        a=(a*a)%p;
        
    }
    return ans%p;
}
LL n,p;
vector<LL >fac,invfac;

LL C(int a,int b)
{
    return fac[a]*invfac[a-b]%p*invfac[b]%p;
}


void solve()
{
 
   cin>>n>>p;
  fac.resize(4*n),invfac.resize(3*n+1);
    fac[0]=1;
  invfac[0]=1;
   rep(i,1,3*n)
   {
    fac[i]=fac[i-1]*i%p;
   }
   invfac[3*n]=qp(fac[3*n],p-2,p);
   dep(i,3*n-1,1)
   {
    invfac[i]=invfac[i+1]*(i+1)%p;
   }

   LL t0=1;
   LL t1=(2*fac[2*n]-fac[n])%p-t0;
   t1%=p;
   LL t2=2*C(2*n,n)%p*fac[2*n]%p*fac[n]%p;
   t2%=p;
   rep(i,0,n)
   {
     t2-=C(n,i)*C(n,n-i)%p*fac[n]%p*C(2*n-i,n)%p*fac[n]%p*fac[n]%p;
     t2%=p;   
   }
   t2-=t1+t0;
   t2%=p;
   LL t3=fac[3*n]-t0-t1-t2;
   t3%=p;
   LL ans=2*t2%p+3*t3%p+t1%p;
   ans%=p;
   cout<<(ans%p+p)%p<<endl;


}

int main()
{
  

  solve();
}


