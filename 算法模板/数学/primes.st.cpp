int primes[10000],cnt;
bool st[1000000];
void init (int n){
      for(int i=2;i<n;i++)
      {
           if(!st[i])  primes[cnt++]=i;
            for(int j=0;primes[j]<=n/i;j++)
           {
                   st[primes[j]*i]=true;
                   if(i%primes[j]==0)  break;
            }

      }

}