#include <iostream>

using namespace std;

//linear search function
int linearSearch(int A[], int N, int num)
{
  int i;
  for(i=0; i<N; i++) //traversing the whole array
  {
    if(A[i] == num)
      return i;
  }
  if(i == N)  //if whole array is traversed & element is still not found
    return -1;
}

int main()
{
  int N;
  cout<<"Enter the size of array: ";
  cin>>N;

  //declaration of array
  int Arr[N];

  cout<<"\nEnter the elements of array: ";
  for(int i=0; i<N; i++)
    cin>>Arr[i];

  cout<<"\nYour array is: ";
  for(int i=0; i<N; i++)
    cout<<Arr[i]<<" ";

  //number to be searched
  int num;
  cout<<"\nEnter the element to be searched: ";
  cin>>num;

  int result = linearSearch(Arr, N, num);

  if(result == -1)
    cout<<"\nElement not found";
  else
    cout<<"\nElement found at index "<<result;

  return 0;
}
