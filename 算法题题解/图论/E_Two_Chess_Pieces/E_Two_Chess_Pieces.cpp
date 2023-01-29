#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=4e5+10;//用无向图表示一颗树数组要开两倍
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
#define lowbit(x) (x&-x)
const double eps=1e-8;
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
// 距离当前结点距离小于d的结点编号
/*
答案转化成所有必须经过的点的个数，固定一个棋子在树根然后将另一个棋子
移动，标记其所有必经的点，利用dfs的后更新前的特性。

*/
int e[N],h[N],ne[N],idx;
int dist[N],dm[N];
bool st[3][N];
int n,d;
void dfs(int u,int fa,int depth)
{
    dist[depth]=u;
    if(depth>d) dm[u]=dist[depth-d];
    else dm[u]=1;
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if(j==fa) continue;
        dfs(j,u,depth+1);
    }
}
void dfs2(int u,int fa,int piece)
{
     for(int i=h[u];~i;i=ne[i]) 
    {
        int j=e[i];
        if(j==fa) continue;
        dfs2(j,u,piece);
        st[piece][u]|=st[piece][j];
        //st数组放在dfs后面，先处理儿子，最后处理父亲
    }

}

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void solve()
{
   cin>>n>>d;
   rep(i,1,n) h[i]=-1;
   idx=0;
  
   rep(i,1,n-1)
   {
    int a,b;
    cin>>a>>b;
    add(a,b);
    add(b,a);
   }
   dfs(1,-1,0);
   int m1;
   cin>>m1;
   while(m1--)
   {
      int x;
      cin>>x;
      st[1][x]=st[2][dm[x]]=true;
   }
   int m2;
   cin>>m2;
   while(m2--)
   {
    int x;
    cin>>x;
    st[2][x]=st[1][dm[x]]=true;
   }
   int ans=0;
   dfs2(1,-1,1);
   dfs2(1,-1,2);
   rep(i,2,n)
   {
     if(st[1][i]) ans+=2;
     if(st[2][i]) ans+=2;

   }
    cout<<ans<<endl;

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


