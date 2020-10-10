/*
1. You are given an array(arr) of distinct integers, which is sorted and rotated around an unknown point.
2. You have to find the smallest element in O(logN) time-complexity
*/

#include<iostream>

using namespace std;

int pivotArray(int arr[], int n) {
  int lo = 0;
  int hi = n-1;

  while(lo < hi) {
    int mid = (lo + hi)/2;
    if(arr[mid] < arr[hi]) //rise -> pivot is in lo to mid region
      hi = mid;
    else  //fall -> pivot is in (mid+1) to hi region
      lo = mid + 1;
  }
  return arr[hi];
}

int main() {
  int n;
  cout<<"Enter the size of the array: ";
  cin>>n;

  int arr[n];
  cout<<"\nEnter the elements of the array(in sorted rotated form only): ";
  for(int i=0; i<n; i++)
    cin>>arr[i];

  int pivot = pivotArray(arr, n);

  cout<<"\nPivot is: "<<pivot;
  return 0;
}
