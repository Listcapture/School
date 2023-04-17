#include<bits/stdc++.h>
using namespace std;

const int N=20;
char tr[N];
char s[N];
void build(int root)
{
   if(s[root-1]=='#') return ;
   else tr[root]=s[root-1];
  
   build(root*2);
   build(root*2+1);
}
void dfs(int u)
{
  if(tr[u]=='0') return ;
  dfs(u*2);
  cout<<tr[u]<<endl;
  dfs(u*2+1);
}
int main()
{
  
  string str;
  cin>>str;
  int len=str.size();
  for(int i=0;i<len;i++) s[i]=str[i];
  for(int i=len;i<N;i++)s[i]='0';

  build(1);
  //dfs(1);
  // abc##de#g##f###
  
  
  
  
  return 0;
}