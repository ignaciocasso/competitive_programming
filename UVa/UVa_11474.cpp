#include <iostream>
#include <cmath>

using namespace std;

const int MAX_TREES = 100; // )
const int MAX_DOCTORS = 10; // ]
const int MAX_BRANCHES = 10; // )

struct t_point {
  int x;
  int y;
};

struct t_tree {
  int n_branches;
  t_point branches[MAX_BRANCHES];
};

struct t_connected_component {
  t_connected_component* parent;
};

t_connected_component* get_root(t_connected_component &connected_component){
  t_connected_component* cc = &connected_component;
  while (cc->parent != NULL) {cc = cc->parent;}
  if (&connected_component!=cc) connected_component.parent=cc;
  return cc;
}

bool connected(t_tree t1, t_tree t2, double dist);
bool connected(t_point p, t_tree t, double dist);
double distance(t_point p1, t_point p2){
  return sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
};

int main() {

  int t;  cin >> t;
  
  for (int cases=0; cases<t; cases++) {

    int n_trees ,n_doctors, dist_trees, dist_doctors;     cin >> n_trees >> n_doctors >> dist_trees >> dist_doctors;
    
    t_connected_component connected_component[MAX_TREES] = { };
    for (int i=0; i<n_trees; i++) connected_component[i].parent=NULL;
    
    t_tree trees[MAX_TREES];  
    t_point doctors[MAX_DOCTORS];
    
    for (int i=0; i<n_doctors; i++)   cin >> doctors[i].x >> doctors[i].y;
    
    for (int i=0; i<n_trees; i++) {
    
      cin >> trees[i].n_branches;
      
      for (int j=0; j<trees[i].n_branches; j++)   cin >> trees[i].branches[j].x >> trees[i].branches[j].y;
    }
    
    for (int j=0; j<n_trees; j++) {
      for (int i=0; i<j; i++){
        if (connected(trees[i], trees[j], dist_trees)) {
          if (connected_component[j].parent==NULL) connected_component[j].parent = &connected_component[i];
          else {
            t_connected_component* root_i = get_root(connected_component[i]);
            t_connected_component* root_j = get_root(connected_component[j]);
            if (root_i != root_j) root_j->parent = root_i;
          }
        }
      }
    }
    
    bool doctor_found = false;
    for (int i=0; i<n_doctors && !doctor_found; i++) for (int j=0; j<n_trees && !doctor_found; j++) {
    
      if (connected(doctors[i], trees[j], dist_doctors) && get_root(connected_component[j]) == get_root(connected_component[0])){
        doctor_found = true;
      }
    }
    
    if (doctor_found) cout << "Tree can be saved :)" << endl;
    else              cout << "Tree can't be saved :(" << endl;
  }

  return 0;
}

bool connected(t_tree t1, t_tree t2, double dist){

  for (int i=0; i<t1.n_branches; i++) for (int j=0; j<t2.n_branches; j++) {
      if (::distance(t1.branches[i], t2.branches[j]) <= dist)  return true; 
  }

  return false;
}

bool connected(t_point p, t_tree t, double dist){

  for (int i=0; i<t.n_branches; i++) {
    if (::distance(t.branches[i], p) <= dist)  return true;
  }
  return false;
}
