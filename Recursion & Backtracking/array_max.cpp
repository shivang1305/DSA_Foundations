#include<iostream>

using namespace std;

int maxOfArray(int A[], int idx, int N) {
  if(idx == N-1) //base case
    return A[idx];
  int misa = maxOfArray(A, idx+1, N);
  if(misa > A[idx])
    return misa;
  else
    return A[idx];
}

int main() {
  int N;
  cout<<"enter the size of array: ";
  cin>>N;
  int Arr[N];
  cout<<"\nEnter the elements of array: ";
  for(int i=0; i<N; i++)
    cin>>Arr[i];

  cout<<"The max element of the array: "<<maxOfArray(Arr, 0, N);

  return 0;
}
