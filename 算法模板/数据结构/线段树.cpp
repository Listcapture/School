#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
const int N=2e5+10;
int w[N];
struct node{
    int l,r;
    int sum,add;
}tr[N*4];
void pushup(int u){
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}
void pushdown(int u){
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if(root.add){
      left.add+=root.add,left.sum+=(left.r-left.l+1)*root.add;
      right.add+=root.add,right.sum+=(right.r-right.l+1)*root.add;
      root.add=0;
    }
}
void build(int u,int l,int r){
    if(l==r){
        tr[u]={l,r,w[l],0};
        
    }else {
        tr[u]={l,r};
        int mid=(tr[u].l+tr[u].r)>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
void modify(int u,int l,int r,int d){
    if(tr[u].l>=l&&tr[u].r<=r) {
        tr[u].sum+=(tr[u].r-tr[u].l+1)*d;
        tr[u].add+=d;
    }else {
        pushdown(u);
        int mid=(tr[u].l+tr[u].r)>>1;
        if(l<=mid) modify(u<<1,l,r,d);
        if(r>mid) modify(u<<1|1,l,r,d);
        pushup(u);
 
    }
}
int query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r) return tr[u].sum;
    else {
        pushdown(u);
        int mid=(tr[u].l+tr[u].r)>>1;
        int sum=0;
        if(l<=mid) sum+=query(u<<1,l,r);
        if(r>mid) sum+=query(u<<1|1,l,r);
        return sum;
    }
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    build(1,1,n);
    
    while(m--){
        char op;
        int l,r,d;
        cin>>op>>l>>r;
        if(op=='C'){
            cin>>d;
            modify(1,l,r,d);
        }else cout<<query(1,l,r)<<endl;
    }
    
    
    
    return 0;
}