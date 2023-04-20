
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define PLL pair<LL, LL>
#define PII pair<int, int>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define dep(i, a, b) for (int i = a; i >= b; i--)
#define lowbit(x) (x & -x)
#define x first
#define y second
const double eps = 1e-8;
clock_t startTime;
#define l first
#define r second
double getCurrentTime()
{
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
const int N=2e5+10;
int a[N],pre[N];
bool cmp(int a,int b)
{
  return a<b;
}
void solve()
{
   int n;
   cin>>n;

   rep(i,1,n)cin>>a[i];
   sort(a+1,a+1+n,cmp);
   LL ans=0;
   rep(i,1,n)
   {
     ans+=(n-i+1)*a[i];
   }
   cout<<(double)ans/n<<endl;

  
}
int main()
{
  int tt;
  tt = 1;
  startTime = clock();
  while (tt--)
  {
    solve();
    // printf("%.2lf",getCurrentTime());
  }
}

