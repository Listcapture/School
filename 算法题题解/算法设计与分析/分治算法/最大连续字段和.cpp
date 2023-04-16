
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define PLL pair<LL, LL>
#define PII pair<int, int>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define dep(i, a, b) for (int i = a; i >= b; i--)
#define lowbit(x) (x & -x)
#define x first
#define y second
const double eps = 1e-8;
clock_t startTime;
#define l first
#define r second
double getCurrentTime()
{
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
const int N=2e5+10;
int a[N];
int  MaxSubSum(int a[],int left,int right)
{
  if(left>right) return 0;
  if(left==right)return a[left];
  int mid=(left+right)/2;
  int res1=MaxSubSum(a,left,mid),res2=MaxSubSum(a,mid+1,right);
  int s1=0,s2=0;
  int tres=0;
  for(int i=mid;i>=left;i--)
  {
    tres+=a[i];
    if(tres>=s1) s1=tres;
    else break;
  }
  tres=0;
  for(int i=mid+1;i<=right;i++)
  {
    tres+=a[i];
    if(tres>=s2) s2=tres;
    else break;
  }

  return max(res1,max(res2,s1+s2));

}

void ChessBoard(int tr,int tc,int dr,int dc,int size)
{
    if(size==1) return ;
    size/=2;
    timestamp++;
    if(dr<=tr+size-1&&dc<=tc+size-1)
    {
      ChessBoard(tr,tc,dr,dc,size);
    }else 
    {
      a[tr+size-1][tc+size-1]=timestamp;
      ChessBoard(tr,tc,tr+size-1,tc+size-1,size);
    }
    if(dr>tr+size-1&&dc>tc+size-1)
    { 
      ChessBoard(tr+size,tc+size,dr,dc,size);
    }else 
    {
      a[tr+size][tc+size]=timestamp;
      ChessBoard(tr+size,tc+size,tr+size,tc+size,size);

    }
    if(dr<=tr+size-1&&dc>tc+size-1)
    {
      ChessBoard(tr,tc+size,dr,dc,size);
    }else 
    {
      a[tr][tc+size]=timestamp;
      ChessBoard(tr,tc+size,tr,tc+size,size);
    }
    if(dr>tr+size-1&&dc<=tc+size-1)
    {
      ChessBoard(tr+size,tc,dr,dc,size);
    }else
    {
      a[tr+size][tc]=timestamp;
      ChessBoard(tr+size,tc,tr+size,tc,size);
    }

}
void QuickSort (int a[], int p, int r)
{
      if (p<r) {
        int q=Partition(a,p,r);
        QuickSort (a,p,q-1); //对左半段排序
        QuickSort (a,q+1,r); //对右半段排序
        }
}

int Partition (int a[], int p, int r)
{        int i = p, j = r + 1; 
        int x=a[p];
while (true) {
           while (a[++i]<x&&i<r);
           while (a[- -j]>x&&j>p);
           if (i >= j) break; 
           swap(a[i], a[j]);
           }
       a[p] = a[j];
       a[j] = x;
       return j;
}
void Table(int k,int **a)
{
    int n=1;
    for(int i=1;i<=k;i++)
    n*=2;
    for(int i=1;i<=n;i++)
    a[1][i]=i;
    int m=1;
    for(int s=1;s<=k;s++)
    {
        n/=2;
        for(int t=1;t<=n;t++)
        {
            for(int i=m+1;i<=2*m;i++)
            {
                for(int j=m+1;j<=2*m;j++)
                    {
                    a[i][j+(t-1)*m*2]=a[i-m][j+(t-1)*m*2-m];
                    a[i][j+(t-1)*m*2-m]=a[i-m][j+(t-1)*m*2];
                }
                m*=2; 
        }
        } 
    } 
}    
void MatrixChain(int *p,int n,int **m,int **s)
{
        for (int i = 1; i <= n; i++) m[i][i] = 0;
        for (int r = 2; r <= n; r++)
           for (int i = 1; i <= n - r+1; i++) {
              int j=i+r-1;
              m[i][j] = m[i+1][j]+ p[i-1]*p[i]*p[j];
              s[i][j] = i;
              for (int k = i+1; k < j; k++) {
                 int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                 if (t < m[i][j]) { m[i][j] = t; s[i][j] = k;}
              }
          }
}


int main()
{
  int tt;
  tt = 1;
  startTime = clock();
  while (tt--)
  {
    int n;
    cin>>n;
    rep(i,1,n) cin>>a[i];
    cout<<MaxSubSum(a,1,n)<<endl;

  }
}
