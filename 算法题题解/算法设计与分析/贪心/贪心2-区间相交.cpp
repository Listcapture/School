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
struct seg{
    int l,r;
}segs[N];
bool cmp(seg a,seg b)
{
   if(a.l!=b.l) return a.l<b.l;
   return a.r<b.r;
   
}
void solve()
{
    int n;
    cin>>n;
    rep(i,1,n) {
        int l,r;
        cin>>l>>r;
        if(l>r) swap(l,r);
        segs[i].l=l;
        segs[i].r=r;
    }
    sort(segs+1,segs+1+n,cmp);
    int tl=segs[1].l,tr=segs[1].r;
    int ans=0;
    rep(i,2,n)
    {
       if(segs[i].l<=tr) ans++;
       tr=max(tr,segs[i].r);
    }
    cout<<ans<<endl;

  
}
int main()
{
  int tt;
  tt = 1;
  startTime = clock();
  while (tt--)
  {
    solve();
    // printf("%.2lf",getCurrentTime());
  }
}
