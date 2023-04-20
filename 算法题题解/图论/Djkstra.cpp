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