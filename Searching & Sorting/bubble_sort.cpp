#include <iostream>

using namespace std;

//bubble sort function
void bubbleSort(int Arr[], int N)
{
  int flag;
  for(int i=0; i<N-1; i++) //for every pass
  {
    flag = 0;
    for(int j=0; j<N-1-i; j++) //to decrease the number of comparisions in each pass
    {
      if(Arr[j] > Arr[j+1])
      {
        //swap the values
        flag = 1;  //change the flag value
        int t = Arr[j];
        Arr[j] = Arr[j+1];
        Arr[j+1] = t;
      }
    }
    if(flag == 0)
      break;
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

  //calling the function
  bubbleSort(Arr, N);

  cout<<"\nSorted array is: ";
  for(int i=0; i<N; i++)
    cout<<Arr[i]<<" ";

  return 0;
}
