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
const int mod=1e9+7;
LL qp(LL a,LL b,LL c)
{
    LL ans=1;
    for(;b;b>>=1)
    {
        if(b&1)
        {
            ans=(ans*a)%c;
        }
        a=(a*a)%c;
    }
    return ans%c;
}
LL get(LL n)
{
    return n*(n+1)%mod*(2*n+1)%mod*qp(6,mod-2,mod);
}
void solve()
{
int n;
cin>>n;
int t=n/2;
cout<<(get(n)%mod+get(n/2)%mod+t*(t+1)/2)%mod<<endl;


}

int main()
{
    int tt;
    cin>>tt;
    startTime = clock();
    while(tt--)
    {
        solve();
        

        //printf("%.2lf",getCurrentTime());
    }
}


