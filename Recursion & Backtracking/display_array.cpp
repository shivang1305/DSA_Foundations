/*
1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.
3. You are required to print the elements of array from beginning to end each in a separate line.
4. For the above purpose complete the body of displayArr function. Don't change the signature.
*/

#include<iostream>

using namespace std;

void dispArr(int A[], int idx, int N) {
  if(idx == N)
    return;
  cout<<A[idx]<<" ";
  dispArr(A, idx+1, N);
}

//driver code
int main() {
  int N;
  cout<<"Enter the size of array: ";
  cin>>N;
  int Arr[N];
  cout<<"\nEnter the elements of array: ";
  for(int i=0; i<N; i++)
    cin>>Arr[i];

  dispArr(Arr, 0, N); //function call

  return 0;
}
