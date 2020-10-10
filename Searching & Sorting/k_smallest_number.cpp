#include<iostream>

using namespace std;

int main()
{
  int T;
  cout<<"Number of testcases: ";
  cin>>T;
  while(T--)
  {
    //inputs from the user
    int N, Q;
    cout<<"\nEnter the values of N & Q: ";
    cin>>N>>Q;
    int lb, ub;
    cout<<"\nEnter the range of array: ";
    cin>>lb>>ub;
    cout<<"\n";

    //creating the array from the range
    int l = ub-lb+1;
    int Arr[l], j=0;
    for(int i=lb; i<=ub; i++)
    {
      Arr[j] = i;
      j++;
    }

    cout<<"\nEnter the K values: ";
    int q[Q];
    for(int i=0; i<Q; i++)
    {
      cin>>q[i];
      int n = q[i];
      if(n > l)
        cout<<"\n-1";
      else
        cout<<"\n"<<Arr[n-1];
    }
  }
  return 0;
}
