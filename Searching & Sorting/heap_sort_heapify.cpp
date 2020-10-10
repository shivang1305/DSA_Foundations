#include<iostream>

using namespace std;

void Heapify(int A[], int N, int i)
{
  int largest = i;
  int l = (2*i) + 1;
  int r = (2*i) + 2;

  while(l<N && A[l]>A[largest])
    largest = l;
  while(r<N && A[r]>A[largest])
    largest = r;

  if(largest != i)
  {
    int t = A[largest];
    A[largest] = A[i];
    A[i] = t;
    Heapify(A, N, largest);
  }
}

void heapSort(int A[], int N)
{
  //for creating a max heap
  for(int i=(N/2)-1; i>=0; i--)
    Heapify(A, N, i);
    //for deletion from max heap to build a sorted array
  for(int i=N-1; i>0; i--)
  {
    int t = A[i];
    A[i] = A[0];
    A[0] = t;
    Heapify(A, i, 0);
  }
}

int main()
{
  int N;
  cout<<"Enter the size of array: ";
  cin>>N;

  int Arr[N];
  cout<<"\nEnter the elements of array: ";
  for(int i=0; i<N; i++)
    cin>>Arr[i];

  heapSort(Arr, N);

  cout<<"\nSorted Array: ";
  for(int i=0; i<N; i++)
    cout<<Arr[i]<<" ";

  return 0;
}
