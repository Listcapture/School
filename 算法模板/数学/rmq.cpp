int f[N][18];
int a[N];
void init(){
    for(int j=0;j<=18;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            if(!j) f[i][j]=a[i];
            else f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    
    
}
int query (int l,int r){
     int len=r-l+1;
     int k=(int)log2(len);
     return max(f[l][k],f[r-(1<<k)+1][k]);
     
    
}