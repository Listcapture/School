
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


LL n,m;
const int N=1010;
int p[N],sz[N];
vector<int >poi;
LL find(LL x)
{
  if(p[x]!=x)return find(p[x]);
  return x;
}
map<int ,int >mp;
void solve()
{
   int n,k;
   cin>>n>>k;
   int id=0;
   for(id=0;id<=n;id++)
   {
    if(id*(id+1)>2*k) break;
   }
   id--;
   // id 个正数 n-id个minus
   //cout<<"id=="<<id<<endl;
   for(int i=1;i<=id;i++)
   {
    cout<<6<<" ";
   }
   int t=k-(id+1)*id/2;
   if(t==0) 
   {
    ;
   }else 
   {
   
     cout<<-6*(id-t)-1<<" "; 
     id++;
   }
   for(int i=id+1;i<=n;i++)
   {
    cout<<-1000<<" ";
   }
   cout<<endl;

  

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

