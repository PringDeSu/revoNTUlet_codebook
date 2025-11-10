#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int SZ = 2e5+10;
//1-indexed,0 used for nullptr
//range reverse range sum
struct Splay{
#define ls ch[now][0]
#define rs ch[now][1]
    ll val[SZ];
    ll sum[SZ];
    int ch[SZ][2],fa[SZ],cnt,rev[SZ],sz[SZ];
    void pull(int now){
        if(!now)return;
        sum[now] = sum[ls]+sum[rs]+val[now];
        sz[now] = sz[ls]+sz[rs]+1;
        return;
    }
    void push(int now){
        if(!now)return;
        if(rev[now]){
            swap(ls,rs);
            rev[ls] ^= 1;
            rev[rs] ^= 1;
            rev[now] = 0;
        }
        pull(now);
        return;
    }
    Splay(){
        fill(sz+1,sz+SZ,1);
        return;
    }
    int newnode(){
        return ++cnt;
    }
    int dir(int now){//is ls or rs
        return ch[fa[now]][1] == now;
    }
    bool isroot(int k){//for LCT
        return !fa[k]||ch[fa[k]][dir(k)] != k;
    }
    void rot(int now){
        assert(now);
        assert(fa[now]);
        int p = fa[now];
        int g = fa[p];
        push(g);
        push(p);
        push(now);
        int d = dir(now);
        if(!isroot(p))ch[g][dir(p)] = now;
        fa[ch[now][d^1]] = p;
        ch[p][d] = ch[now][d^1];
        fa[now] = g;
        fa[p] = now;
        ch[now][d^1] = p;
        pull(p);
        pull(now);
        return;
    }
    void splay(int now){
        if(!now)return;
        while(!isroot(now)){
            push(fa[fa[now]]);
            push(fa[now]);
            push(now);
            if(!isroot(fa[now])){
                if(dir(fa[now]) == dir(now))rot(fa[now]);
                else rot(now);
            }
            rot(now);
        }
        push(now);
        return;
    }
    int get_sz(int now,int tar){
        push(now);
        while(now&&sz[ls]+1 != tar){
            if(sz[ls]>=tar)now = ls;
            else{
                tar -= sz[ls]+1;
                now = rs;
            }
            push(now);
        }
        return now;
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
    pair<int,int> split(int a,int tar){
        splay(a);
        if(!tar)return make_pair(0,a);
        int b = get_sz(a,tar);
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
};
