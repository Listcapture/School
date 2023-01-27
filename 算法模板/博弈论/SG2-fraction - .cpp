#include<bits/stdc++.h>
using namespace std;
int n;
const int N=110;
int f[N];
int sg(int x){
	if(f[x]!=-1) return f[x];
	unordered_set<int >S;
	for(int i=0;i<x;i++){
		for(int j=0;j<=i;j++){
			S.insert(sg(i)^sg(j));
		}
	}
	for(int i=0;;i++) if(!S.count(i)) return f[x]=i;
}
signed main(){
    int ans=0;
    cin>>n;
    memset(f,-1,sizeof f);
    for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		ans^=sg(x);
	}
	cout<<(ans?"Yes":"No")<<endl;
	return 0;
}