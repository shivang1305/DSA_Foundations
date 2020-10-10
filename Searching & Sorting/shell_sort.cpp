#include<iostream>

using namespace std;

void shellSort(int A[], int N)
{
  int gap;
  for(gap=N/2; gap>=1; gap=gap/2){
    for(int j=gap; j<N; j++){
      for(int i=j-gap; i>=0; i=i-gap){  //to compare forwards and backwards both
        if(A[i] < A[i+gap])
          break;
        else{
          int t = A[i];
          A[i] = A[i+gap];
          A[i+gap] = t;
        }
      }
    }
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

  shellSort(Arr, N);

  cout<<"\nSorted Array: ";
  for(int i=0; i<N; i++)
    cout<<Arr[i]<<" ";

  return 0;
}
