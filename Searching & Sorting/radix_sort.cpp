#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void countSort(int arr[], int n, int exp) {
  //creating the frequency array
  int freq[10] = {0};
  for(int i=0; i<n; i++)
    freq[arr[i] / exp % 10]++;

  //Creating the prefix sum array
  for(int i=1; i<=9; i++)
    freq[i] += freq[i-1];

  //creating the sorted array
  int sarr[n] = {0};
  for(int i=n-1; i>=0; i--)
    sarr[--freq[arr[i] / exp % 10]] = arr[i];  //to mainting the stablity of the sort

  //replacing the array
  for(int i=0; i<n; i++)
    arr[i] = sarr[i];
}

void radixSort(int arr[], int n) {
  //obtaing the max element of the array
  int ma = INT_MIN;
  for(int i=0; i<n; i++)
    ma = max(ma, arr[i]);

  //call the sount sort function on the basis of no of digits of the max element (ones, tens, hundreds etc)
  int exp = 1;
  while(exp <= ma) {
    countSort(arr, n, exp);
    exp = exp * 10;
  }

  //printing the array
  for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
}


int main() {
  int n;
  cout<<"Enter the size of array: ";
  cin>>n;

  int arr[n];
  cout<<"\nEnter the elements of the array: ";
  for(int i=0; i<n; i++)
    cin>>arr[i];

  radixSort(arr, n);

  return 0;
}
