#include<bits/stdc++.h>
using namespace std;
const int N=40010;
int a[210];
int p[N];
int n,m;

int get(int x,int y)
{
  return x*n+y;
}
int find(int x)
{
      if(p[x]!=x) p[x]=find(p[x]);
      return p[x];
}


int main(){
   
      cin>>n>>m;
      int ans=0;
      for(int i=0;i<n*n;i++)  p[i]=i;
      
      for(int i=1;i<=m;i++)  
      {
          int x,y;
           char d;
           cin>>x>>y>>d;
           x--,y--;
           int a=get(x,y);
           int b=0;
           if(d=='D') b=get(x+1,y);
           else b=get(x,y+1);
           int pa=find(a),pb=find(b);
           if(pa==pb)
           {
               ans=i;
               break;
               
           }
           p[pa]=pb;
          
          
          
      }
    
     if(!ans)  cout<<"draw"<<'\n';
     else cout<<ans<<endl;
    
    
    
    
}