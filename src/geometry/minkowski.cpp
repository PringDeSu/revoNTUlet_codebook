// needs Point template
template <typename T>
vector<Pt<T>> minkowski(vector<Pt<T>> va,vector<Pt<T>> vb){
    deque<Pt<T>> a,b;
    for(auto &i:va)a.push_back(i);
    for(auto &i:vb)b.push_back(i);
    Pt head = *min_element(a.begin(),a.end());
    while(a[0].x != head.x||a[0].y != head.y){
        a.push_back(a[0]);
        a.pop_front();
    }
    head = *min_element(b.begin(),b.end());
    while(b[0].x != head.x||b[0].y != head.y){
        b.push_back(b[0]);
        b.pop_front();
    }
    a.push_back(a[0]);
    b.push_back(b[0]);
    int p1 = 0,p2 = 0;
    vector<Pt<T>> re;
    while(p1 < a.size()&&p2 < b.size()){
        //cerr<<a.size()<<','<<b.size()<<":"<<p1<<' '<<p2<<endl;
        int dir = 0;
        re.push_back(a[p1]+b[p2]);
        if(p1+1 == a.size())dir = 1;
        else if(p2+1 == b.size())dir = 0;
        else if(((a[p1+1]-a[p1])^(b[p2+1]-b[p2]))>0)dir = 0;
        else dir = 1;
        if(dir == 0)p1++;
        else p2++;
    }
    return re;
}
