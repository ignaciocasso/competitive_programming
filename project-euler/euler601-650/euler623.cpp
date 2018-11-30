#include <iostream>

using namespace std;

int main(){

  int N = 2000;
  int M=N/5;
  unsigned long long mat[N+1][M+1];
  int p = 1000000007;

  int n,m;
  cout << "n: ";
  cin >> n;
  m = n/5;

  for (int j=0; j<=m; j++){
    mat[0][j] = 0;
  }

  for (int j=0; j<=m; j++) {
    mat[1][j]=j;
  }

  for (int i=2; i<=n; i++) {
    for (int j=0; j<=m; j++){
      mat[i][j]=0;
      if (i>5) {mat[i][j] += mat[i-5][j+1];}
      for (int k=1; k<i-2; k++) {
	mat[i][j] = (mat[i][j] + mat[k][j]*mat[i-2-k][j]) % p;
      }
    }
  }

  long sol=0;
  for (int i=0; i<=n; i++) {
    sol = (sol + mat[i][0]) % p;
  }

  cout << sol << endl;
	
  return 0;
}
