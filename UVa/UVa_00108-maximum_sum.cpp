#include <iostream>

using namespace std;

int main(){

  int mat[101][101];
  int sumas[101][101] = { 0 };

  int n;
  while (cin >> n) {
  
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cin >> mat[i][j];
    
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) {
      sumas[i][j] = sumas[i-1][j] + sumas[i][j-1] - sumas[i-1][j-1] + mat[i][j];
    }
    
    int max_sum = mat[1][1];
    
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) for (int k=i; k<=n; k++) for (int l=j; l<=n; l++) {
    
      int sum = sumas[i-1][j-1] + sumas[k][l] - sumas[k][j-1] - sumas[i-1][l];
       
      if (sum > max_sum)    max_sum = sum;
    }
    
    cout << max_sum << endl;
  }


  return 0;
}
