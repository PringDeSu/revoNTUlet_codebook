template<typename T = int>
struct Pt{
  T x,y;
  Pt (T xx = (T)(0),T yy = (T)(0)):x(xx),y(yy){}
  Pt operator+(Pt b)const{return Pt(x+b.x,y+b.y);}
  Pt operator-(Pt b)const{return Pt(x-b.x,y-b.y);}
  T operator*(Pt b)const{return x*b.x+y*b.y;}
  T operator^(Pt b)const{return x*b.y-y*b.x;}
  T operator/(Pt b)const{return x*b.y-y*b.x;}
  auto operator<=>(const Pt& b) const = default; // since C++20

  friend int dir(Pt a,Pt b){//returns sign(a ^ b)
    auto re = a ^ b;
    return re<0?-1:re>0?1:0;
  }
  friend bool onseg(Pt x,Pt s,Pt e){
    if(((e-x)^(s-x)) != 0)return false;
    else if((s-x)*(e-x)>0)return false;
    return true;
  }
  friend int intersect(Pt s1,Pt e1,Pt s2,Pt e2){//returns 0 if doesn't intersect,1 if intersect,2 if on line
    if(onseg(s1,s2,e2)||onseg(e1,s2,e2)||onseg(s2,s1,e1)||onseg(e2,s1,e1))return 2;
    if(dir(s1-s2,e2-s2)*dir(e1-s2,e2-s2)<0&&dir(s2-s1,e1-s1)*dir(e2-s1,e1-s1)<0)return 1;
    return 0;
  }

};
