#define ll long long
const int SZ = 2e5+10;
//1-indexed,0 used for nullptr
//range reverse range sum
struct Splay{
#define ls ch[x][0]
#define rs ch[x][1]
#define p fa[x]
#define g fa[fa[x]]
  ll val[SZ];
  ll sum[SZ];
  int ch[SZ][2],fa[SZ],cnt,rev[SZ],sz[SZ];
  void pull(int x){
    if(!x)return;
    sum[x] = sum[ls]+sum[rs]+val[x];
    sz[x] = sz[ls]+sz[rs]+1;
    return;
  }
  void push(int x){
    if(!x)return;
    if(rev[x]){
      swap(ls,rs);
      rev[ls] ^= 1;
      rev[rs] ^= 1;
      rev[x] = 0;
    }
    pull(x);
    return;
  }
  Splay(){
    fill(sz+1,sz+SZ,1);
    return;
  }
  int newnode(){
    return ++cnt;
  }
  int dir(int x){//is ls or rs
    return ch[p][1] == x;
  }
  bool isroot(int x){//the || is for LCT
    return !p||ch[p][dir(x)] != x;
  }
  void rot(int x){ //g, p, x, here are _g, _p, _x
    int _p = p, _g = g, _x = x;
    push(_g); push(_p); push(_x);
    int d = dir(_x);
    if(!isroot(_p))ch[_g][dir(_p)] = _x;
    fa[ch[x][d^1]] = _p;
    ch[_p][d] = ch[_x][d^1];
    fa[_x] = _g;
    fa[_p] = _x;
    ch[_x][d^1] = _p;
    pull(_p);
    pull(_x);
    return;
  }
  void splay(int x){
    if(!x)return;
    while(!isroot(x)){
      push(g); push(p); push(x);
      if(!isroot(p)){
        rot(dir(p) == dir(x)? p: x);
      }
      rot(x);
    }
    push(x);
    return;
  }
  int get_sz(int x,int y){
    push(x);
    while(x&&sz[ls]+1 != y){
      if(sz[ls]>=y)x = ls;
      else{
        y -= sz[ls]+1;
        x = rs;
      }
      push(x);
    }
    return x;
  }
  void merge(int a,int b){
    if(!a||!b)return;
    splay(a);splay(b);
    a = get_sz(a,sz[a]);
    b = get_sz(b,1);
    splay(a);splay(b);
    ch[a][1] = b;
    fa[b] = a;
    pull(a);
    return;
  }
  pair<int,int> split(int a,int s){
    splay(a);
    if(!s)return make_pair(0,a);
    int b = get_sz(a,s);
    splay(b);
    pair<int,int> re;
    re.first = b;
    re.second = ch[b][1];
    fa[ch[b][1]] = 0;
    ch[b][1] = 0;
    pull(b);
    return re;
  }
#undef ls
#undef rs
#undef p
#undef g
};
