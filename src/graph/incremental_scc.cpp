struct IncrementalSCC{
#define pii pair<int,int>
#define fs first
#define sc second
#define tiii tuple<int,int,int>
    //if u == v : ans[i] = -1
    //if not connected : ans[i] = m
    //all 0-indexed
    int n;
    vector<int> ans;
    int m;
    vector<tiii> all;
    vector<int> SCC(int n,vector<vector<int>>& paths){
        vector<int> scc_id(n,-1),idx(n,-1),low(n,-1),st;
        int cnt = 0,gcnt = 0;
        function<void(int)> dfs = [&](int now)->void{
            low[now] = idx[now] = cnt++;
            st.push_back(now);
            for(auto nxt:paths[now]){
                if(scc_id[nxt] != -1)continue;
                if(idx[nxt] == -1){
                    dfs(nxt);
                    low[now] = min(low[now],low[nxt]);
                }
                else{
                    low[now] = min(low[now],idx[nxt]);
                }
            }
            if(low[now] == idx[now]){
                int id = -1;
                while(id != now){
                    id = st.back();
                    st.pop_back();
                    scc_id[id] = gcnt;
                }
                gcnt++;
            }
        };
        for(int i = 0;i<n;i++){
            if(scc_id[i] == -1)dfs(i);
        }
        return scc_id;
    }
    vector<int> mapping;
    void dc(int l,int r,vector<tiii> &edges){
        if(l == r){
            for(auto &[id,_,__]:edges)ans[id] = min(ans[id],l);
            return;
        }
        int mid = (l+r)>>1;
        int cnt = 0;
        for(auto &[t,u,v]:edges){
            if(mapping[u] == -1)mapping[u] = cnt++;
            if(mapping[v] == -1)mapping[v] = cnt++;
        }
        n = cnt;
        vector<vector<int>> paths(n);
        vector<int> vv;
        for(auto &[t,u,v]:edges){
            vv.push_back(u);
            vv.push_back(v);
            u = mapping[u],v = mapping[v];
            if(t<=mid)paths[u].push_back(v);
        }
        for(auto &i:vv)mapping[i] = -1;

        auto scc_id = SCC(n,paths);
        vector<tiii> vl,vr;
        for(auto &[t,u,v]:edges){
            if(scc_id[u] == scc_id[v]){
                ans[t] = min(ans[t],mid);
                vl.push_back(tiii(t,u,v));
            }
            else{
                u = scc_id[u],v = scc_id[v];
                vr.push_back(tiii(t,u,v));
            }
        }
        vector<tiii>().swap(edges);
        dc(l,mid,vl);
        dc(mid+1,r,vr);
        return;
    }
    void add_edge(int u,int v){
        all.push_back(tiii(all.size(),u,v));
    }
    vector<tiii> solve(){//[time,u,v]
        m = all.size();
        vector<tiii> ret(m);
        for(auto [t,u,v]:all)ret[t] = tiii(m,u,v);
        for(auto [t,u,v]:all)n = max({n,u,v});
        n++;
        ans = vector<int>(m,m);
        for(auto [t,u,v]:all){
            if(u == v)ans[t] = -1;
        }
        mapping = vector<int>(n,-1);
        dc(0,m,all);
        for(int i = 0;i<m;i++)get<0>(ret[i]) = ans[i];
        return ret;
    }
    IncrementalSCC(){
        ans.clear();
        n = m = 0;
    }
#undef tiii
#undef pii
#undef fs
#undef sc
};
