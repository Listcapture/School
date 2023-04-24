void dijkstra(int start,int dist[]){
    
    memset(dist,0x3f,sizeof 4*N);
    dist[start]=0;
    me(st,0);
    priority_queue<PII ,vector<PII>,greater<PII>>q;
    q.push({0,start});
    while(q.size()){
        auto t=q.top();q.pop();
        int ver=t.y;
        if(st[ver])continue;
         st[ver]=1;
        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[ver]+w[i]){
                dist[j]=dist[ver]+w[i];
                q.push({dist[j],j});
            }
        }
    }
    
    
}
void dijkstra(int s)
{
   memset(dist,0x3f,sizeof dist);
   dist[s]=0;
   priority_queue<PII,vector<PII>,greater<PII>heap;
   heap.push(make_pair(dist[s],s));
   while(heap.size())
   {
        PII t=heap.top();
        int ver=heap.second;
        if(st[ver])continue;
        st[ver]=true;
        for(int i=h[ver];~i;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dist[ver]+w[i])
            {
                dist[j]=dist[ver]+w[i];
                heap.push(make_pair(dist[j],j));
            }
        }

   }
   

}