#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
#define lowbit(x) (x&-x)
const double eps=1e-8;
clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
queue<int >q[30];
void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    for(int i=0;s[i];i++)
    {
        q[s[i]-'a'].push(i);
    }
    string s1,s2,s3;
    int cur=0;
    for(int i=1;i<=n;i++)
    {
        
    }
    
    cout<<s1<<" "<<s2<<endl;
    
}

int main()
{
    int tt;
    tt=1;
    startTime = clock();
    while(tt--)
    {
        solve();
        

        printf("%.2lf",getCurrentTime());
    }
}