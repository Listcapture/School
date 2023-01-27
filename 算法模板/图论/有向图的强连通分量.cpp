#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int M=1e6+10;
#define me(a,b) memset(a,b,sizeof a)
// n stand for the points in the map
// directed map 
int h[N],e[M],ne[M],cnt;
int belong[N],stap[N],stop,instack[N],dfn[N],low[N],bent,dindex;
// belongcn == bent cnt-> QLTFL belong ->the QLTFL of point i;
void add(int a,int b){
	e[cnt]=b,ne[cnt]=h[a],h[a]=cnt++;
}
void tarjan(int i){
	dfn[i]=low[i]=++dindex;
	instack[stap[++stop]=i]=1;
	for(int p=h[i];~p;p=ne[p]){
		int j=e[p];
		if(!dfn[j]){
           tarjan(j);
		   if(low[j]<low[i])low[i]=low[j];
		   		
		}else if(instack[j]&&dfn[j]<low[i]) low[i]=dfn[j];
		
	}
	if(dfn[i]==low[i]){
		++bent;
		int j;
		do{
			j=stap[stop--];
			instack[j]=0;
			belong[j]=bent;
			
		}while(j!=i);
	}
}
signed main(){
	
    return 0;
}
