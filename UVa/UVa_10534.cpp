#include <iostream>

using namespace std;

const int MAX_LENGTH = 10000;

int search_index(int array[], int length, int n) {//use binary_search if necesary

  for (int i=0; i<length; i++) {if (array[i]>=n) return i;}

  return length;
}

int main() {

  int input_sequence_length;

  while (cin >> input_sequence_length){

    int input_sequence[MAX_LENGTH];

    for (int i=0; i<input_sequence_length; i++) {cin >> input_sequence[i];}

    int wavio_prefix[MAX_LENGTH]; //size of the longest increasing subsequence that ends in input_sequence[i]
    int wavio_sufix[MAX_LENGTH]; //size of the longest decreasing subsequence that begins in input_sequence[i]

    int subsequences[MAX_LENGTH] = {0}; //subsequences[i] is the smallest final element of all increasing subsequences of length i so far
    int longest_subsequence_length = 0;       //it's easy to see that therefore subsequences is an (strictly) ordered array

    for (int i=0; i<input_sequence_length; i++) {

      int n = input_sequence[i];

      int index = search_index(subsequences, longest_subsequence_length, n);

      if (index==longest_subsequence_length) longest_subsequence_length++;

      subsequences[index]=n;

      wavio_prefix[i]=index;
    }

    longest_subsequence_length = 0;

    for (int i=input_sequence_length-1; i>=0; i--) {

      int n = input_sequence[i];

      int index = search_index(subsequences, longest_subsequence_length, n);

      if (index==longest_subsequence_length) longest_subsequence_length++;

      subsequences[index] = n;

      wavio_sufix[i] = index;
    }

    int longest_wavio_subsequence = 0;
    for (int i=0; i<input_sequence_length; i++) {
      int wavio_length = 1 + 2*min(wavio_prefix[i], wavio_sufix[i]);
      if (wavio_length > longest_wavio_subsequence) longest_wavio_subsequence = wavio_length;
    }

    cout << longest_wavio_subsequence << endl;
  }

  return 0;
}
