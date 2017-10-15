#include <iostream>
#include <vector>

using namespace std;


class GrafoTrenes {





}


struct train {
	int num_ciudades;
	int cities[100];
	int times[100];
}

struct linea {
	vector<int> salidas, llegadas;
}

int main(){

	int num_escenarios;

	int num_cuidades, num_trenes;

	linea grafo[100][100];
	map<string, int> cuidades;
	int next;

	string s;
	
	train trains[1000];

	cin >> num_escenarios;
	for (int i=0; i<num_escenarios; i++){

		cin >> num_ciudades;
		next = 0;
		for (int i = 0; i < num_cuidadaes; i++){
			cin >> s;
			cludades.insert(s, next++);
		}
	
		cin >> num_trenes;
		for (int i = 0; i < num_trenes; i++){
			cin >> trains[i].num_ciudades;
			string origen, destino;
			int salida, llegada;
			if (num_cuidades!=0) cin >> salida >> origen;
			for (int j=0; j < trains[i].num_ciudades-2; j++){

				cin >> llegada >> destino;

				grafo[ciudades[origen],ciudades[destino]].salidas.push_back(salida);
				grafo[ciudades[origen],ciudades[destino]].llegadas.push_back(llegada);

				cin >> trains[i].times[j] >> trains[i].cities[j];

				origen = destino;
				salida = llegada;
			}
		}



	}
	



}
