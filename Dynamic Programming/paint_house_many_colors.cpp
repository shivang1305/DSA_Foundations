/*
1. You are given a number n and a number k separated by a space, representing the number of houses and number of colors.
2. In the next n rows, you are given k space separated numbers representing the cost of painting nth house with one of the k colors.
3. You are required to calculate and print the minimum cost of painting all houses without painting any consecutive house with same color.
*/


/*
Approach- 1 Time Complexity: O(n^3)
---------------------------------------------------------------------------------------------------
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
  int N;
//   cout<<"Enter the number of houses: ";
  cin>>N;

  int K;
//   cout<<"\nEnter the number of colors: ";
  cin>>K;

  int cost[N][K];
//   cout<<"\nEnter the cost: \n";
  for(int i=0; i<N; i++) {
    for(int j=0; j<K; j++)
      cin>>cost[i][j];
  }

  int dp[N][K];

  for(int k=0; k<K; k++)
    dp[0][k] = cost[0][k];

  for(int i=1; i<N; i++) {
    for(int j=0; j<K; j++) {
      int minimum = INT_MAX;
      for(int z=0; z<K; z++) {
        if(z != j)
          minimum = min(minimum, dp[i-1][z]);
      }
      dp[i][j] = minimum + cost[i][j];
    }
  }

  int mini = INT_MAX;
  for(int i=0; i<K; i++) {
    mini = min(mini, dp[N-1][i]);
  }

  cout<<mini;

  return 0;
}
---------------------------------------------------------------------------------------------------
Approach- 2 Time Complexity = O(n^2)
---------------------------------------------------------------------------------------------------
*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cout<<"Enter the number of houses: ";
  cin>>N;

  int K;
  cout<<"\nEnter the number of colors: ";
  cin>>K;

  int cost[N][K];
  cout<<"\nEnter the cost: \n";
  for(int i=0; i<N; i++) {
    for(int j=0; j<K; j++)
      cin>>cost[i][j];
  }

  int dp[N][K];

  //computing minimum and second minimum at each row

  int least = INT_MAX;
  int sLeast = INT_MAX;

  for(int k=0; k<K; k++) {
    dp[0][k] = cost[0][k];

    if(cost[0][k] <= least) {
      sLeast = least;
      least = cost[0][k];
    }
    else if(cost[0][k] <= sLeast)
      sLeast = cost[0][k];
  }


  for(int i=1; i<N; i++) {
    int newLeast = INT_MAX;
    int newSecondLeast = INT_MAX;
    for(int j=0; j<K; j++) {
      if(dp[i-1][j] == least)
        dp[i][j] = cost[i][j] + sLeast;
      else
        dp[i][j] = cost[i][j] + least;

      if(dp[i][j] <= newLeast) {
        newSecondLeast = newLeast;
        newLeast = dp[i][j];
      }
      else if(dp[i][j] <= newSecondLeast)
        newSecondLeast = dp[i][j];
    }
    least = newLeast;
    sLeast = newSecondLeast;
  }

  cout<<least;

  return 0;
}
