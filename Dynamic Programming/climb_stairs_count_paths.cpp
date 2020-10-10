#include<iostream>

using namespace std;

//Recursion method
int countPathsRecursion(int N) {
  if(N<0) //negative base case
    return 0;
  if(N == 0) //positive base case
    return 1;
  int cp1 = countPaths(N-1);
  int cp2 = countPaths(N-2);
  int cp3 = countPaths(N-3);
  int cp = cp1 + cp2 + cp3;
  return cp;
}

//Memoization method
int countPathsMemo(int N, int qb[]) {
  if(N < 0)
    return 0;
  if(N == 0)
    return 1;
  if(qb[N] != 0)
    return qb[N];

  int cp1 = countPathsMemo(N-1);
  int cp2 = countPathsMemo(N-2);
  int cp3 = countPathsMemo(N-3);
  int cp = cp1 + cp2 + cp3;
  qb[N] = cp;
  return cp;
}

//Tabulation Method
/*
1. Assign Storage and Meaning to the array
2. Identify Direction
3. Travel & Solve
*/
int countPathsTab(int N) {
  int dp[N+1];
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  for(int i=3; i<=N ; i++) {
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
  }
  return dp[n];
}

//Tabulation without an array method
int climbStairs(int n) {
  if(n < 3)
    return n;
  int prev0 = 1, prev1 = 1, prev2 = 2, res;
  for(int i=3; i<=n; i++) {  //O(N) time complexity
    res = prev0 + prev1 + prev2;
    prev0 = prev1;
    prev1 = prev2;
    prev2 = res;
  }
  return res;
}

int main() {
  int N;
  cout<<"Enter the number of stairs: ";
  cin>>N;

  cout<<"\nThe number of paths are: "<<countPaths(N);

  return 0;
}
