#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void partitionArray(int Arr[], int N, int pivot) {
  for(int i=0, j=0; i<N; i++) {
    if(Arr[i] <= pivot) {
      swap(Arr[i], Arr[j]);
      j++;
    }
  }
}

void printArray(int Arr[], int N) {
  for(int i=0; i<N; i++)
    cout<<Arr[i]<<" ";
}

int main() {
  int N;
  cout<<"Enter the size of the array: ";
  cin>>N;

  int Arr[N];
  cout<<"\nEnter the elements of array: ";
  for(int i=0; i<N; i++)
    cin>>Arr[i];

  int pivot;
  cout<<"\nEnter the value of pivot: ";
  cin>>pivot;

  partitionArray(Arr, N, pivot);

  printArray(Arr, N);

  return 0;
}
