
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
const int N=220,M=1e4;
LL  f[N][M];
LL a[N],v[N],w[N];
LL n,k;
int  get(LL x,LL s)
{
	LL res=0;
	if(s==0)
	{
		while(x%2==0) x/=2,res++;
	}
	if(s==1)
	{
		while(x%5==0) x/=5,res++;
	}
	return  res;
}
// 当开maxn行或2行的数组时，j的枚举顺序无关紧要，因为同一行的结果不会互相冲突，但在只有1行的情况下，
// j的枚举顺序就变得至关重要，因为被强行压掉了一维，转移方程变为dp[j]=dp[j-1]+1，每一行的结果一算出来，
// 就会被下一行覆盖。如果正序枚举j，dp[j]还没算出来，dp[j-1]就会被覆盖，得不到正确的dp[j]，因此，我们需
// 要逆序枚举j。
// 换句话说，如果你对状态进行了压缩，那么你的枚举顺序就必须进行逆转。
void solve()
{
   cin>>n>>k;
   for(int i=1;i<=n;i++)
   {
	cin>>a[i];
	v[i]=get(a[i],1);
	w[i]=get(a[i],0);
   }
    memset(f,~0x3f,sizeof(f));
   f[0][0]=0;
   for(int i=1;i<=n;i++)
   {
	for(int j=k;j>=1;j--)
	{
		for(int x=M-1;x>=v[i];x--)
		{
			f[j][x]=max(f[j][x],f[j-1][x-v[i]]+w[i]);
		}
		
	}
   }
   LL ans=0;
   for(LL x=M-1;x>=0;x--)
   {
		ans=max(ans,min(f[k][x],x));
   }
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