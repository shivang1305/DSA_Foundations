#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int partitionArray(int Arr[], int lo, int hi, int pivot) {
  int j = lo;
  for(int i=lo; i<=hi; i++) {
    if(Arr[i] <= pivot) {
      swap(Arr[i], Arr[j]);
      j++;
    }
  }
  return j-1;
}


int quickSelect(int Arr[], int lo, int hi, int k) {
  int pivot = Arr[hi];
  int pi = partitionArray(Arr, lo, hi, pivot);

  if(pi == k-1)
    return Arr[pi];
  else if(pi < k-1)
    quickSelect(Arr, pi+1, hi, k);
  else
    quickSelect(Arr, lo, pi-1, k);
}

int main() {
  int N;
  cout<<"Enter the size of array: ";
  cin>>N;

  int Arr[N];
  cout<<"\nEnter the elements of the array: ";
  for(int i=0; i<N; i++)
    cin>>Arr[i];

  int k;
  cout<<"\nEnter the value of k: ";
  cin>>k;

  cout<<"Kth smallest element is: "<<quickSelect(Arr, 0, N-1, k);

  return 0;
}
