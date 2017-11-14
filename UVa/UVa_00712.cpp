#include <iostream>

using namespace std;

const int MAX_N = 7;

int main() {

  int n;
  int tree_number=0;

  while (cin >> n && n!=0) {

    cout << "S-Tree #" << ++tree_number << ":" << endl;

    int array[MAX_N];

    for (int i=0; i<n; i++) {
      char c;
      int m;
      cin >> c >> m;
      array[m-1]=n-1-i;
    }

    string distribution;
    cin >> distribution;

    int m;
    cin >> m;
   
    for (int i=0; i<m; i++) {
      string vva;
      cin >> vva;
      int index = 0;
      for (int j=0; j<vva.length(); j++){
	int k= vva[j]=='1' ? 1 : 0;
	index += k*(1<<array[j]);
      }
      cout << distribution[index];
    }
    cout << endl << endl;
  }

  return 0;
}
