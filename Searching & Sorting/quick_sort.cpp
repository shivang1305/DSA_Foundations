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


void quickSort(int Arr[], int lo, int hi) {
  if(lo >= hi)
    return;

  int pivot = Arr[hi];
  int pi = partitionArray(Arr, lo, hi, pivot);

  quickSort(Arr, lo, pi-1);
  quickSort(Arr, pi+1, hi);

}


//driver code
int main()
{
  int N;
  cout<<"Enter the size of array: ";
  cin>>N;
  int Arr[N];

  cout<<"\nEnter the elements of array:";
  for(int i=0; i<N; i++)
    cin>>Arr[i];

  quickSort(Arr, 0, N-1);

  cout<<"\nSorted array: ";
  for(int i=0; i<N; i++)
    cout<<Arr[i]<<" ";

  return 0;
}
