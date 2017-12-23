#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {return (b==0 ? a : gcd(b, a%b));}
int gcd(int a, int b, int c) {return gcd(a, gcd(b,c));}

int main(){ //Vease el vídeo "All possible pythagorean triples, visualized" de 3blue1brown para buscar inspiración

  int n;
  while (cin >> n){
  
    int num_ternas = 0;
    int used_numbers[1000001] = { 0 };
    int num_lonely_numbers = n;
  
    int x,y,z;
    int fin = sqrt(2*n);
    for (int i=1; i<fin; i++){
      for (int j = i+1; j<fin; j++){
        if (gcd(i,j)==1){
          x = j*j-i*i;
          y = 2*i*j;
          z = i*i+j*j;
          if (x%2==0) {
            x/=2;
            y/=2;
            z/=2;
          }
          if (z <= n && x<y){
            num_ternas++;
            for (int i=1; i<=n/z; i++){
              if (used_numbers[z*i]==0) {used_numbers[z*i]=1; num_lonely_numbers--;}
              if (used_numbers[x*i]==0) {used_numbers[x*i]=1; num_lonely_numbers--;}
              if (used_numbers[y*i]==0) {used_numbers[y*i]=1; num_lonely_numbers--;}
            }
          }
        }
      }
    }
  
    cout << num_ternas << " " << num_lonely_numbers << endl;
  }
  
  return 0;
}
