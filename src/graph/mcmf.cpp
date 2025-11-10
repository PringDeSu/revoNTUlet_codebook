#define T ll
const T inf = 1e12;
struct MCMF{//TC:O(VEF)
    struct E{
        int t,f;
        T c,w;
        E(int tt,T cap,T wei):t(tt),c(cap),w(wei),f(0){}
    };
    vector<E> e;
    vector<vector<int>> paths;
    vector<T> dis;
    vector<int> pre;
    vector<bool> inq;
    queue<int> q;
    int n;
    MCMF(int _n = 0){
        n = _n;
        paths = vector<vector<int>>(n);
        e.clear();
        pre = vector<int>(n);
        dis = vector<T>(n);
        inq = vector<bool>(n);
    }
    void add_edge(int a,int b,int c,int d){//from,to,cap,wei
        paths[a].push_back(e.size());
        e.push_back(E(b,c,d));
        paths[b].push_back(e.size());
        e.push_back(E(a,0,-d));
    }
    bool SPFA(int s,int t){
        fill(dis.begin(),dis.end(),inf);
        fill(pre.begin(),pre.end(),-1);
        dis[s] = 0;
        q.push(s);inq[s] = true;
        while(!q.empty()){
            auto now = q.front();q.pop();
            inq[now] = false;
            //assert(dis[now]>=0);
            for(auto &eid:paths[now]){
                if(e[eid].f == e[eid].c)continue;
                int nxt = e[eid].t;
                if(dis[nxt]>dis[now]+e[eid].w){
                    pre[nxt] = eid;
                    dis[nxt] = dis[now]+e[eid].w;
                    if(!inq[nxt]){
                        inq[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
        }
        return dis[t] != inf;
    }
    T flow(int s,int t,int cnt = INT_MAX){//cnt is the number of flows
        T ans = 0;
        while(cnt--&&SPFA(s,t)){
            ans += dis[t];
            int now = t;
            while(pre[now] != -1){
                int eid = pre[now];
                e[eid].f++;
                e[eid^1].f--;
                now = e[eid^1].t;
            }
        }
        return ans;
    }
};
#undef T
