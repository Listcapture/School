#include<bits/stdc++.h>
using namespace std;
#define PDD pair<double,double>
#define x first
#define y second
/*
andrew算法
1.将所有点按照x升序，y升序排序
2.用一个栈维护凸包，判重数组标记所有在栈中的点
3.从1-n枚举点，求解上凸包
4.把第一个点标记为未使用，求解下凸包。

*/
const int N=1e4+10;
PDD p[N];
bool used[N];
int n;
PDD operator -(PDD a,PDD b)
{
  b.x-=a.x,b.y-=a.y;
  return b;
}
double get_dist(PDD a,PDD b)
{
  double dx=a.x-b.x;
  double dy=a.y-b.y;
  return  sqrt(dx*dx+dy*dy);
}
double cross(PDD a,PDD b)
{
  return a.x*b.y-a.y*b.x;
}
int stk[N],top;

double judge(PDD a,PDD b,PDD c)
{
  return cross(b-a,c-a);
}

int main()
{
  cin>>n;
  for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
  sort(p+1,p+1+n);
  for(int i=1;i<=n;i++)
  {
    while(top>=2&&judge(p[stk[top-1]],p[stk[top]],p[i])<=0)
    used[stk[top--]]=false;
 
    stk[++top]=i;
    used[i]=true;
  }
  used[1]=false;
  for(int i=n;i>=1;i--)
  {
    if(used[i]) continue;
    while(top>=2&&judge(p[stk[top-1]],p[stk[top]],p[i])<=0)
    used[stk[top--]]=false;
    stk[++top]=i;
    used[i]=true;
  }
  double ans=0;
  for(int i=2;i<=top;i++)
  {
    ans+=get_dist(p[stk[i]],p[stk[i-1]]);
  }
  
  printf("%.2lf",ans);
  
  
  return 0;
}