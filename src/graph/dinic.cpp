struct Dinic{//0-indexed
  struct E{
    int t,f,c;
    E(int tt = 0,int cc = 0,int ff = 0):t(tt),c(cc),f(ff){}
  };
  vector<vector<int>> paths;
  vector<int> ptr,lvl;
  vector<E> e;
  queue<int> q;
  Dinic(int _n = 0){
    paths = vector<vector<int>>(_n);
    ptr = lvl = vector<int>(_n);
  }
  void add_edge(int a,int b,int c,int d = 0){
    paths[a].push_back(e.size());
    e.push_back(E(b,c));
    paths[b].push_back(e.size());
    e.push_back(E(a,d));
  }
  bool bfs(int s,int t){
    fill(lvl.begin(),lvl.end(),-1);
    q.push(s);
    lvl[s] = 0;
    while(!q.empty()){
      auto now = q.front();q.pop();
      for(auto &eid:paths[now]){
        if(e[eid].f == e[eid].c)continue;
        if(lvl[e[eid].t] == -1){
          lvl[e[eid].t] = lvl[now]+1;
          q.push(e[eid].t);
        }
      }
    }
    return lvl[t] != -1;
  }
  int dfs(int now,int t,int flow){
    if(now == t)return flow;
    for(int &i = ptr[now];i<paths[now].size();i++){
      int eid = paths[now][i];
      if(e[eid].f == e[eid].c||lvl[e[eid].t] != lvl[now]+1)continue;
      if(int re = dfs(e[eid].t,t,min(flow,e[eid].c-e[eid].f))){
        e[eid].f += re;
        e[eid^1].f -=re;
        return re;
      }
    }
    return 0;
  }
  int flow(int s,int t){
    int ans = 0;
    while(bfs(s,t)){
      fill(ptr.begin(),ptr.end(),0);
      while(auto re = dfs(s,t,INT_MAX)){
        ans += re;
      }
    }
    return ans;
  }
  bool inScut(int k){
    return lvl[k] != -1;
  }
};
