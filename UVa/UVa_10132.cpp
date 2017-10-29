#include <iostream>
#include <cstring>

using namespace std;

const int MAX_FILES = 144;    // ]
const int MAX_LENGTH = 256*8; // )

int main(){

  int n_cases;
  
  cin >> n_cases;
  
  string s;
  getline(cin, s);
  getline(cin, s);
  
  for (int i=0; i<n_cases; i++){
  
    string trozos[MAX_FILES*2];
    int n_files = 0;
    
    string trozo, min1, min2, max1, max2;
    int min=MAX_LENGTH, max=0;
    
    getline(cin, trozo);
    
    while (trozo!=""){
    
      trozos[n_files] = trozo;
      n_files++;
      
      int length = trozo.length();
      
      if (length < min) {
        min = length;
        min1 = trozo;
        min2 = trozo;
      }
      else if (length==min && trozo != min1) {
        min2 = trozo;
      }
        
      if (length > max) {
        max = length;
        max1 = trozo;
        max2 = trozo;
      }
      else if (length==max && trozo!=max1) {
        max2 = trozo;
      }
      
      getline(cin, trozo);
    }
    
    string sol[4];
    sol[0] = min1+max1;
    sol[1] = min1+max2;
    sol[2] = max1+min1;
    sol[3] = max2+min1;
    
    int length = min+max;
    
    if (i!=0) cout << endl;
    
    bool solucion = false;
    
    for (int j=0; j<4 && !solucion; j++) {
      solucion = true;
      for (int k=0; k<n_files && solucion; k++) {
        int size = trozos[k].size();
        if (trozos[k] != sol[j].substr(0,size) && trozos[k]!=sol[j].substr(length-size, size)) solucion = false;
      }
      
      if (solucion) cout << sol[j] << endl;
    }
  }

  return 0;
}
