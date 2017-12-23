#include <iostream>

using namespace std;

int main() { //buscamos los posibles n,{xi},{yi} tal que 1<=xi,yi<=G, 1<=yn, sum(xi) = sum(yi) = D. (el reparto quedaria x1y1x2y2...xnyn)

  int d,g;  cin >> d >> g;
  
  int cont = 0;
  
  while (d!=-1){
  
    cont++;
  
    int m[34][34] = { 0 }; //m[i][j] es el numero de formas de descomponer i en j sumandos menores o iguales que G
    
    m[0][0] = 1;
    
    for (int i=1; i<=d; i++) for (int j=1; j<=d; j++) {
      m[i][j] = 0;
      for (int k=1; k<=i && k<=g; k++)  m[i][j] += m[i-k][j-1];
    }
    
    long sol = 0;
    
    for (int i=1; i<=d; i++) {//sol = 2*sum(m[d][i]*sum(m[j][i-1]))  (i=1...d, j=0...d-1)
      long sum = 0;
      for (int j=0; j<=d-1; j++) sum += m[j][i-1];
      sol += m[d][i]*sum;
    }
    
    sol *=2; //hemos supuesto que empezamos por una tarea, las configuraciones que empiezan por otra son totalmente simétricas
    
    cout << "Case " << cont << ": " << sol << endl;
  
    cin >> d >> g;
  }

  return 0;
}
