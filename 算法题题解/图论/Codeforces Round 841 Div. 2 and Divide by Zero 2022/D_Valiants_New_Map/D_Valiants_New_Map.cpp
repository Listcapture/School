#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e6+10;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define dep(i,a,b) for(int i=(a);i>=(b);i--)
#define lowbit(x) (x&-x)
const double eps=1e-8;
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void solve()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>  >g(n+1,vector<int>(m+1,0));
  rep(i,1,n)
  rep(j,1,m)
  {
    cin>>g[i][j];
  }
  int l=1,r=n;
  while(l<r)
  {
    int mid=(l+r+1)>>1;
    bool flag=false;
   
    vector<vector<int> >s(n+1,vector<int>(m+1,0));
    rep(i,1,n)
    {
        rep(j,1,m)
        {
          s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(g[i][j]>=mid);
        }
    }
    rep(i,1,n-mid+1)
    {
        rep(j,1,m-mid+1)
        {
            int a=i,b=j,c=i+mid-1,d=j+mid-1;
            if((s[c][d]-s[c][b-1]-s[a-1][d]+s[a-1][b-1])==mid*mid)
          {
            flag=true;
          }
        }
    }


     if(flag)l=mid;
     else r=mid-1;
  }
  cout<<l<<endl;



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


