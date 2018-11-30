// Onece we get three numbers in our list not all of them 2, we can get any
// number. Why? Because then you get {n,m,k} -> {n,m,m^i,k-i} -> ... ->
// {n,m,big_enough_number} -> {n,n,m^(j),any_number}. And we can get three
// numbers if we start with k1^k2, not both of them prime


#include <iostream>
#include <math.h>

using namespace std;

int main(){

  long long N = 1000000000000;

  // primes
  bool is_prime[1000001];
  int primes[80000];
  int next=0;
  for (int i=2; i<=1000000; i++) {
    is_prime[i]=true;
    for (int j=0; j<next && primes[j]*primes[j]<=i; j++) {
      if (i%primes[j]==0) {
	is_prime[i]=false;
	break;
      }
    }
    if (is_prime[i]) {
      primes[next]=i;
      next++;
    }
  }

  // squares
  bool sqfs[1000001]; //// 1000^4 is already N
  for (int i=0; i<=1000000; i++) {sqfs[i]=true;}
  for (long long i=2; i<=1000; i++) {
    long long k=i*i;
    while (k<=1000000) {
      sqfs[k]=false;
      k*=i;
    }
  }
   
  // solution
  long long sol = 0;
  for (long long i=2; i<=1000000; i++){
    if (sqfs[i]) {
      int exp=2;
      unsigned long long k=i*i;
      while(k<=N) {
	if(!is_prime[i] || !is_prime[exp]) {sol += k;}
	k*=i;
	exp++;
      }
    }
  }
  
  sol -= 16;

  cout << sol << endl;

  return 0;
}
