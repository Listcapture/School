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
int a[N],p[N];
bool vis[N];
void solve()
{
    int n;
    cin>>n;
    rep(i,1,n)cin>>a[i],p[a[i]]=i;
    rep(i,1,n) vis[i]=false;
    int ans=0;
    bool flag=false;
    rep(i,1,n)
    {
      if(vis[i])continue;
      vector<int >a;
      for(int j=i;!vis[j];j=p[j])
      {
        a.push_back(j);
        vis[j]=true;
      }
      sort(a.begin(),a.end());
      ans+=a.size()-1;
      rep(j,0,a.size()-1)
      {
        flag|=(a[j-1]+1==a[j]);
      }
    }
    cout<<ans+(flag?-1:1)<<endl;




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


