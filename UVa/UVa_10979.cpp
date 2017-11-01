#include <iostream>

using namespace std;

const int MAX_SEGMENTS = 10; // ]

struct t_point{
  double x;
  double y;
};

class Segment {

  public:
  
    t_point p1;
    t_point p2;
    
    double a,b,c; //ax + by + c = 0
    
    Segment(int x1, int y1, int x2, int y2) {
    
      a = y2-y1;
      b = -(x2-x1);
      c = -(y2-y1)*x1 + (x2-x1)*y1;
    
      if (x1<x2)      {p1.x = x1; p1.y = y1; p2.x = x2; p2.y = y2;} //We keep the two points ordered (lexicographically)
      else if (x1>x2) {p1.x = x2; p1.y = y2; p2.x = x1; p2.y = y1;}
      else if (y1<y2) {p1.x = x1; p1.y = y1; p2.x = x2; p2.y = y2;}
      else if (y1>y2) {p1.x = x2; p1.y = y2; p2.x = x1; p2.y = y1;}
      else {}
    }
   
    bool colinear(Segment other){//says if this segment is in the same line as another
    
      return (a*other.b==b*other.a && a*other.c==c*other.a && b*other.c==c*other.b);
    }
    
    bool intersects(Segment other) {//says if this segment intersects with another
    
      if (!colinear(other)){
      
        if (((other.p1.x*a + other.p1.y*b + c)*(other.p2.x*a + other.p2.y*b + c) <= 0) &&
           ((p1.x*other.a + p1.y*other.b + other.c)*(p2.x*other.a + p2.y*other.b + other.c) <= 0)) {
        
          return true;
        }
      }
      else if (p1.x!=p2.x){
        if (p2.x >= other.p1.x && p1.x <= other.p2.x) return true;
      }
      else {
        if (p2.y >= other.p1.y && p1.y <= other.p2.y) return true;
      }
      
      return false;
    }
    
    void merge(Segment other) {//merges this segment with another (it assumes they are colinear and intersect)
    
      if (p1.x!=p2.x) {
        if (p1.x > other.p1.x) {p1.x = other.p1.x; p1.y = other.p1.y;}
        if (p2.x < other.p2.x) {p2.x = other.p2.x; p2.y = other.p2.y;}
      }
      else {
        if (p1.y > other.p1.y) {p1.x = other.p1.x; p1.y = other.p1.y;}
        if (p2.y < other.p2.y) {p2.x = other.p2.x; p2.y = other.p2.y;}
      }
    }
    
    t_point* intersection(Segment other) {//returns the intersection of this segment and another, if exists and is unique
    
      if (colinear(other) || !intersects(other)) return NULL;
      
      else {
      
        t_point* p = new t_point;
      
        double det = a*other.b - b*other.a;
        
        p->x = -(c*other.b - b*other.c) / det;
        p->y = -(a*other.c - c*other.a) / det;
        
        return p;
      }
    }
};


int main(){

  int n;
  while (cin >> n) {
  
    int n_triangles = 0;
    
    Segment* segments[10];
    
    t_point* intersections[10][10];
    
    for (int i=0; i<n; i++) {
      double x1,y1,x2,y2;  cin >> x1 >> y1 >> x2 >> y2;      
      Segment* segment = new Segment(x1,y1,x2,y2);
      segments[i] = segment;
    }
    
    for (int j=0; j<n; j++) for (int i=0; i<j; i++) {//colinear and intersecting segments are merged
   
      if (segments[i]->colinear(*segments[j]) && segments[i]->intersects(*segments[j])){
        segments[i]->merge(*segments[j]);
        delete(segments[j]);
        for (int k=j; k<n; k++) {segments[k]=segments[k+1];}
        
        n--; i=-1; j=-1;
      }
    }
    
    for (int k=0; k<n; k++) for (int j=0; j<k; j++){//calculates number of triangles
    
      intersections[j][k] = segments[j]->intersection(*segments[k]);
      
      if (intersections[j][k]!=NULL){
        for (int i=0; i<j; i++){ 
          if (intersections[i][j]!=NULL && intersections[i][k]!=NULL) {
            if (!(intersections[i][j]->x == intersections[i][k]->x && intersections[i][j]->y == intersections[i][k]->y)){
              n_triangles++;
            }
          }
        }
      }
    }
    
    cout << n_triangles << endl;
    
    for (int i=0; i<n; i++) delete(segments[i]);
  }
  
  return 0;
}
