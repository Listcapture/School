#include<bits/stdc++.h>
using namespace std;
#define LL long long 
#define PLL pair<LL,LL>
#define PII pair<int,int >
#define fir first
#define sec second
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
#define lowbit(x) (x&-x)
const double eps=1e-8;
clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
const int N=2e5+10;
LL x,y,n,m;
int e[N],ne[N],h[N],idx;
int col[N];
int st[N];
void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
bool  dfs(int u,int color)
{
   if(!col[u]) col[u]=color;
   for(int i=h[u];~i;i=ne[i])
   {
    int j=e[i];
    if(!col[j])
    {
        if(!dfs(j,3^col[u])) return false;
    }else if(col[j]==col[u]) return false;
   }
   return true;
}


void solve()
{
    while(cin>>x>>y>>n>>m)
   {

    rep(i,1,x) h[i]=-1,st[i]=0,col[i]=0; idx=0;
    while(y--)
    {
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    int t;
    bool can=true;
    rep(i,1,n) 
    {
        cin>>t;
        col[t]=1;
        if(!dfs(t,1)) can=false;
    }
    rep(i,1,m)
    {
        cin>>t;
        col[t]=2;
        if(!dfs(t,2)) can=false;
    }
    rep(i,1,x) 
    {
        if(h[i]==-1)continue;
        if(!col[i])
        {
            if(!dfs(i,1)) 
            {
                can=false;
                break;
            }
        }
    }
    rep(i,1,x) if(!col[i])can=false;
    cout<<((can)?"YES":"NO")<<endl;
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
    return 0;
}
