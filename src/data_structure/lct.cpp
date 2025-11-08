#define ll long long
// 1-based, needs splay
// vertex add paths sum link-cut
struct LCT{
	Splay sp;
	void access(int x){
		sp.splay(x);
		sp.ch[x][1] =  0;
		sp.pull(x);
		while(sp.fa[x]){
			int u = sp.fa[x];
			sp.splay(u);
			sp.push(u);
			sp.ch[u][1] = x;
			sp.pull(u);
			sp.splay(x);
		}
	}
	void makeroot(int x){
		access(x);sp.splay(x);
		sp.rev[x] ^= 1;
	}
	void link(int u,int v){
		makeroot(u);
		sp.splay(u);
		sp.fa[u] = v;
	}
	void cut(int u,int v){
		makeroot(u);
		access(v);
		sp.splay(v);
		int lc = sp.ch[v][0];
		sp.fa[lc] = 0;
		sp.ch[v][0] = 0;
		sp.pull(v);
	}
	ll path_sum(int u,int v){
		makeroot(u);
		access(v);
		sp.splay(v);
		return sp.sum[v];
	}
	void addval(int u,int val){
		sp.splay(u);
		sp.val[u] += val;
		sp.pull(u);
		return;
	}
	int find(int p){
		access(p);
		return sp.get_sz(p,1);
	}
};
