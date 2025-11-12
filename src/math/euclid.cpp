struct euclid{
  ll x, y, g;
  void ec(ll a, ll b){
    // minimum integer solution of "ax+by=g, x>0"
    if(!b) return void((x=1, y=0, g=a));
    ec(b, a%b);
    swap(x, y);
    y -= a/b*x+a/g;
    x += b/g;
  }
  inline euclid(ll a, ll b){
    ec(abs(a), abs(b));
    if(b<0) y = -y;
    if(a<0) x = -x;
  }
};
