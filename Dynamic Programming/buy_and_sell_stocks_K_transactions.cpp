#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
  int days;
  cout<<"Enter the number of days: ";
  cin>>days;

  int prices[days];
  cout<<"\nEnter the prices of stocks for each day: ";
  for(int i=0; i<days; i++)
    cin>>prices[i];

  int K;
  cout<<"\nEnter the number of transactions allowed: ";
  cin>>K;

  int dp[K+1][days];

  for(int i=0; i<=K; i++) {
    int ans = INT_MIN;
    for(int j=0; j<days; j++) {
      if(i==0 || j==0)
        dp[i][j] = 0;
      else {
        //-------------Approach 1--------------------------------
        // int ans = INT_MIN;
        // for(int k=j-1; k>=0; k--) {  //Time Complexity : O(n^3)
        //   ans = max(ans, dp[i-1][k] + prices[j] - prices[k]);
        // }
        // dp[i][j] = max(ans, dp[i][j-1]);

        //-----------Approach 2----------------------------------
        ans = max(ans, dp[i-1][j-1] - prices[j-1]);
        dp[i][j] = max(ans + prices[j], dp[i][j-1]);
      }
    }
  }

  cout<<dp[K][days-1];
  return 0;
}
