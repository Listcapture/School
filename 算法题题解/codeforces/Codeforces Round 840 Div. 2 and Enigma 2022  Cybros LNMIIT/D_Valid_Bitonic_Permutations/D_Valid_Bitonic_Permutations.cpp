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
/*
dp[i][j]表示【i，j】中包含n的双调队列方案数，初始化，fi，i chek（i，n）
1.为什么这样定义，因为包含n的双调队列是一个长度为len=j-i+1的[n-len+1,n-]的排列，
假设我们要使得这个排列扩充，只需要判断n-len能否加在队列某一端即可
2.如何判断，只要bi！=x，bj！=y就可以。
dp[i-1][j]+=dp[i][j],i按降序排列
dp[i][j+1]+=dp[i][j];j按升序排列
注意dp【1，1】=dp[n][n]=0;
*/
void solve()
{
  
  int n,i,j,x,y;
  cin>>n>>i>>j>>x>>y;
  auto check=[&](int pos ,int val){
     if(pos==i) return val==x;
     else if(pos==j) return val==y;  
     return true;
  };
  const int mod=1e9+7;
  vector<vector<int> >dp(n+2,vector<int>(n+2,0));
  rep(i,2,n-1) dp[i][i]=check(i,n);
  dep(i,n,1)
  rep(j,i,n)
  {
      int val=n-(j-i+1);
      if(check(i-1,val))
      {
        dp[i-1][j]+=dp[i][j];
        dp[i-1][j]%=mod;
      }
      if(check(j+1,val))
      {
        dp[i][j+1]+=dp[i][j];
        dp[i][j+1]%=mod;
      }
  }
   cout<<dp[1][n]<<endl;
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


