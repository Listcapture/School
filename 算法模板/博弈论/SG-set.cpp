
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,k;
const int N=110,M=1e4+10;
int s[N],f[M],x;
int sg(int x){
    if(f[x]!=-1) return  f[x];
    set<int >S;
    for(int i=1;i<=k;i++){
		int sum=s[i];
		if(x>=sum) S.insert(sg(x-sum));
	}
	for(int i=0;;i++)
	if(!S.count(i)) return f[x]=i;
}
signed main(){
    cin>>k;
    for(int i=1;i<=k;i++) cin>>s[i];
    cin>>n;
    memset(f,-1,sizeof f);
    int ans=0;
    for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		ans^=sg(x);
	}
	cout<<(ans?"Yes":"No")<<endl;
	return 0;
}