#include <iostream>

using namespace std;

const int MAX_N = 25;

int main() {

  int n_cases;
  cin >> n_cases;
  string s; getline(cin, s); getline(cin, s);
  bool first=true;

  for (int cases=0; cases<n_cases; cases++) {

    int mat[MAX_N][MAX_N] = { 0 }; // in the i-th iteration of the for below, math[j][k]=min {m | (m,k)-(i,j) are the upper left and lower
    int max_area = 0;              // right corners of a rectangle of ones, or -1 if there are none of such rectangles.
    string row; getline(cin, row);
    for (int i=0; row != ""; getline(cin,row), i++) {
      int ones_in_a_row = 0;
      for (int j=0; j<row.length(); j++) {
	if (row[j]=='0') {ones_in_a_row=0;}
	else             {ones_in_a_row++;}
	for (int k=0; k<=j-ones_in_a_row; k++) {
	  mat[j][k]=-1;
	}
	for (int k=j-ones_in_a_row+1; k<=j; k++) {
	  if (mat[j][k]==-1){
	    mat[j][k]=i;
	  }//else it stays the same
	  int area = (i-mat[j][k]+1)*(j-k+1);
	  if (area>max_area){
	    max_area=area;
	  }
	}
      }
    }
    if (!first) {cout << endl;}
    else        {first=false;}
    cout << max_area << endl;
  }

  return 0;
}
