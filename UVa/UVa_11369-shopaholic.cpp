#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_ITEMS = 20000;

int main(){

  int n_cases;  cin >> n_cases;

  for (int cases=0; cases<n_cases; cases++) {
    
    int n_items;  cin >> n_items;

    int items[MAX_ITEMS];

    for (int i=0; i<n_items; i++) cin >> items[i];

    sort (items, items+n_items);

    int discount = 0;

    int i;
    for (i=n_items-3; i>=0; i-=3) {discount += items[i];}

    cout << discount << endl;

  }

  return 0;
}
