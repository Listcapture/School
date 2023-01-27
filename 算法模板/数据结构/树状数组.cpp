#include<bits/stdc++.h>

using namespace std;
int n,m;
int input[500010];
int tree[500100];
    int lowbit(int x)
    {
        return x & -x;
    }
    void add(int x,int k)
    {
        while(x<=n)
        {
            tree[x]+=k;
            x+=lowbit(x);
        }
    }
    int search(int x)
    {
        int ans=0;
        while(x!=0)
        {
            ans+=tree[x];
            x-=lowbit(x);
        }
        return ans;
    }
    int main()
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>input[i];
        for(int i=1;i<=m;i++)
        {
            int a;
            scanf("%d",&a);
            if(a==1)
            {
                int x,y,z;
                scanf("%d%d%d",&x,&y,&z);
                add(x,z);
                add(y+1,-z);
            }
            if(a==2)
            {
                int x;
                scanf("%d",&x);
                printf("%d\n",input[x]+search(x));
            }
        }
        return 0;
    }
