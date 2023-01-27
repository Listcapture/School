#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
#define PDD pair<double,double >
#define x first
#define y second
PDD operator-(PDD a,PDD b)
{
  return make_pair(a.x-b.x,a.y-b.y);
}
double cross(PDD a,PDD b)
{
  return a.x*b.y-a.y*b.x;
}
double jud(PDD a,PDD b,PDD c)
{
  return cross(b-a,c-a);
}
PDD s[N];
int n,m,x1,y1,x2,y2;
bool check(int mid,PDD t)
{
  PDD u=p[mid].t-p[mid].s,v=t-p[mid].s;
  return cross(u,v)>=0;
}
struct v{
  PDD s,t;
}p[N];
int main()
{

  while(cin>>n>>m>>x1>>y1>>x2>>y2)
  {
    vector<int>cnt(n+2);
    int a,b;
    int tot=0;
   for(int i=1;i<=n;i++)
   {
        cin>>a>>b;
        s[i]=make_pair(b,y2);
        PDD ta=make_pair(a,y1),tb=make_pair(b,y2);
        p[i].s=tb,p[i].t=ta;
   }
     
 
    while(m--)
    {
      double x,y;
      cin>>x>>y;
      PDD t=make_pair(x,y);
      int l=1,r=n+1;
      while(l<r)
      {
        int mid=(l+r+1)>>1;
        if(check(mid,t)) l=mid;
        else r=mid-1;
      }
      cnt[l-1]++;

    }

     for(int i=0;i<n;i++)
  {
    cout<<i<<": "<<cnt[i]<<endl;
  }
  }
  return 0;
}