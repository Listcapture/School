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
    for(int i=1;i<=n;i++)
    {
        for(int j=v[i];j<=m;j++)
        {
            f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
        }
    }
    cout<<"MaxValue=="<<f[n][m]<<endl;
    vector<int >ans;
    int i=n,j=m;
    while(i&&j)
    {
        // f[i][j]- f[i-1][j],f[i-1][j-v[i]]+w[i]
       if(f[i][j]==f[i-1][j]) i--;
       else if(f[i][j]-w[i]==f[i-1][j-v[i]]) i--,ans.push_back(i),j-=v[i];
    }
    for(int i=ans.size()-1;i>=0;i--)
    {
        cout<<ans[i]<<" \n"[i==0];
    }
    

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