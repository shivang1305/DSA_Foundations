/*
1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a, which represents a maze.
4. You are standing in top-left cell and are required to move to bottom-right cell.
5. You are allowed to move 1 cell right (h move) or 1 cell down (v move) in 1 motion.
6. Each cell has a value that will have to be paid to enter that cell (even for the top-left and bottom-right cell).
7. You are required to traverse through the matrix and print the cost of path which is least costly.
*/

#include<iostream>
#include<vector>

using namespace std;

int minCostPath(vector<vector<int>> maze) {
  int dp[maze.size()][maze[0].size()];

  int m = maze.size();
  int n = maze[0].size();

  for(int i=m-1; i>=0; i--) {
    for(int j=n-1; j>=0; j--) {
      if(i== m-1 && j==n-1)
        dp[i][j] = maze[i][j];
      else if(i+1 == m-1)
        dp[i][j] = maze[i][j] + dp[i][j+1];
      else if(j+1 == n-1)
        dp[i][j] = maze[i][j] + dp[i+1][j];
      else
        dp[i][j] = maze[i][j] + min(dp[i+1][j], dp[i][j+1]);
    }
  }

  return dp[0][0];
}

int main() {
  int m, n;
  cout<<"Enter the size of array: ";
  cin>>m>>n;

  vector<vector<int>> maze;

  int val;

  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      cin>>val;
      maze.push_back(val);
    }
  }

  cout<<"\nThe min cost for traversal is: "<<minCostPath(maze); //function call

  return 0;
}
