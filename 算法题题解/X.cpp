#include <bits/stdc++.h>
using namespace std;
const int N=1e7+10;
int vis[N],p,t;
const int M=2e6+10;
int ct[M],prime[M];
int max1=1e7+9;
int init()
{
   memset(vis,1,sizeof(vis));
   p=0;
   vis[1]=0;
   for(int i=2;i<=max1;i++)
   {
       if (vis[i])
       {

         prime[++p]=i;
         for(int j=2;i*j<=max1;j++)
              vis[i*j]=0;
       }
    }
    t=0;
    for(int i=1;i<=p;i++)
    if (vis[i]) ct[++t]=prime[i];

 return 0;

}

int main()
{


    init();
   // cout<<p<<" "<<t<<endl;
    int n,ans=-1;
    while(cin>>n)
    {

           ans=-1;
            for(int i=1;i<t;i++)
                if (ct[i]<=n&&ct[i+1]>n)
                 {
                     ans=ct[i];
                     break;
                 }

            cout<<ans<<endl;



    }



    return 0;
}