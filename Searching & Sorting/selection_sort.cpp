#include <iostream>

using namespace std;

void selectionSort(int A[], int N)
{
  for(int i=0; i<N-1; i++)
  {
    int min = i;
    for(int j=i+1; j<N; j++)
    {
      if(A[j] < A[min])
        min = j;
    }
    if(min != i)
    {
      int t = A[min];
      A[min] = A[i];
      A[i] = t;
    }
  }
}

//driver's code
int main()
{
  int N;
  cout<<"Enter the size of array: ";
  cin>>N;
  int Arr[N];
  cout<<"\nEnter the elements: ";
  for(int i=0; i<N; i++)
    cin>>Arr[i];

  selectionSort(Arr, N);

  cout<<"\nSorted array: ";
  for(int i=0; i<N; i++)
    cout<<Arr[i]<<" ";
  return 0;
}
