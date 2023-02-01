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
string a,b;
int p[10];
void solve()
{
   cin>>a>>b;
   int lena=a.length(),lenb=b.length();
   memset(p,-1,sizeof p);
   bool sp=0;
   if(lena==lenb)
   {
       if(a==b) cout<<"="<<endl;
       else cout<<"!"<<endl;
   }else 
   {
      if(lena<lenb) swap(a,b),swap(lena,lenb),sp=true; 
      int len=max(lena,lenb);
      int l=0,r=9;
      int status=0;
      for(int i=0;i<lena-lenb;i++)
      {
          char sa=a[i]-'0';
          if(p[sa]==-1) p[sa]=l++;
          if(p[sa]>0) 
          {
              cout<<(sp?"<":">")<<endl;
              return ;
          }
      }
       bool can=true;
       int tlen=lena-lenb;
      for(int i=lena-lenb;i<lena;i++)
      {
          int  sa=a[i]-'0',sb=b[i-tlen]-'0';
          if(p[sa]==-1) p[sa]=l++;
          if(p[sb]==-1) p[sb]=r--;
          
          if(p[sa]>p[sb]) 
          {
              cout<<(sp?"<":">")<<endl;
              return  ;
          }else if(p[sa]<p[sb])
          {
            cout<<"!"<<endl;
            return ;
          }
      }
    
       
       cout<<"!"<<endl;
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