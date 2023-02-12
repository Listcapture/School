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

int n;
int a[N];
// fi 表示大于 i 的 距里 i 最近的数的位置。
map<LL,LL >cnt;
void solve()
{
 cin>>n;
 rep(i,1,n)cin>>a[i];
 if(a[i]%2==1)
 {
    cout<<0<<endl;
 }else 
 {
    rep(i,1,n)
    {
        if(a[i]<a[1])
        {
            cout<<1<<endl;
            return ;
        }
    }
    cout<<-1<<endl;
    return ;
 }
   
   

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
    return 0;
}
