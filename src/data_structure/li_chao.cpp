// range add line get min
// can even be used if modifies aren't range modify
#define ll long long
const ll SZ = 8e6+10;
const ll inf = 3e18;
vector<ll> all; // coordinates are stored here
struct Line{
    ll m,b;
    Line(ll mm = 0,ll bb = 0):m(mm),b(bb){}
    ll operator()(ll k){
        return m*k+b;
    }
};
struct LiChao{
#define ls now*2+1
#define rs now*2+2
#define mid ((l+r)>>1)
    Line seg[SZ];
    LiChao(){
        fill(seg,seg+SZ,Line(0,inf));
    }
    void modify(int now,int l,int r,int s,int e,Line v){
        if(l == r){
            if(seg[now](all[l])>v(all[l]))swap(seg[now],v);
            return;
        }
        if(l>=s&&e>=r){
            if(seg[now](all[mid])>v(all[mid]))swap(seg[now],v);
            if(seg[now].m<v.m)modify(ls,l,mid,s,e,v);
            else modify(rs,mid+1,r,s,e,v);
        }
        else{
            if(mid>=s)modify(ls,l,mid,s,e,v);
            if(mid<e)modify(rs,mid+1,r,s,e,v);
        }
        return;
    }
    ll getval(int now,int l,int r,int p){
        if(l == r)return seg[now](all[p]);
        if(mid>=p)return min(seg[now](all[p]),getval(ls,l,mid,p));
        else return min(seg[now](all[p]),getval(rs,mid+1,r,p));
    }
    void add_line(int s,int e,Line v){
        modify(0,0,all.size()-1,s,e,v);
        return;
    }
    ll getmin(int p){
        return getval(0,0,all.size()-1,p);
    }
#undef ls
#undef rs
#undef mid
};
#undef ll long long
