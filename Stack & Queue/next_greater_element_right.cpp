/*
1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.
3. You are required to "next greater element on the right" for all elements of array
4. Input and output is handled for you.

"Next greater element on the right" of an element x is defined as the first element to right of x having value greater than x.
Note -> If an element does not have any element on it's right side greater than it, consider -1 as it's "next greater element on right"
e.g.
for the array [2 5 9 3 1 12 6 8 7]
Next greater for 2 is 5
Next greater for 5 is 9
Next greater for 9 is 12
Next greater for 3 is 12
Next greater for 1 is 12
Next greater for 12 is -1
Next greater for 6 is 8
Next greater for 8 is -1
Next greater for 7 is -1
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

  stack<int> st;

  /*---------------------------------------------------------------------------*/
  //right to left approach
  // ans[n-1] = -1;
  // st.push(arr[n-1]);

  // for(int i=n-2; i>=0; i--) {
  //   while(!st.empty() && st.top() <= arr[i])
  //     st.pop();
  //
  //   if(st.empty())
  //     ans[i] = -1;
  //   else
  //     ans[i] = st.top();
  //
  //   st.push(arr[i]);
  // }
  /*---------------------------------------------------------------------------*/

  /*---------------------------------------------------------------------------*/
  //left to right approach
  int ans[n] = {0};
  st.push(arr[0]);

  for(int i=1; i<n; i++) {
    int x = 0;
    while(!st.empty() && arr[i] >= st.top()) {
      ans[i - 1 - x] = arr[i];
      x++;
      st.pop();
    }
    st.push(arr[i]);
  }

  //to fill the remaining elements
  for(int i=0; i<n; i++) {
    if(ans[i] == 0)
      ans[i] = -1;
  }
  /*---------------------------------------------------------------------------*/

  //result
  for(int i=0; i<n; i++)
    cout<<ans[i]<<" ";
  return 0;
}
