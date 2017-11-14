#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

const int MAX_SIZE = 10000000;

int main(){

  string test_case;
  

  while (getline(cin, test_case)){
  
    istringstream input(test_case);

    stack<int> toys_stack;
    int toy=0;
    stack<int> room_left_stack;
    int room_left = MAX_SIZE;

    int n;

    bool matrioshka = true;

    while (input >> n && matrioshka){

      if (n<0) {
	n=-n;
	if (n > room_left) {matrioshka = false;}
	else {
	  toys_stack.push(toy);
	  toy = n;
	  room_left_stack.push(room_left);
	  room_left = n-1;
	}

      }

      else {

	if (n!=toy) {matrioshka = false;}
	else {
	  toy = toys_stack.top();
	  toys_stack.pop();
	  room_left = room_left_stack.top();
	  room_left_stack.pop();
	  room_left-=n;
	}
      }
    }

    if (toy!=0) {matrioshka = false;}

    if (matrioshka) cout << ":-) Matrioshka!" << endl;
    else cout << ":-( Try again." << endl;
  }


  return 0;
}
