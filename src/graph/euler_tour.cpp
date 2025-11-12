struct EulerTour{
  // undirected graph,0-indexed,fails if doesn't exist
  // for directed graph, remove the g[b].push_back(pii(a, id)) line in add_edge
  // returns the order of edges
  vector<vector<pii>> g;
  vector<int> ptr;
  vector<bool> vis;
  vector<int> re;
  int n,ecnt;
  void init(int _n){
    n = _n;
    ecnt = 0;
    g = vector<vector<pii>>(n);
    ptr = vector<int>(n);
  }
  void add_edge(int a,int b,int id = -1){
    if(id == -1)id = ecnt;
    g[a].push_back(pii(b,id));
    g[b].push_back(pii(a,id));
    ecnt++;
  }
  void dfs(int now){
    for(int &i = ptr[now];i<g[now].size();i++){
      auto [to,eid] = g[now][i];
      if(vis[eid]) continue;
      vis[eid] = true;
      dfs(to);
      re.push_back(eid);
    }
    return;
  }
  vector<int> solve(int s){
    re.clear();
    vis = vector<bool>(ecnt,0);
    dfs(s);
    reverse(re.begin(),re.end());
    return re;
  }
};
