/*
Climb the stairs with min number of possible moves.
Given 'n' number of stairs and an array whose values denoting the number of jumps allowed from each stair.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int climbStairs(int n, int arr[]) {
  int dp[n+1];

  for(int i=0; i<=n; i++)
    dp[i] = -1;

  dp[n] = 0;

  for(int i=n-1; i>=0; i--) {

    if(arr[i] > 0) {
      int ans = INT_MAX;

      for(int j=1; j<=arr[i] && i+j <= n; j++) {
        if(dp[i+j] != -1)
          ans = min(dp[i+j], ans);
      }
        
      if(ans != INT_MAX)
        dp[i] = 1 + ans;
    }

  }
  return dp[0];
}

int main() {
  int n;
  cout<<"Enter the bumber of stairs: ";
  cin>>n;

  int arr[n];
  cout<<"Enter the number of allowed jumps at each stair: ";
  for(int i=0; i<n; i++)
    cin>>arr[i];

  cout<<"Min moves to climb the stairs: "<<climbStairs(n, arr);
  return 0;
}
