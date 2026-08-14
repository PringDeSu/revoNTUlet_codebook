vector<Pt> minkowski(vector<Pt> va, vector<Pt> vb) {
	deque<Pt> a, b;
	for (auto &i: va) a.push_back(i);
	for (auto &i: vb) b.push_back(i);
	Pt head = *min_element(a.begin(), a.end());
	while (a[0] != head) {
		a.push_back(a[0]);
		a.pop_front();
	}
	head = *min_element(b.begin(), b.end());
	while (b[0] != head) {
		b.push_back(b[0]);
		b.pop_front();
	}
	a.push_back(a[0]);
	b.push_back(b[0]);
	a.push_back(a[1]);
	b.push_back(b[1]);
	int p1 = 0, p2 = 0;
	vector<Pt> re;
	while (p1 + 2 < a.size() || p2 + 2 < b.size()) {
		re.push_back(a[p1] + b[p2]);
		ll x = (a[p1+1]-a[p1]) ^ (b[p2+1]-b[p2]);
		if (x >= 0 && p1 + 2 < a.size()) p1 ++;
		if (x <= 0 && p2 + 2 < b.size()) p2 ++;
	}
	return re;
}

