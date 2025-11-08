// needs Point.cpp
template<typename T = int>
struct ConvexHull{
	//returns in clockwise direction
	// returns strictly on convex hull
	vector<Pt<T>> solve(vector<Pt<T>> v){
		sort(v.begin(),v.end());
		vector<Pt<T>> u,d;
		for(auto &i:v){
			if (!u.empty() && u.back() == i) continue;
			while(u.size()>1&&((i-u.end()[-1])^(u.end()[-2]-u.end()[-1]))>=0)u.pop_back();
			while(d.size()>1&&((i-d.end()[-1])^(d.end()[-2]-d.end()[-1]))<=0)d.pop_back();
			u.push_back(i);
			d.push_back(i);
		}
		for(int i = 1;i+1<d.size();i++)u.push_back(d.end()[-1-i]);
		return u;
	}
};
