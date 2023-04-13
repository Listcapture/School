
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define PLL pair<LL, LL>
#define PII pair<int, int>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define dep(i, a, b) for (int i = a; i >= b; i--)
#define lowbit(x) (x & -x)
#define x first
#define y second
const double eps = 1e-8;
clock_t startTime;
#define l first
#define r second
double getCurrentTime()
{
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 2020;
int p[N], w[N];
int f[N][N];
void solve()
{
  int n, m;
  cin >> m >> n;
  rep(i, 1, n) cin >> p[i] >> w[i];
  rep(i, 1, n)
  {
    rep(j, p[i], m)
    {
      f[i][j] = max(f[i][j], f[i - 1][j - p[i]] + p[i] * w[i]);
    }
  }
  cout << f[n][m] << endl;
  vector<int> ans;
  int i = n, j = m;
  while (i > 1 && j >= 0)
  {
    if (f[i][j] - p[i] * w[i] == f[i - 1][j - p[i]])
    {
      ans.push_back(i);
      j -= p[i];
      i--;
    }
    else
      i--;
  }
  cout << "ans.size()==" << ans.size() << endl;
  cout << "��Ʒ��Ϣ��" << endl;
  for (int i = ans.size() - 1; i >= 0; i--)
  {
    cout << ans[i] << " " << p[ans[i]] << " " << w[ans[i]] << endl;
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

// 2000 6
// 200 2
// 300 2
// 600 1
// 400 3
// 1000 4
// 800 5