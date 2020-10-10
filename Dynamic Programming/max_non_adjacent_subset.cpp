/*
1. You are given a number n, representing the count of elements.
2. You are given n numbers, representing n elements.
3. You are required to find the maximum sum of a subsequence with no adjacent elements.
*/

#include<iostream>

using namespace std;

void maxNonAdjacentSum(int arr[], int N) {
  int incl = arr[0];
  int excl = 0;

  for(int i=1; i<N; i++) {
    int new_incl = excl + arr[i];
    int new_excl = max(incl, excl);

    incl = new_incl;
    excl = new_excl;
  }

  cout<<max(incl, excl);
}

int main() {
  int N;
  cout<<"Enter the number of elements: ";
  cin>>N;

  int arr[N];
  cout<<"Enter the elements of array: ";
  for(int i=0; i<N; i++)
    cin>>arr[i];

  maxNonAdjacentSum(arr, N);

  return 0;
}
