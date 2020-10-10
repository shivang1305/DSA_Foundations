#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main() {
  int n;
  cout<<"Enter the size of array: ";
  cin>>n;

  int arr[n];
  cout<<"\nEnter the elements of the array: ";
  for(int i=0; i<n; i++)
    cin>>arr[i];


  //right boundary
  vector<int> rb;
  rb.assign(n, n);

  stack<int> str;
  str.push(0);

  for(int i=1; i<n; i++) {
    while(!str.empty() && arr[i] < arr[str.top()]) {
      rb[str.top()] = i;
      str.pop();
    }
    str.push(i);
  }

  // for(int i=0; i<n; i++)
  //   cout<<rb[i]<<" ";
  // cout<<endl;

  //left boundary
  vector<int> lb;
  lb.assign(n, -1);
  lb[0] = -1;

  stack<int> stl;
  stl.push(n-1);

  for(int i=n-2; i>=0; i--) {
    while(!stl.empty() && arr[i] < arr[stl.top()]) {
      lb[stl.top()] = i;
      stl.pop();
    }
    stl.push(i);
  }

  // for(int i=0; i<n; i++)
  //   cout<<lb[i]<<" ";

  int maxArea = INT_MIN;
  for(int i=0; i<n; i++) {
    int area = arr[i] * (rb[i] - lb[i] - 1);
    maxArea = max(maxArea, area);
  }

  cout<<"\nMax area under historgram is: "<<maxArea;

  return 0;
}
