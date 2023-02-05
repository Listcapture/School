#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
#define PLL pair<LL,LL>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
#define lowbit(x) (x&-x)
const double eps=1e-8;
bool cmp(PLL a,PLL b)
{
  return a.first<b.first;
}
clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
queue<int >q[30];
LL n,k;
string s;

bool cmp(char a,char b)
{
  return a>b;
}
void solve()
{
   cin>>n>>k>>s;
   string head,tail;
   for(int i=0;s[i];i++)
   {
      while(head.size()&&head.size()<s[i]&&k)
      { 
        tail.push_back(head.back());
        head.pop_back();
        k--;
      }
      head.push_bacK(s[i]);
   }
   while(k&&head.size())
   {
    tail.push_back(head.back());
    head.pop_back;
    k--;
   }
   sort(tail.begin(),tail.end(),greater());
   cout<<head+tail<<endl;

 
}
//ddcbaba ccaa k=2
//cadbcadbc
int main()
{
    int tt;
    tt=1;
    init();
    startTime = clock();
    while(tt--)
    {
        solve();
        //printf("%.2lf",getCurrentTime());
    }
}
