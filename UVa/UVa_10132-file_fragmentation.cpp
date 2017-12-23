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
  
  for (int cases=0; cases<n_cases; cases++){
  
    string fragments[MAX_LENGTH][2]; for (int i=0; i<MAX_LENGTH; i++) {fragments[i][0]=""; fragments[i][1]="";}
    
    int min=MAX_LENGTH, max=0;
    
    string frag;
    
    getline(cin, frag);
    
    while (frag!=""){
    
      int length = frag.size();
      
      if (length < min) min = length;
      if (length > max) max = length;
      
      if (fragments[length][0]==""){
        fragments[length][0]=frag;
      }
      else if (fragments[length][1]=="" && fragments[length][0]!=frag) fragments[length][1]=frag;
      
      getline(cin, frag);
    }
    
    string sol[4];
    sol[0] = fragments[min][0]+fragments[max][0];
    sol[1] = fragments[max][0]+fragments[min][0];
    sol[2] = fragments[min][0]+fragments[max][1];
    sol[3] = fragments[max][1]+fragments[min][0];
    
    int length = min+max;
    
    if (cases!=0) cout << endl;
    
    bool solucion = false;
    int k;
    for (k=0; k<4 && !solucion; k++) {
      solucion = true;
      for (int i=1; i<=length/2 && solucion; i++) {
      
        string si1=fragments[i][0], si2=fragments[i][1], sj1=fragments[length-i][0], sj2=fragments[length-i][1], cadena=sol[k];
        
        if (i+i==length) {
          if (si2!="")  sj1=si2;
          else          sj1=si1;
          si2="";
        }
      
        if (si2!=""){
          if      (si1+sj1==cadena && sj2+si2==cadena)  solucion=true;
          else if (si1+sj2==cadena && sj1+si2==cadena)  solucion=true;
          else if (sj1+si1==cadena && si2+sj2==cadena)  solucion=true;
          else if (sj2+si1==cadena && si2+sj1==cadena)  solucion=true;
          else                                          solucion=false;
        }
        else if (si1!="") {
          if (si1+sj1 == cadena || sj1+si1 == cadena) solucion=true;
          else                                        solucion=false;
        }
        else solucion=true;
      }
      
      if (solucion) cout << sol[k] << endl;
    }
  }

  return 0;
}
