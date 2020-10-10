/*
1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing the prices of a share on n days.
3. You are required to find the stock span for n days.
4. Stock span is defined as the number of days passed between the current day and the first day before today when price was higher than today.

e.g.
for the array [2 5 9 3 1 12 6 8 7]
span for 2 is 1
span for 5 is 2
span for 9 is 3
span for 3 is 1
span for 1 is 1
span for 12 is 6
span for 6 is 1
span for 8 is 2
span for 7 is 1
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cout<<"Enter the size of the array: ";
  cin>>n;

  int arr[n];
  cout<<"\nEnter the elements of array: ";
  for(int i=0; i<n; i++)
    cin>>arr[i];

  //left to right approach
  int ans[n] = {0};
  ans[0] = 1;

  stack<int> st;
  st.push(arr[0]);

  for(int i=1; i<n; i++) {
    int count = 0;
    while(!st.empty() && arr[i] >= st.top()) {
      count++;
      st.pop();
    }

    if(st.empty())
      ans[i] = i+1;
    else
      ans[i] = count + 1;

    st.push(arr[i]);
  }

  //result
  for(int i=0; i<n; i++)
    cout<<ans[i]<<" ";
  return 0;
}
