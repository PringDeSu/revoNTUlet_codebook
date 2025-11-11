typedef pair<int, int> pii;
#define ld double
#define pdd Pt<ld>

ld len(pdd k) {
    return sqrt(k*k);
}
pdd excenter(pdd p0, pdd p1, pdd p2) {
    p1 = p1-p0;
    p2 = p2-p0;
    ld x1 = p1.x, y1 = p1.y, x2 = p2.x, y2 = p2.y;
    ld m = 2.0 * (x1*y2-y1*x2);
    pdd center;
    center.x = (x1*x1*y2 - x2*x2*y1 + y1*y2*(y1-y2)) / m;
    center.y = (x1*x2*(x2-x1) - y1*y1*x2 + x1*y2*y2) / m;
    return center + p0;
}

pdd Minimum_Enclosing_Circle(vector<pdd> dots, ld &r) {
    mt19937 seed(time(0));
    shuffle(dots.begin(), dots.end(), seed);
    pdd cent;
    cent = dots[0], r = 0;
    for(int i = 1;i<dots.size();i++) {
        if (len(dots[i]-cent) > r) {
            cent = dots[i], r = 0;
            for(int j = 0;j<i;j++) {
                if (len(dots[j]-cent) > r) {
                    cent = (dots[i]+dots[j]);
                    cent.x /= 2, cent.y /= 2;
                    r = len(dots[i]-cent);
                    for(int k = 0;k<j;k++) {
                        if(len(dots[k]-cent) > r) {
                            cent = excenter(dots[i], dots[j], dots[k]);
                            r = len(dots[k]-cent);
                        }
                    }
                }
            }
        }
    }
    return cent;
}
