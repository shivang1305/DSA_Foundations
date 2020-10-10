#include<iostream>

using namespace std;

void mergeArray(int A[], int lb , int mid, int ub)
{
  int B[ub];
  int i = lb, k = lb, j = mid+1;
  while(i<=mid && j<=ub)
  {
    if(A[i] < A[j])
    {
      B[k] = A[i];
      i++;
    }
    else
    {
      B[k] = A[j];
      j++;
    }
    k++;
  }
  if(i<=mid)
  {
    while(i<=mid)
    {
      B[k] = A[i];
      i++;
      k++;
    }
  }
  else
  {
    while(j<=ub)
    {
      B[k] = A[j];
      j++;
      k++;
    }
  }
  for(k=lb; k<=ub; k++)
    A[k] = B[k];
}

void mergeSort(int A[], int lb, int ub)
{
  int mid;
  if(lb < ub)
  {
    mid = (lb + ub)/2;
    mergeSort(A, lb, mid);
    mergeSort(A, mid+1, ub);
    mergeArray(A, lb, mid, ub);
  }
}

//driver's code
int main()
{
  int N;
  cout<<"Enter the size of array: ";
  cin>>N;
  int A[N];

  cout<<"\nEnter the elements of array: ";
  for(int i=0; i<N; i++)
    cin>>A[i];

  mergeSort(A, 0, N-1);

  cout<<"\nSorted array: ";
  for(int i=0; i<N; i++)
    cout<<A[i]<<" ";

  return 0;
}
