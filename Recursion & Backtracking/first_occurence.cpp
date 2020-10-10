#include<iostream>

using namespace std;

int firstOccurence(int A[], int idx, int ele, int N) {
  if(idx > N-1) //base case
    return -1;
  if(A[idx] == ele)
    return idx;
  else
    return firstOccurence(A, idx+1, ele, N); //recurring call
}

int main() {
  int N;
  cout<<"enter the size of array: ";
  cin>>N;
  int Arr[N];
  cout<<"\nEnter the elements of array: ";
  for(int i=0; i<N; i++)
    cin>>Arr[i];

  int ele;
  cout<<"\nEnter the element to be searched for: ";
  cin>>ele;

  cout<<"The first occurence of element of the array: "<<firstOccurence(Arr, 0, ele, N);

  return 0;
}
