
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
#define l first
#define r second
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
const int N=110;
int f[N][N];
int Data[N][N];
vector<char>ans2;

void dfs(int cx,int cy)
{
  if(cx==1&&cy==1) return ;
  if(f[cx-1][cy]>f[cx-1][cy-1]&&cx>=2)
  {
    ans2.push_back('L');
    dfs(cx-1,cy);
  }else ans2.push_back('R'),dfs(cx-1,cy-1);
}
void Triangle_sum(int n)
{
  
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=i;j++)
    {
      f[i][j]=max(f[i-1][j],f[i-1][j-1])+Data[i][j];
    }
    
  }
  int mx=0,my=0,Max=0;
  for(int i=1;i<=n;i++)
  {
    if(f[n][i]>Max)
    {
      Max=f[n][i];
      mx=n,my=i;
    }
  }
  cout<<"MAX=="<<Max<<endl;
  dfs(mx,my);
  


}
// 7
// 3 8
// 8 1 0
// 2 7 4 4
// 4 5 2 6 5
void solve2()
{
   int n;
   cin>>n;
   rep(i,1,n)rep(j,1,i) cin>>Data[i][j];
   Triangle_sum(n);
   for(int i=ans2.size()-1;i>=0;i--)
   {
    cout<<ans2[i]<<" \n"[i==0];
   }

}
struct record
{
  int a;
  short b;
  char c;
}temp;
int main()
{
    int tt;
    tt=1;
    startTime = clock();
    while(tt--)
    {
        temp=273;
        cout<<temp<<endl;
        
        //printf("%.2lf",getCurrentTime());
    }
}

