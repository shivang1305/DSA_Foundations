/*
to create a max heap from a given array (bugs)
*/

#include<iostream>

using namespace std;

void maxHeapInsertion(int A[], int N, int value){
  N = N+1;
  A[N] = value;
  int i = value;

  while(i > 1) {
    int parent = i/2;
    if(A[parent] < A[i]){
      int t = A[parent];
      A[parent] = A[i];
      A[i] = t;
      i = parent;
    }
    else
      return;
  }
}

void heapInsertion(int A[], int N) {
  for(int i=N/2; i>=1; i--)
    maxHeapInsertion(A, N, i);
}

int main()
{
  int N;
  cout<<"Enter the size of array: ";\
  cin>>N;

  int Arr[N];

  cout<<"\nEnter the elements of array: ";
  for(int i=0; i<N; i++)
    cin>>Arr[i];

  heapInsertion(Arr, N);

  cout<<"\nArray after insertion in max heap";
  for(int i=0; i<N; i++)
    cout<<Arr[i]<<" ";

  return 0;
}
