#include<iostream>

using namespace std;

int lastOccurence(int A[], int idx, int ele, int N) {
  if(idx > N-1)
    return -1;
  int lisa = lastOccurence(A, idx+1, ele, N);
  if(lisa != -1)
    return lisa;
  else
    if(A[idx] == ele)
      return idx;
    else
      return -1;
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

  cout<<"The last occurence of element of the array: "<<lastOccurence(Arr, 0, ele, N);

  return 0;
}
