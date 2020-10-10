#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*
DUTCH NATIONAL FLAG ALGORITHM
*/

void sort012(int arr[], int n) {
  int l = 0;
  int r = n-1;
  int m = 0;

  while(m <= r) {
    if(arr[m] == 0){
      swap(arr[l], arr[m]);
      l++;
      m++;
    }else if(arr[m] == 1)
      m++;
    else if(arr[m] == 2){
      swap(arr[m], arr[r]);
      r--;
    }
  }
}

int main() {
  int n;
  cout<<"Enter the size of the array: ";
  cin>>n;

  int arr[n];
  cout<<"\nEnter the elements of the array: ";
  for(int i=0; i<n; i++)
    cin>>arr[i];

  sort012(arr, n);

  //sorted array
  for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
  return 0;
}
