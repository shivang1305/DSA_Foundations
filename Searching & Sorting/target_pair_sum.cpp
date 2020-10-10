/*
1. You are given an array(arr) of distinct integers and a target.
2. You have to print all the pairs having their sum equal to the target.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void targetSumPair(int arr[], int n, int tar) {
  sort(arr, arr+n);

  int l = 0;
  int r = n-1;

  while(l < r) {
    if(arr[l]+arr[r] > tar)
      r--;
    else if(arr[l]+arr[r] < tar)
      l++;
    else {
      cout<<arr[l]<<"-"<<arr[r]<<endl;
      l++;
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

  int tar;
  cout<<"\nEnter the target value: ";
  cin>>tar;

  targetSumPair(arr, n, tar);

  return 0;
}
