/*
1. You are given a number n, representing the number of friends.
2. Each friend can stay single or pair up with any of it's friends.
3. You are required to print the number of ways in which these friends can stay single or pair up.
E.g.
1 person can stay single or pair up in 1 way.
2 people can stay singles or pair up in 2 ways. 12 => 1-2, 12.
3 people (123) can stay singles or pair up in 4 ways. 123 => 1-2-3, 12-3, 13-2, 23-1.
*/

#include<iostream>

using namespace std;

int main() {
  int N;
  cout<<"Enter the number of friends: ";
  cin>>N;

  int dp[N + 1] = {0};

  dp[1] = 1;
  dp[2] = 2;

  for(int i=3; i<=N; i++)
    dp[i] = dp[i-1] + (i-1)*dp[i-2];

  cout<<dp[N];

  return 0;
}
