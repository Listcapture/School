#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define PII pair<int,int>
#define PDD pair<double,double>
#define PLL pair<LL,LL>
const int N=2e5+10;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
#define lowbit(x) (x&-x)
const double eps=1e-8;
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

int a[N],p[N],q[N];
vector<int >pos[N];
void solve()
{
  int n;
  cin>>n;
  rep(i,1,n) pos[i].clear();
  rep(i,1,n)cin>>a[i],pos[a[i]].push_back(i);
  vector<int >cand0,cand1;
  dep(i,n,1)
  {
    if(pos[i].size()>2) 
    {
      puts("NO");
      return ;
    }
    if(pos[i].size()==0)
    {
      if(!cand0.size()||!cand1.size())
      {
        puts("NO");
        return ;
      }
      p[cand0.back()]=i,cand0.pop_back();
      q[cand1.back()]=i,cand1.pop_back();
      
    }else if(pos[i].size()==1)
    {
      p[pos[i][0]]=i,cand1.push_back(pos[i][0]);
      q[cand1.back()]=i,cand1.pop_back();
    }else 
    {
      p[pos[i][0]]=i,q[pos[i][1]]=i;
      cand1.push_back(pos[i][0]),cand0.push_back(pos[i][1]);
    }
  }
   puts("YES");
   rep(i,1,n)
   {
    cout<<p[i]<<" \n"[i==n];
   }
   rep(i,1,n)
   {
    cout<<q[i]<<" \n"[i==n];
   }
  
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
