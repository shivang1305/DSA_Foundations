// #include<iostream>
//
// using namespace std;
//
// void countingSort(int A[], int N, int k)
// {
//   int Count[k+1];
//   int B[N];
//   for(int i=0; i<=k; i++)
//     Count[i] = 0;
//   for(int i=0; i<N; i++)
//     Count[A[i]]++;
//   for(int i=1; i<=k; i++)
//     Count[i] += Count[i-1];
//   for(int i=N-1; i>=0; i--)
//     B[--Count[A[i]]] = A[i]; //pre-increament here is important
//   for(int i=0; i<N; i++)
//     A[i] = B[i];
// }
//
// int main()
// {
//   int N;
//   cout<<"Enter the size of array: ";
//   cin>>N;
//
//   int Arr[N];
//   cout<<"\nEnter the elements of array: ";
//   for(int i=0; i<N; i++)
//     cin>>Arr[i];
//
//   //to find the range of array
//   int max = Arr[0];
//   for(int i=0; i<N; i++)
//   {
//     if(max < Arr[i])
//       max = Arr[i];
//   }
//
//   countingSort(Arr, N, max);
//
//   cout<<"\nSorted Array: ";
//   for(int i=0; i<N; i++)
//     cout<<Arr[i]<<" ";
//
//   return 0;
// }


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void countSort(int arr[], int n, int mi, int ma) {
  //creating the frequency array
  int freq[ma - mi + 1] = {0};
  for(int i=0; i<n; i++)
    freq[arr[i] - mi]++;

  //Creating the prefix sum array
  for(int i=1; i<=ma - mi; i++)
    freq[i] += freq[i-1];

  //creating the sorted array
  int sarr[n] = {0};
  for(int i=n-1; i>=0; i--) {
    sarr[--freq[arr[i] - mi]] = arr[i];  //to mainting the stablity of the sort54
  }

  //print the sorted array
  cout<<"\nSorted Array: ";
  for(int i=0; i<n; i++)
    cout<<sarr[i]<<" ";

}

int main() {
  int n;
  cout<<"Enter the size of the array: ";
  cin>>n;

  int arr[n];
  cout<<"\nEnter the elements of the array: ";

  //Obtain the max and min value to get the range of the elements of the array
  int ma = INT_MIN;
  int mi = INT_MAX;

  for(int i=0; i<n; i++) {
    cin>>arr[i];
    ma = max(ma, arr[i]);
    mi = min(mi, arr[i]);
  }

  countSort(arr, n, mi, ma);

  return 0;
}
