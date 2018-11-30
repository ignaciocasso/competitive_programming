/*
  All chains sequence are periodic with a period of {a,a^e,...,a^(e^(r-1))}.
  Proof:
      Let a, be the maximum element in the sequence and b another element with n> (b^e) > n/2 ( iff the sequence is as stated above, a is the only one).
      Then c=n-b^e=(n-a^e)+(a^e-b^e) > 0 + a^e-(a-1)^e >= 2*a + 1 > 2*c+1 > c, where we have used (a>b) => b^k <= (a-1)^k, and (a^k)-(a-1)^k >= 2*a +1, and it's equal iff k=2 (induction).
  So we only have to find solutions to a^(e^r) + a <= N and count how many sequences generates each of those
  Each of those generates r sequences of length r with the same cycle, but different starting point plus probably r-1 sequences that start with a but have a smaller cycle
 */


#include <iostream>
#include <math.h>

using namespace std;



int main() {

  long long M=1000000;
  long long N=M*M*M;
  cout << "N: ";
  cin >> N;
  //N=1000000;


  int limit;
  long long max[100]; // kth root of N
  for (int i=2; i<100; i++) {
    max[i] = pow(N,1.0/i);
    if (pow(max[i],i)+max[i] > N) {max[i]--;}
    if (max[i]==1) {limit=i; break;}
  }

  long long sol=0;
  for (int e=2; e<limit; e++) {
    int r=1;
    int k=e;
    while (k<limit) {
      sol += (2*r-1)*(max[k]-1);
      int s=1;
      int m=pow(max[k],e);
      while (s<r) {
	if (pow(m,pow(e,r-s)) + m > N) {sol--;} //a^(e^r) + a^(e^(r-s)) > N, so no sequence (a,a^e,...,a^(r-s),..,a^r-1,a^(r-s),..). It is impossible for a<b, proof below (1)
	s++;
	m=pow(m,e);
      }
      r++;
      k*=e;
    }
}

  cout << sol << endl;
  
  return 0; 
}

/*
(1)
Veamos que (a-1)^(e^r) + (a-1)^(e^(r-1)) <= a^(e^r) <= a^(e^r) + a <= N, o lo que es lo mismo, que a^(e^r) - (a-1)^(e^r) >= (a-1)^(e^(r-1)).
Cogiendo b=a^(e^(r-1)), c=(a-1)^(e^(r-1)), nos queda b^e-c^e >= b^2-c^2 >= b^2-(b-1)^2 >= b >= c
*/
