struct DominatorTree{
    //1-indexed
    //not reachable from s -> not on tree
    int n;
    vector<vector<int>> G,rG;
    vector<int> pa,dfn,id;
    int dfnCnt;
    vector<int> semi,idom,best;
    vector<vector<int>> ret;
    void init(int _n){
        n=_n;
        G = rG = ret = vector<vector<int>>(n+1);
        pa = dfn = id = vector<int>(n+1,-1);
        dfnCnt = 0;
        semi = idom = best = vector<int>(n+1,-1);
    }
    void add_edge(int u,int v){
        G[u].push_back(v);
        rG[v].push_back(u);
    }
    void dfs(int u){
        id[dfn[u]=++dfnCnt]=u;
        for(auto v:G[u]) if(!dfn[v]){
            dfs(v),pa[dfn[v]]=dfn[u];
        }
    }
    int find(int y,int x){
        if(y<=x)return y;
        int tmp=find(pa[y],x);
        if(semi[best[y]]>semi[best[pa[y]]])
            best[y]=best[pa[y]];
        return pa[y]=tmp;
    }
    void tarjan(int root){
        dfnCnt=0;
        for(int i=1;i<=n;++i){
            dfn[i]=idom[i]=0;
            ret[i].clear();
            best[i]=semi[i]=i;
        }
        dfs(root);
        for(int i=dfnCnt;i>1;--i){
            int u=id[i];
            for(auto v:rG[u]) if(v=dfn[v]){
                find(v,i);
                semi[i]=min(semi[i],semi[best[v]]);
            }
            ret[semi[i]].push_back(i);
            for(auto v:ret[pa[i]]){
                find(v,pa[i]);
                idom[v] = semi[best[v]]==pa[i] ? pa[i] : best[v];
            }
            ret[pa[i]].clear();
        }
        for(int i=2; i<=dfnCnt; ++i){
            if(idom[i]!=semi[i]) idom[i]=idom[idom[i]];
            ret[id[idom[i]]].push_back(id[i]);
        }
    }
    vector<vector<int>> solve(int s){
        tarjan(s);
        return ret;
    }
};
