#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main() {
  int n;
  cout<<"Enter the size of the array: ";
  cin>>n;

  int arr[n];
  cout<<"\nEnter the elements of the array: ";
  for(int i=0; i<n; i++)
    cin>>arr[i];

  int k;
  cout<<"\nEnter the sliding window: ";
  cin>>k;

  vector<int> nge;
  nge.assign(n, n);

  stack<int> st;
  st.push(0);

  for(int i=1; i<n; i++) {
    while(!st.empty() && arr[i] >= arr[st.top()]) {
      nge[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }

  // for(int i=0; i<n; i++)
  //   cout<<nge[i]<<" ";

  int j = 0;
  for(int i=0; i<=n-k; i++) {
    if(j != i)
      j = i;
    while(nge[j] < i+k)
      j = nge[j];
    cout<<arr[j]<<" ";
  }

  return 0;
}
