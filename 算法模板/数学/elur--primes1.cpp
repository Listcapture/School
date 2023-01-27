#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+10;
bool st[N];
int cnt,primes[N];
int phi[N];
int get_elur(int n){
	for(int i=2;i<=n;i++){
		if(!st[i]) primes[cnt++]=i,phi[i]=i-1;
        
		for(int j=0;primes[j]*i<=n;j++){
			st[primes[j]*i]=1;4
			if(i%primes[j]==0) 
			{
				phi[primes[j]*i]=phi[i]*primes[j];
				break;
			}
			phi[primes[j]*i]=phi[i]*(primes[j]-1);
		}
		
		
	}
	int res=0;
	for(int i=1;i<=n;i++){
		res+=phi[i];
	}
	return res+1;
}
signed main(){
    int n;
    cin>>n;
    cout<<get_elur(N)<<endl;
	cout << phi[n] << endl;
	return 0;
}
