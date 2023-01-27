#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=3e6+10;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define dep(i,a,b) for(int i=(a);i>=(b);i--)
#define lowbit(x) (x&-x)
const double eps=1e-8;
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
int phi[N],primes[N],cnt,cop[N];
bool st[N];

void init(int N)
{
    phi[1]=1;
    rep(i,2,N/2)
    {
    if(!st[i]) primes[cnt++]=i,phi[i]=i-1;
    for(int j=0;primes[j]*i<N/2;j++)
    {
       st[primes[j]*i]=true;
       if(i%primes[j]==0)
       {
         phi[i*primes[j]]=phi[i]*primes[j];
         break;
       }else phi[i*primes[j]]=phi[i]*(primes[j]-1);
    }
    }
    rep(i,1,N/2)
    {
        phi[i]+=phi[i-1];
        cop[i]=phi[i]-1;
    }

}
void solve()
{
   int n;
   LL m;
   cin>>n>>m;
   LL ans=0;
   for(LL k=n;k>=2;k--)
   {
 
    LL can=cop[n/k];
    LL ave=min(can/(k-1),m/(k-1));
    ans+=ave*k;
    m-=ave*(k-1);
   }
   if(m) cout<<-1<<endl;
   else cout<<ans<<endl;
   

  
  



}

int main()
{
    int tt;
    cin>>tt; 
     init(N);
    startTime = clock();
    while(tt--)
    {
      
        solve();
        

        //printf("%.2lf",getCurrentTime());
    }
}


