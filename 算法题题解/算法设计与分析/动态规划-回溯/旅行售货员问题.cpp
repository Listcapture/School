#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define PII pair<int,int>
const int N = 5050;
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define dep(i, a, b) for (int i = a; i >= b; i--)
#define lowbit(x) (x & -x)
const double eps = 1e-8;
clock_t startTime;
double getCurrentTime()
{
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
int dist[N];
int f[N][N];
int st[N];
int d[N][N];
int pre[N][N];
int n,m;
vector<int>res;
void dfs(int x,int y)
{
    if(pre[x][y]==x) return ;
    int t=pre[x][y];
    if(t) res.push_back(t);
    dfs(t,y);
    return ;
}

void solve()
{
    int n;
    int fina;
   
    cin>>n; cin>>fina;
    rep(i,1,n)rep(j,1,n)cin>>d[i][j];
    // 把pre数组初始化为正无穷。
    memset(pre,0,sizeof pre);
    rep(i,1,n) f[i][i]=0;
    cout<<"start="<<1<<" "<<"endpoint="<<fina<<endl;
    //采用floyd算法求出从1到n的最短路径（本质上利用动态规划算法）
    rep(i,1,n)
    rep(j,1,n)
    rep(k,1,n)
    {
        if(d[i][j]>d[i][k]+d[k][j]) d[i][j]=d[i][k]+d[k][j],pre[i][j]=k;
    }
    cout<<"MinDistanceFrom-One-To-Final=="<<d[1][fina]<<endl;
    res.push_back(fina);
    dfs(1,fina);
    res.push_back(1);
    for(int i=res.size()-1;i>=0;i--)
    {
        cout<<res[i]<<"-\n"[i==0];
    }

// 5 5
// 0 1 2 3 4
// 1 0 3 4 1 
// 2 3 0 2 5
// 3 4 2 0 10
// 4 1 5 10 0

}
int main()
{
    int tt;
    tt = 1;
    startTime = clock();
    while (tt--)
    {
        solve();

        // printf("%.2lf",getCurrentTime());
    }
}