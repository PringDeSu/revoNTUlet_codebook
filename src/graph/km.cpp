// Kuhn-Munkres : Bipartite matching with "maximum" weight in O(n^3)
// NOTICE THAT match[y] = x 
struct KM{
  const static int M = 500; // modify maximum number of vertices
  int n;
  ll ans = 0;
  // 0-base
  vector<vector<ll>> w; // input weighted edges w[x][y]
  vector<int> match; // match[y] = x
  vector<ll> lx, ly, slack;
  bitset<M> visx, visy; // initialize with all zero

  // abbr
# define forx for(int x=0; x<n; x++)
# define fory for(int y=0; y<n; y++)
# define z match[y]

  bool dfs(int x){
    visx[x] = 1;
    fory{
      if(visy[y]) continue;
      ll d = lx[x]+ly[y]-w[x][y];
      if(!d){
        visy[y] = 1;
        if(z==-1 || (!visx[z] && dfs(z))){
          z = x;
          return 1;
        }
      }
      else if(d<slack[y]) slack[y] = d;
    }
    return 0;
  }

  bool augment(){
    fory if(!visy[y] && !slack[y]){
      visy[y] = 1;
      if(z==-1) return 1;
      else if(!visx[z] && dfs(z)){
        z = -1;
        return 1;
      }
    }
    return 0;
  }

  void relabel(){
    ll d = INT64_MAX;
    fory if(!visy[y]) d = min(d, slack[y]);
    forx if(visx[x]) lx[x] -= d;
    fory{
      if(visy[y]) ly[y] += d;
      else slack[y] -= d;
    }
  }

  KM(vector<vector<ll>> &W): n(W.size()), w(W) { // input edges' weight
                           //initialize
    slack.resize(n);
    match.assign(n, -1);
    lx.assign(n, INT64_MIN);
    ly.assign(n, 0);
    forx fory lx[x] = max(lx[x], w[x][y]);
    //matching
    forx{
      visx.reset();
      visy.reset();
      visx[x] = 1;
      fory slack[y] = lx[x]+ly[y]-w[x][y];
      while(!augment()) relabel();
      visx.reset();
      visy.reset();
      dfs(x);
    }
    //summing
    forx ans += lx[x];
    fory ans += ly[y];
  }

# undef forx
# undef fory
# undef z 
};
