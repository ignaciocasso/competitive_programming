#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	//La ecuación que se cumple es n^2 = (m^2 + m)/2, siendo n el numero de la casa y m el numero de casas
	
	int encontrados = 0;
	
	unsigned long int n=2,m=2;

	unsigned long int lado_izquierdo=4, lado_derecho=3;
	
	while (encontrados!=10){
		
		if (lado_derecho > lado_izquierdo){	//n++, lado_izquierdo=n^2
			lado_izquierdo += 2*n + 1;
			n++;
		}
		else if (lado_derecho < lado_izquierdo){ //m++, lado_derecho = (m^2 + m)/2 = 1+2+...+m
			m++;
			lado_derecho += m;
		}
		else {
			encontrados++;
			cout << setw(10) << n << setw(10) << m << endl;

			m++;
			lado_derecho += m;
		}
	}
}
