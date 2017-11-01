#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100000; // ]
const int MOD = 1000007;

int main(){

  int n_cases;  cin >> n_cases;
  
  for (int cases=0; cases<n_cases; cases++){
  
    int k, c, n, a0;  cin >> k >> c >> n >> a0;
    
    unsigned long long int values[MAX_N];
    
    values[0]=a0;
    
    for (int i=1; i<n; i++) { 
      values[i] = (k*values[i-1] + c)%1000007;
    }
  
    sort(values, values + n);
    
    unsigned long long int sum=0;
    
    for (int i=0; i<n; i++) { 
      sum += (2*i-n+1)*values[i];
    }
    
    cout << "Case " << cases+1 << ": " << sum << endl;
  }
  return 0;
}
