// needs dinic
struct GomoryHuTree{//0-indexed
#define pii pair<int,int>
#define tiii tuple<int,int,int>
  vector<tiii> edges;
  vector<vector<pii>> tr;
  vector<int> p;
  int n;
  GomoryHuTree(int _n = 0){
    n = _n;
    p = vector<int>(_n,0);
    tr = vector<vector<pii>>(_n);
  }
  void add_edge(int a,int b,int c){
    edges.push_back(tiii(a,b,c));
  }
  vector<vector<pii>> make_tree(){
    fill(p.begin(),p.end(),0);
    tr = vector<vector<pii>>(n);
    for(int i = 1;i<p.size();i++){
      Dinic din(n);
      for(auto &[a,b,w]:edges){
        din.add_edge(a,b,w,w);
      }
      int w = din.flow(i,p[i]);
      tr[i].push_back(pii(p[i],w));
      tr[p[i]].push_back(pii(i,w));
      for(int j = i+1;j<n;j++){
        if(p[j] == p[i]&&din.inScut(j))p[j] = i;
      }
    }
    return tr;
  }
#undef pii
#undef tiii
};
