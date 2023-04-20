#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
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
int v[N], w[N];
int f[N][N];
int n,m;
void solve()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
    // 求解背包可以获得的最大值
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
           if(j>=v[i]) f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
           else f[i][j]=f[i-1][j];        
        }
    }
    cout<<"MaxValue=="<<f[n][m]<<endl;
    vector<int >ans;
    int i=n,j=m;
    //自顶向下，用非递归的回溯求出装入了所有装入物品的下标。
    while(i&&j)
    {
        // f[i][j]- f[i-1][j],f[i-1][j-v[i]]+w[i]
       
        if(f[i][j]-w[i]==f[i-1][j-v[i]]) ans.push_back(i),j-=v[i],i--;
        else i--;
    }
    for(int i=ans.size()-1;i>=0;i--)
    {
        cout<<ans[i]<<" "<<endl;
    }
}
// 90 5
// 3  12
// 56 28
// 77 49
// 21 9
// 87 35
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
