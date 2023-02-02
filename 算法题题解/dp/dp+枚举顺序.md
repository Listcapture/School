
###### 链接：https://ac.nowcoder.com/acm/contest/46813/L
###### 来源：牛客竞赛

#### 题目：
>一堆石头共有$n$块，你需要进行$m$次操作，执行第$i$次操作的的代价为$b_i$,
>同时使得石头总数变为$n-n\%x_i$,问使得石头总数不再减小的最小代价为多少。
>你可以进行任意第$i$次操作,只需要保证总操作次数为$m$.

#### 输入输出格式
![Alt text](dp+%E6%9E%9A%E4%B8%BE%E9%A1%BA%E5%BA%8F.png)

#### 思路1：
>设$f\lbrack j\rbrack$表示使得石头总数变为j的最小代价，初始化$f[m]=0$,那么就有状态转移方程
>$$f[j-j\%x[i]\ ]=min(f[j-j\%x[i],f[j]+b[i])$$
>虽然我们可以进行任意第$i$次操作,连续进行相同的操作不会使得石头总数变小
>比如我们用第i此操作使得$7-->6$这种变化,代价为$d_1$,对于石子总数$6$,连续进行第$i$次操作是无用的,如果我们以$i$为第一枚举元素,就会连续进行这种无
意义的操作,而当$i-->i+1$时,$i$操作就无法再使用了,这会使得答案错误,改变枚举顺序是一种很好的方式,事实上,以i为第二关键字枚举,总能证明是最优的.


#### 代码：
    #include<bits/stdc++.h>
    using namespace std;
    typedef long long LL;
    const int N=2e5+10;
    #define rep(i,a,b) for(int i=a;i<=b;i++)
    #define dep(i,a,b) for(int i=a;i>=b;i--)
    #define lowbit(x) (x&-x)
    const double eps=1e-8;
    clock_t startTime;
    double getCurrentTime() {
        return (double)(clock() - startTime) / CLOCKS_PER_SEC;
    }
    int v[N],w[N];
    int f[N];
    void solve()
    {
    int n,m;
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
    }
    memset(f,0x3f,sizeof (f));
    f[m]=0;// f[j]表示使当前人数变为j的最小花费
    for(int j=m;j>=1;j--)
    {
        for(int i=1;i<=n;i++)
        {
            if(v[i]<=j)  f[j-j%v[i]]=min(f[j-j%v[i]],f[j]+w[i]);
        }
    }
        for(int i=1;i<=m;i++)
        {
            if(f[i]!=f[0])
            {
                cout<<f[i]<<endl;
                return ;
            }
        }

    }

    int main()
    {
        int tt;
        tt=1;
        startTime = clock();
        while(tt--)
        {
            solve();
            

            //printf("%.2lf",getCurrentTime());
        }
    }
#### 思路2：
>设$f_j$为当前石头总数为$j$时使得石头总数不能再减小的最小花费,
>初始化$f_1=f_2=0$,可以得到的一个状态转移方程为            
>$$f[j]=min(f[t]+w[i],f[j]),其中t-t\%x[i]=j$$    
>整理有$j=\lfloor \frac{t}{x[i]} \rfloor \cdot x[i]$
原状态转移方程$f[t/x[i]\cdot x[i]]=min(f[t]+w[i],f[t/x[i]\cdot x[i]])$   
对$j,t$相互映射可得,$f[j]=min(f[j],f[j-j\%x[i]]+w[i])$  
>j从小到大枚举,注意当$f[j]==0x3f3f3f3f$时,说明无论选取何种操作都不能使得石头总数为
>j的石头数量变小,那么重新赋值$f[j]=0$,表示j已经不能变得更小了,代价是$0$.

#### 代码：
    #include<bits/stdc++.h>
    using namespace std;
    typedef long long LL;
    const int N=2e5+10;
    #define rep(i,a,b) for(int i=a;i<=b;i++)
    #define dep(i,a,b) for(int i=a;i>=b;i--)
    #define lowbit(x) (x&-x)
    const double eps=1e-8;
    clock_t startTime;
    double getCurrentTime() {
        return (double)(clock() - startTime) / CLOCKS_PER_SEC;
    }
    int v[N],w[N];
    int f[N];
    void solve()
    {
    int n,m;
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
    }
    memset(f,0x3f,sizeof (f));
    f[1]=f[2]=0;//f[j]表示当前人数为j时所需花费的最小代价
    for(int j=1;j<=m;j++ )
    {
        for(int i=1;i<=n;i++)
        {
           if(j>=v[i]) f[j]=min(f[j],f[j-j%v[i]]+w[i]);
        }
        if(f[j]==0x3f3f3f3f) f[j]=0;
    }
    cout<<f[m]<<endl;
    }

    int main()
    {
        int tt;
        tt=1;
        startTime = clock();
        while(tt--)
        {
            solve();
            //printf("%.2lf",getCurrentTime());
        }
    }





































































    