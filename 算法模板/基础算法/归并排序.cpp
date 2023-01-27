const int N=1e6+10;
int a,b;
int q[N],tmp[N], n;
int  merge_sort(int q[],int l,int r)
{
    if(l>=r)
    return 0;
    int mid=(l+r)/2,i=l,j=mid+1,k=0;
    int nes=merge_sort(q,l,mid)+merge_sort(q,mid+1,r);
    while(i<=mid&&j<=r)
    {
        if(q[i]< q[j])tmp[k++]=q[i++];
        else
        {
            tmp[k++]=q[j++];
           nes+=mid-i+1;
        }
        }
    while(i<=mid)
    tmp[k++]=q[i++];
    while(j<=r)
    tmp[k++]=q[j++];
    for(int i=l,j=0;i<=r;i++,j++)
    q[i]=tmp[j];
    return nes;
}
