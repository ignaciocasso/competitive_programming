#include <iostream>

using namespace std;

int main() {

  int fibonacci[24]; // Fibonacci sequence 1-24
  fibonacci[0]=1;
  fibonacci[1]=1;
  for (int i=2; i<24; i++) {
    fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
  }

  int primes[30000]; // first n primes lower than Fibonacci(24)
  int next=0;
  for (int i=2; i<=fibonacci[23]; i++) { // F(24)
    bool is_prime=true;
    for (int j=0; j<next; j++) {
      if (i%primes[j]==0){
	is_prime=false;
	break;
      }
    }
    if (is_prime) {
      primes[next]=i;
      next++;
    }
  }

  long long s[50000]; //s(i), for i=2,...,F(24)
  // s(i) = sum p*s(i-p), excepto que algunos se repiten, pero si se calcula en orden creciente de p se arregla
  for (int i=0; i<=fibonacci[23]; i++) s[i]=0;
  s[0]=1;
  for (int j=0; j<next; j++) {
    int p=primes[j];
    for (int i=p; i<=fibonacci[23]; i++) {
      s[i] = (s[i]+p*s[i-p]) % 1000000000;
    }
  }

  long long sol = 0; // sum S(i), i = F(1),...,F(24)
  for (int i=1; i<24; i++) {
    sol = (sol + s[fibonacci[i]]) % 1000000000;
  }

  cout << sol << endl;

  return 0;
}
