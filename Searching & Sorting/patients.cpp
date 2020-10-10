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
  int Vaccine[N], Strength[N];
  cout<<"\nEnter the elements of array: ";
  for(int i=0; i<N; i++)
    cin>>Vaccine[i];
  for(int i=0; i<N; i++)
    cin>>Strength[i];

  //calling the function
  bubbleSort(Vaccine, N);
  bubbleSort(Strength, N);

  int flag = 0;
  for(int i=0; i<N; i++)
  {
    if(Vaccine[i] < Strength[i])
    {
      flag = 1;
      cout<<"\nNo";
      break;
    }
  }
  if(flag == 0)
    cout<<"\nYes";

  return 0;
}
