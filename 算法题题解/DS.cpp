
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
const int N=1e4+10,MM=1e6+10;
struct query
{
  int id,l,r,t;
}q[N];
struct modify
{
  int p,col;
}M[N];
int cnt[MM];
int a[N],ans[N];
LL n,m,len;
int cm,cq;
int  get(int x)
{
  return x/len;
}
void add(int a,int b,int c)
{
  e[idx]=b,ne[idx]=h[a],h[a]=idx++;
  memset(h,-1,sizeof h);
  vector<int>fac;
  for(int i=0;i<fac.size();i++)
  {
    cout<<fac[i]<<" \n"[i==fac.size()-1];
    
  }
}
bool cmp(query a,query b)
{
  int blockal=get(a.l),blockbl=get(b.l);
  int blockar=get(a.r),blockbr=get(b.r);
  if(blockal!=blockbl) return blockal<blockbl;
  if(blockar!=blockbr) return blockar<blockbr;
  return a.t<b.t;
}
void add(int x,int &res)
{
  if(!cnt[x]) res++;
  cnt[x]++;
}
void del(int x,int &res)
{
  cnt[x]--;
  if(!cnt[x]) res--;
}
int main()
{
  cin>>n>>m;
  rep(i,1,n)cin>>a[i];
  for(int i=1;i<=m;i++)
  {
    string op;
    int l,r;
    cin>>op>>l>>r;
    if(op=="Q")
    {
      q[++cq]={cq,l,r,cm};
    }else M[++cm]={l,r};
  }
  
  len=cbrt((double)n*cm)+1;sort(q+1,q+1+cq,cmp);
  //cout<<len<<endl;
  int tl=1,tr=0,tim=0;
  int res=0;
  rep(i,1,cq)
  {
    int id=q[i].id,l=q[i].l,r=q[i].r,t=q[i].t;
    while(tl<l) del(a[tl++],res);
    while(tl>l) add(a[--tl],res);
    while(tr>r) del(a[tr--],res);
    while(tr<r) add(a[++tr],res);
    while(tim<t)
    {
      tim++;// 加操作的特性
      del(a[M[tim].p],res);
      add(M[tim].col,res);
      swap(a[M[tim].p],M[tim].col);
    }
    while(tim>t)
    {
      del(a[M[tim].p],res);
      add(M[tim].col,res);
      swap(a[M[tim].p],M[tim].col);
      tim--;
    }
    ans[id]=res;
  }
  rep(i,1,cq) cout<<ans[i]<<endl;
  
    

}