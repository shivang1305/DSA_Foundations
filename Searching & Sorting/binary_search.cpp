#include <iostream>

using namespace std;

int binarySearch(int A[], int N, int num)
{
  //for traversal of array multiple times
  int left = 0;
  int right = N-1;
  int mid;

  while(left <= right)
  {
    mid = (left+right)/2;
    if(num == A[mid])
      return mid;
    else if(num > A[mid])
      left = mid+1;
    else
      right = mid-1;
  }
  return -1;
}

int main()
{
  int N;
  cout<<"Enter the size of array: ";
  cin>>N;

  //declaration of array
  int Arr[N];

  cout<<"\nEnter the elements of array (in sorted form only): ";
  for(int i=0; i<N; i++)
    cin>>Arr[i];

  cout<<"\nYour array is: ";
  for(int i=0; i<N; i++)
    cout<<Arr[i]<<" ";

  //number to be searched
  int num;
  cout<<"\nEnter the element to be searched: ";
  cin>>num;

  int result = binarySearch(Arr, N, num);

  if(result == -1)
    cout<<"\nElement not found";
  else
    cout<<"\nElement found at index "<<result;

  return 0;
}
