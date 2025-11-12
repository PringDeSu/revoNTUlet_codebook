#define ll long long
// range reverse range add range sum
// need to push before using the info on node
struct node{
  int pri;
  int pl,pr;
  ll sum,tag,val;
  int sz;
  int rev;
  node(){
    pl = pr = sum = tag = 0;
    sz = 0;
    rev = 0;
    pri = rand();
  }
};

const int SZ = 2e5+10;
struct Treap{
  node nd[SZ];
  int cnt = 0;
  Treap(){
    cnt = 0;
  }
  int newnode(){
    cnt++;
    nd[cnt].sz = 1;
    return cnt;
  }
  void pull(int now){
    if(!now)return;
    nd[now].sz = nd[nd[now].pr].sz+nd[nd[now].pl].sz+1;
    ll ls = nd[nd[now].pl].sum+nd[nd[now].pl].tag*nd[nd[now].pl].sz;
    ll rs = nd[nd[now].pr].sum+nd[nd[now].pr].tag*nd[nd[now].pr].sz;
    nd[now].sum = nd[now].val+ls+rs;
    return;
  }
  void push(int now){
    if(!now)return;
    if(nd[now].rev){
      swap(nd[now].pl,nd[now].pr);
      if(nd[now].pl)nd[nd[now].pl].rev ^= 1;
      if(nd[now].pr)nd[nd[now].pr].rev ^= 1;
      nd[now].rev = 0;
    }
    int tl = nd[now].pl,tr = nd[now].pr;
    nd[now].val += nd[now].tag;
    if(tl)nd[tl].tag += nd[now].tag;
    if(tr)nd[tr].tag += nd[now].tag;
    nd[now].tag = 0;
    pull(now);
  }
  int merge(int a,int b){
    if(!a)return b;
    if(!b)return a;
    if(nd[a].pri>nd[b].pri){
      push(a);
      nd[a].pr = merge(nd[a].pr,b);
      pull(a);
      return a;
    }
    else{
      push(b);
      nd[b].pl = merge(a,nd[b].pl);
      pull(b);
      return b;
    }
  }
  void split(int now,int &a,int &b,int tar){
    if(!now){
      a = b = 0;
      return;
    }
    push(now);
    if(nd[nd[now].pl].sz+1<=tar){
      a = now;
      split(nd[now].pr,nd[a].pr,b,tar-(nd[nd[now].pl].sz+1));
    }
    else{
      b = now;
      split(nd[now].pl,a,nd[b].pl,tar);
    }
    pull(a);
    pull(b);
    return;
  }
};
Treap T;
