/*
Day 27 ->  DSA Foundations                                                         Date:26-Sept-2020

1. You are given a pattern of upto 8 length containing characters 'i' and 'd'.
2. 'd' stands for decreasing and 'i' stands for increasing
3. You have to print the smallest number, using the digits 1 to 9 only without repetition, such that
the digit decreases following a d and increases follwing an i.
*/

#include<iostream>
#include<stack>

using namespace std;

int main() {
  string arr;
  cout<<"Enter the 'd' or 'i' values (upto 8 only) in string format: ";
  cin>>arr;
  arr += 'i';

  stack<int> st;
  int ans[arr.length()] = {0};

  int ct = 1;

  for(int i=0; i<arr.length(); i++) { // O(n)
    if(arr[i] == 'i') {
      ans[i] = ct++;
      while(!st.empty()) {
        int idx = st.top();
        st.pop();
        ans[idx] = ct++;
      }
    }
    else
      st.push(i);
  }

  for(int i=0; i<arr.length(); i++)
    cout<<ans[i]<<" ";

  return 0;
}
