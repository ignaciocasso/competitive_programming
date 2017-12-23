#include <iostream>

using namespace std;

const int MAX_H = 50+2, MAX_W = 50+2, MAX_POINTS = MAX_H*MAX_W; // ]
const int MAX_TREASURES = 10; // ]

struct point {
  int x;
  int y;
};

void shortest_path(int graph[MAX_TREASURES+1][MAX_TREASURES+1], int path[], bool visited[], int n_vertices, int n_visited, int &shortest, int dist_so_far);

int main(){

  int h, w;
  
  cin >> h >> w;
  
  while (h!=0 && w!=0) {
    
    int n_treasures = 0;
    point treasures[MAX_TREASURES];
    
    point landing;
    
    bool mapa[MAX_H][MAX_W];  for (int i=1; i<=h; i++) for (int j=1; j<=w; j++) mapa[i][j] = true;
    
    for (int i=1; i<=h; i++) for (int j=1; j<=w; j++){
      
      char c; cin >> c;
     
      if (c=='@') {landing.x=i; landing.y = j;}
      
      else if (c=='~' || c=='#') mapa[i][j] = false;
      
      else if (c=='*') {
        mapa[i-1][j-1]=false; mapa[i-1][j]=false; mapa[i-1][j+1]=false;
        mapa[i][j-1]=false;   mapa[i][j]=false;   mapa[i][j+1]=false;
        mapa[i+1][j-1]=false; mapa[i+1][j]=false; mapa[i+1][j+1]=false;
      }
      
      else if (c=='!') {
        treasures[n_treasures].x = i;
        treasures[n_treasures].y = j;
        n_treasures++;
      }
    }
    
    int camino_minimo[MAX_TREASURES][MAX_H][MAX_W];
    
    for (int t=0; t<n_treasures; t++) {
      for (int i=0; i<=h+1; i++) for (int j=0; j<=w+1; j++) camino_minimo[t][i][j] = MAX_POINTS;
      int x = treasures[t].x;
      int y = treasures[t].y;
      if (mapa[x][y]) camino_minimo[t][x][y] = 0;
    }
    
    bool estabilizado = false;
    while (!estabilizado) {
    
      estabilizado=true;
    
      for (int t=0; t<n_treasures; t++) for (int i=1; i<=h; i++) for (int j=1; j<=w; j++) {
      
        if (mapa[i][j]) {
        
          int caminos[4] = {camino_minimo[t][i-1][j], camino_minimo[t][i+1][j], camino_minimo[t][i][j+1], camino_minimo[t][i][j-1]};
        
          for (int k=0; k<4; k++) {
            if (caminos[k]+1 < camino_minimo[t][i][j]){
              camino_minimo[t][i][j] = caminos[k] + 1;
              estabilizado = false;
            }
          }
        }
      }
    }
    
    int graph[MAX_TREASURES+1][MAX_TREASURES+1];
    
    for (int t1=0; t1<n_treasures; t1++) for (int t2=t1+1; t2<n_treasures; t2++) {
      
      graph[t1][t2] = camino_minimo[t1][treasures[t2].x][treasures[t2].y];
      graph[t2][t1] = camino_minimo[t2][treasures[t1].x][treasures[t1].y];
    }
    
    bool imposible = false;
    for (int t=0; t<n_treasures; t++) {
      int distancia = camino_minimo[t][landing.x][landing.y];
      graph[t][n_treasures] = distancia;
      graph[n_treasures][t] = distancia;
      if (distancia==MAX_POINTS) imposible = true;
    }
    
    if (imposible) cout << -1 << endl;
    else {
      int path[MAX_TREASURES];
      bool visited[MAX_TREASURES] = { false };
      int shortest = MAX_POINTS*2;
      shortest_path(graph, path, visited, n_treasures, 0, shortest, 0);
      cout << shortest << endl;
    }
    
    cin >> h >> w;
  }

  return 0;
}

void shortest_path(int graph[MAX_TREASURES+1][MAX_TREASURES+1], int path[], bool visited[], int n_vertices, int n_visited, int &shortest, int dist_so_far) {

  if (n_vertices==0) shortest = 0;
  
  else if (n_visited==n_vertices) {
    
    int distancia = dist_so_far + graph[path[n_vertices-1]][n_vertices];
    
    if (distancia < shortest) shortest = distancia;  
  }
  
  else for (int i=0; i<n_vertices; i++) {
    
    if (!visited[i]){
    
      int dist_so_far_new;
      if (n_visited!=0) dist_so_far_new = dist_so_far + graph[path[n_visited-1]][i];
      else              dist_so_far_new = dist_so_far + graph[n_vertices][i];
      
      if (dist_so_far_new<shortest) {
    
        path[n_visited] = i;
        visited[i]=true;
        shortest_path(graph, path, visited, n_vertices, n_visited+1, shortest, dist_so_far_new);
        visited[i]=false;
      }
    }
  }
}
