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
const int N=2e5+10;
LL n;



void solve()
{
    cin>>n;
    LL k=sqrt(n);
    rep(a,0,k)
    {
      LL s1=a*a;
      rep(b,0,k)
      {
        LL s2=s1+b*b;
        rep(c,0,k)
        {
          LL s3=s2+c*c;
          rep(d,k,0)
          {
            LL s4=s3+d*d;
            if(s4==n)
            {
              cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
              return ;
            }
          }
        }
      }
    }
    
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
