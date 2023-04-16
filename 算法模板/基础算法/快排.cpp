//quick_sort()
const int N=2e5+10;
int q[N];
void quick_sort(int q[],int l,int r){

	if(l>=r) return ;
	int i=l-1,j=r+1,x=q[(l+r)>>1];
	while(i<j){
		do i++;while(q[i]<x);
		do j--;while(q[j]>x);
		if(i<j) swap(q[i],q[j]);
	}
	quick_sort(q,l,j),quick_sort(q,j+1,r);

}
int temp[10001];
void merge_sort(int a[],int l,int r)
{
   if(l>=r) return ;
   int mid=(l+r)/2;
   merge_sort(a,l,mid),merge_sort(a,mid+1,r);
   int i=l,j=mid+1,k=0;
   while(i<=mid&&j<=r)
   {
	if(a[i]<a[j]) temp[k++]=a[i];
	else temp[k++]=a[j++];
   }
   while(i<=mid) temp[k++]=a[i++];
   while(j<=mid) temp[k++]=a[j++];
   for(int i=l,j=0;i<=r;j++,i++) a[i]=temp[j];


}
void GreedySelector(int n, int s[], int f[], int A[])
{     
	   for(int i=1;i<=n;i++)
	   {
		for(int j=1;j<=n;j++)
		{
			if(f[i]>f[j])
			{
				swap(f[i],f[j]);
				swap(s[i],s[j]);
			}else if(f[i]==f[j]&&s[i]>s[j])
			{
				swap(s[i],s[j]);
			}
		}
	   }
       A[1]=1;
       int j=1;
       for (int i=2;i<=n;i++) 
	   {
             if (s[i]>=f[j]) { A[i]=1; j=i; }
             else A[i]=0; 
		}
}
void LCSLength(int m,int n,char *x,char *y,int **c,int **b)
{  
       int i,j;
       for (i = 1; i <= m; i++) c[i][0] = 0;
       for (i = 1; i <= n; i++) c[0][i] = 0;
       for (i = 1; i <= m; i++)
          for (j = 1; j <= n; j++) {
             if (x[i]==y[j]) { 
                  c[i][j]=c[i-1][j-1]+1; b[i][j]=1;}
             else if (c[i-1][j]>=c[i][j-1]) {
                  c[i][j]=c[i-1][j]; b[i][j]=2;}
             else { c[i][j]=c[i][j-1]; b[i][j]=3; }
             }
}

void LCS(int i,int j,char *x,int **b)
{
      if (i ==0 || j==0) return;
      if (b[i][j]== 1){ LCS(i-1,j-1,x,b); cout<<x[i]; }
      else if (b[i][j]== 2) LCS(i-1,j,x,b);
      else LCS(i,j-1,x,b);
}


 