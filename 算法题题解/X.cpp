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
int primes[N],cnt;
bool st[N];
void init()
{
    for(int i=2;i<N;i++)
    {
        if(!st[i]) primes[cnt++]=i;
        for(int j=0;primes[j]*i<N;j++)
        {
            st[primes[j]*i]=true;
            if(i%primes[j]==0) break;
        }
    }
}

void solve()
{
    
    
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