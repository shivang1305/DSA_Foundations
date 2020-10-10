/*
1. You are given a number n, representing the count of items.
2. You are given n numbers, representing the values of n items.
3. You are given n numbers, representing the weights of n items.
3. You are given a number "cap", which is the capacity of a bag you've.
4. You are required to calculate and print the maximum value that can be created in the bag without
   overflowing it's capacity.

Note -> Each item can be taken 0 or 1 number of times. You are not allowed to put the same item
        again and again
*/

#include<iostream>

using namespace std;

int main() {
  int n;
  cout<<"Enter the number of entities: ";
  cin>>n;

  int values[n];
  cout<<"\nEnter the values: ";
  for(int i=0; i<n; i++)
    cin>>values[i];

  int weights[n];
  cout<<"\nEnter the weights: ";
  for(int i=0; i<n; i++)
    cin>>weights[i];

  int capacity;
  cout<<"\nEnter the capacity of bag: ";
  cin>>capacity;

  int dp[n+1][capacity+1] = {0};

  for(int i=0; i<=n; i++) { //balls-score
    for(int j=0; j<=capacity; j++) { //runs
      if(i==0 || j==0)
        dp[i][j] = 0;
      else if(weights[i-1] > j)//cannot bat as no of balls are less than min balls req to play
        dp[i][j] = dp[i-1][j];
      else if(weights[i-1] <= j) //can bat
        dp[i][j] = max(dp[i-1][j], values[i-1] + dp[i-1][j - weights[i-1]]); //mere batting krne baad zyada run score kr paa rhi h team ya mere batting kre bina hi zyada score kr rhi h team
    }
  }

  cout<<dp[n][capacity];

  return 0;
}
