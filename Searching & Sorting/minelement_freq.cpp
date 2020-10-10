#include<iostream>

using namespace std;

void bubbleSort(int A[], int N)
{
  for(int i=0; i<N-1; i++)
  {
    int flag = 0;
    for(int j=0; j<N-1-i; j++)
    {
      if(A[j] > A[j+1])
      {
        flag = 1;
        int t = A[j];
        A[j] = A[j+1];
        A[j+1] = t;
      }
    }
    if(flag == 0)
      break;
  }
}

int main()
{
  int N;
  cout<<"\nEnter the size of array: ";
  cin>>N;

  int Arr[N];
  cout<<"\nEnter the elements in array: ";
  for(int i=0; i<N; i++)
    cin>>Arr[i];

  int K;
  cout<<"\nEnter the frequency: ";
  cin>>K;

  bubbleSort(Arr, N);

  int count, i;
  int x = 0;
  while(true)
  {
    count = 0;
    for(i=x; i<N; i++)
    {
      if(Arr[x] == Arr[i])
        count++;
      else
        break;
    }
    if(count == K)
      break;
    x = i;
  }

  cout<<"\n"<<Arr[x];

  return 0;
}
