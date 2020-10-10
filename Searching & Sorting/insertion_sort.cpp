#include <iostream>

using namespace std;

void insertionSort(int A[], int N)
{
  for(int i=1; i<N; i++)
  {
    int j= i-1;
    int temp = A[i];
    while(j>=0 && temp<A[j])
    {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = temp;
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

  insertionSort(Arr, N);

  cout<<"\nSorted array: ";
  for(int i=0; i<N; i++)
    cout<<Arr[i]<<" ";
  return 0;
}
