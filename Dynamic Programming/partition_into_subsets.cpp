/*
1. You are given a number n, representing the number of elements.
2. You are given a number k, representing the number of subsets.
3. You are required to print the number of ways in which these elements can be partitioned in k non-empty subsets.
E.g.
For n = 4 and k = 3 total ways is 6
12-3-4
1-23-4
13-2-4
14-2-3
1-24-3
1-2-34
*/

#include<iostream>

using namespace std;

int main() {
  int N, K;
  cout<<"Enter the no of players and no of teams: ";
  cin>>N>>K;

  if(N == 0 || K == 0 || N < K)
    cout<<0;

  else {
    long long int dp[K+1][N+1] = {0};

    for(int i=1; i<=K; i++) {
      for(int j=1; j<=N; j++) {
        if(i==1 || j == i)
          dp[i][j] = 1;
        else if(j > i)
          dp[i][j] = i*dp[i][j-1] + dp[i-1][j-1];
      }
    }

    cout<<dp[K][N];
  }

  return 0;
}
