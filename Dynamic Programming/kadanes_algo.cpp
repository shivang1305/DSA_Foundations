/*
Kadane algorithm is based on sub-arrays i.e finding max sum subarray from the given array in O(n) time complexity.
*/

#include <iostream>
#include <climits>

using namespace std;

int maxSubarray(int A[], int N) {
  int max = INT_MIN, sum = 0;
  for(int i=0; i<N; i++) {  //time complexity = O(N)
    sum += A[i];
    if(sum > max)
      max = sum;
    if(sum < 0)
      sum = 0;
  }
  return max;
}

//Driver's code
int main() {
  int N;
  cout<<"Enter the size of array: ";
  cin>>N;

  int Arr[N];
  cout<<"\nEnter the elements of array: ";
  for(int i=0; i<N; i++)
    cin>>Arr[i];

  int result = maxSubarray(Arr, N);
  cout<<"\nMaximum contiguous sum is: "<<result;
  return 0;
}
