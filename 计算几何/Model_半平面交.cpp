#include<bits/stdc++.h>
using namespace std;
#define PDD pair<double ,double>
#define x first
#define y second
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
const int N=220;
const double eps=1e-8;
int sign(double x)
{
    if(fabs(x)<eps) return 0;
    else (x<0) return -1;
    else return 1;

}

int dmp(double x,double y)
{
    if(fabs(x-y)<eps) return 0;
    else if(x<y) return -1;
    else return 1;
}
double cross(PDD a,PDD b)
{
    return a.x*b.y-a.y*b.x;
}
double area(PDD a,PDD b,PDD c)
{
    return cross(b-a,c-a);
}
double dot(PDD a,PDD b)
{
    return a.x*b.x+a.y*b.y
}
double get_len(PDD a)
{
    return sqrt(dot(a,a));
}
bool cmp(line a,line b)
{
    double A=get_ang(a),B=get_ang(b);
    if(!dmp(A,B)) return area(a.st,a.ed,b.ed)<0;
    else return A<B;
}
struct l
{
    PDD st,ed;
}line[N];

PDD p[N];
int m,cnt;
//求直线交点
PDD get_intersec
int main()
{
   int n;
   cin>>n;
   while(n--)
   {
    int cnt=0;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
      cin>>p[i].x>>p[i].y;
    }
    for(int i=1;i<=m;i++)
    {
        line[i].st=p[i];
        line[i].ed=p[(i+1)%m];
    }
    double ans=hpl();
    printf("%.3lf\n",ans);
   }






    return 0;
}