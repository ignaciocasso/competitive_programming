#include <iostream>
#include <stack>

using namespace std;

int main(){

	int alturas[10000] = { 0 };

	int l,h,r;

	while (cin >> l >> h >> r){

		for (int i=l; i<r; i++) {
			if (h > alturas[i]) alturas[i] = h;
		}
	}

	int altura = 0;
	bool first = true;
	for (int i=0; i<10000; i++){

		if (alturas[i] != altura){
			altura = alturas[i];
			if (!first) cout << " ";
			cout << i << " " << altura;
			first = false;
		}
	}
	cout << endl;
	
	return 0;
}
