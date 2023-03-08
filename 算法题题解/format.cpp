
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
const int N=1010;
LL n;
LL a[N][N];
LL f[N][N][2];
LL cnt[N][N][2];
vector<char >zpath;
vector<char>path;
LL get(LL x,LL s)
{
  LL res=0;
  if(x==0)return 0;
  if(s==0)
  {
    while(x%2==0) x/=2,res++;
  }else while(x%5==0) x/=5,res++;
  return res;
}
void finz(int zx,int zy)
{
  // 从1，1 出发经过zx,zy, zx,zy n,n
  int cx=1,cy=1;
  while(cx<zx) zpath.push_back('D'),cx++;
  while(cy<zy) zpath.push_back('R'),cy++;
  while(cx<n) zpath.push_back('D'),cx++;
  while(cy<n) zpath.push_back('R'),cy++;
}
bool ok(int a,int b)
{
  return (a>=1&&a<=n&&b>=1&&b<=n);
}
void back(int s)
{
    int cx=n,cy=n;
    while(1){
     //cout<<cx<<" "<<cy<<endl;
      int a=cx-1,b=cy;
      int la=cx,lb=cy-1;
      if(!ok(a,b)&&!ok(la,lb))
      {
        break;
      }else if(!ok(a,b))
      {
        path.push_back('R');
        cx=la,cy=lb;
      }else if(!ok(la,lb))path.push_back('D'),cx=a,cy=b;
      else 
      {
        if(f[a][b][s]<=f[la][lb][s])
        {
          path.push_back('D');
          cx=a,cy=b;
        }else 
        {
          path.push_back('R');
          cx=la,cy=lb;
        }


      }
    }

}



void solve()
{
  cin>>n;
  LL ans=0;
  bool zero=false;
  int zx,zy;
  rep(i,1,n) rep(j,1,n)
  {
    cin>>a[i][j];
    if(!a[i][j])zero=true,zx=i,zy=j;
    cnt[i][j][0]=get(a[i][j],0);
    cnt[i][j][1]=get(a[i][j],1);
    f[i][j][0]=f[i][j][1]=2e18;
  }
  
  // dp
  for(int i=1;i<=n;i++)
  {
    f[i][0][0]=f[i][0][1]=0x3f3f3f3f;
    f[0][i][0]=f[0][i][1]=0x3f3f3f3f;
  }
  f[0][1][0]=f[0][1][1]=0;
  f[1][0][0]=f[1][0][1]=0;
  rep(i,1,n)
  rep(j,1,n)
  {
    f[i][j][0]=min(f[i-1][j][0],f[i][j-1][0])+cnt[i][j][0];
    f[i][j][1]=min(f[i-1][j][1],f[i][j-1][1])+cnt[i][j][1];
  }
  ans=min(f[n][n][0],f[n][n][1]);
  int s;
  if(f[n][n][0]<=f[n][n][1]) s=0;
  else s=1;
  if(ans>1&&zero){
    finz(zx,zy);
    cout<<1<<endl;
    for(int i=0;i<zpath.size();i++)
    {
      cout<<zpath[i];
    }
   
  }else 
  {
    cout<<ans<<endl;
    back(s);
    reverse(path.begin(),path.end());
    for(int i=0;i<path.size();i++) cout<<path[i];
    
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
}