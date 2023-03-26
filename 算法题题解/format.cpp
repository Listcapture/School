
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
  cin>>n>>m;
  rep(i,1,n)p[i]=i,sz[i]=1;
  while(m--)
  {
    int a,b;
    cin>>a>>b;
    if(!mp[a]) poi.push_back(a);
    if(!mp[b]) poi.push_back(b);
    int pa=find(a),pb=find(b);
    if(pa!=pb)
    {
      p[pa]=pb;
      sz[pb]+=sz[pa];
    }else 
    {
        vector<int >fat;
        for(int i=0;i<(int)poi.size();i++)
        {
          fat.push_back(find(poi[i]));
        }
        if(fat.size()>=2)
        {
           int id1=0,id2=0;
           int ms1=0,ms2=0;
          for(int i=0;i<fat.size();i++)
          {
            int inv=fat[i];
            if(sz[inv]>ms1)
            {
              ms2=ms1;
              ms1=sz[inv];
              id2=id1;
              id1=inv;
            }else if(sz[inv]>=ms1&&id1!=inv)
            {
                ms2=sz[inv];
                id2=inv;
            }
          }
           p[id2]=id1;
           sz[id1]+=sz[id2];
        }
    }
    
       int ans=0;
       for(int i=0;i<(int)poi.size();i++)
       {
          int t=find(poi[i]);
          ans=max(ans,sz[t]);
       }
       cout<<ans<<endl;
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
}