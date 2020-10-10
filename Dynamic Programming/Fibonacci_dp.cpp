/*
Print the fibonacci series using Dynamic Programming all concepts
*/

#include<iostream>

using namespace std;

//Memoization
int fiboMem(int N, int memo[]) {
  if(N==0 || N==1)
    return N;
  if(memo[N] != 0)
    return memo[N];

  int result = fiboMem(N-1, memo) + fiboMem(N-2, memo);
  memo[N] = result;
  return result;
}

//Tabulation
int fibTab(int N) {
  if (N<2)
    return N;

  int dp[N+1];
  dp[0] = 0;
  dp[1] = 1;

  for (int i=2; i<=N; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }

  return dp[N];
}

//Tabulation without an array (relation)
int finTabR(int N) {
  if(N < 2)
    return N;
  int prev1 = 0, prev2 = 1, res;
  for(int i=2; i<=N; i++) {  //O(N) time complexity
    res = prev1 + prev2;
    prev1 = prev2;
    prev2 = res;
  }
  return res;
}

int main() {
  int N;
  cout<<"Enter the value of N: ";
  cin>>N;

  int memo[N+1] = {0};
  cout<<"The result is: "<<fiboMem(N, memo);

  return 0;
}
