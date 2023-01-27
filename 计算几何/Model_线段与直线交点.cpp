#include<bits/stdc++.h>
using namespace std;
const int N=220;
#define PDD pair<double,double>
#define x first
#define y second
struct edge
{
    PDD a,b;
}e[N];
PDD p[N];
//注意直线方向向量不能是零向量
PDD operator-(PDD a,PDD b)
{
    return make_pair(a.x-b.x,a.y-b.y);
}
double cross(PDD a,PDD b)
{
    return a.x*b.y-a.y*b.x;
}
double area(PDD a,PDD b,PDD c)
{
    return cross(b-a,c-a);
}
int sign(double x)
{
  if(fabs(x)<=1e-8) return 0;
  else if(x<0) return -1;
  else return 1;
}
bool jud(PDD x,PDD y,edge v)
{
   return sign(area(x,y,v.a))*sign(area(x,y,v.b))<=0;
}
int cnt;
int n;
void solve()
{
    for(int i=1;i<=cnt;i++)
    {
        for(int j=i+1;j<=cnt;j++)
        {
            bool can=true;
            if(fabs(p[i].x-p[j].x)<=1e-8)continue;
            for(int k=1;k<=n;k++)
            {
                if(!jud(p[i],p[j],e[k]))
                {
                  can=false;
                  break;
                }
            }
            if(can) 
            {
                puts("Yes!");
                return ;
            }
        }
    }
    puts("No!");


}
int main()
{
   int tt;
   scanf("%d",&tt);
   while(tt--)
   {
     scanf("%d",&n);
     cnt=0;
     for(int i=1;i<=n;i++)
     {
       scanf("%lf%lf%lf%lf",&e[i].a.x,&e[i].a.y,&e[i].b.x,&e[i].b.y);
       p[++cnt]=e[i].a;
       p[++cnt]=e[i].b;
     }
     solve();

   }
    return 0;
}