/*
FLOOD FILL problem with recursion method
1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a. The numbers can be 1 or 0 only.
4. You are standing in the top-left corner and have to reach the bottom-right corner.
Only four moves are allowed 't' (1-step up), 'l' (1-step left), 'd' (1-step down) 'r' (1-step right). You can only move to cells which have 0 value in them. You can't move out of the boundaries or in the cells which have value 1 in them (1 means obstacle)
5. Complete the body of floodfill function - without changing signature - to print all paths that can be used to move from top-left to bottom-right.
*/

#include<iostream>
#include<string>

using namespace std;

#define M 4
#define N 3

void floodFill(int maze[][N], int row, int col, string psf, bool visited[][N]) {
  if(row<0 || col<0 || row==M || col==N || maze[row][col]==1 || visited[row][col]==true) //negative base case
    return;
  if(row == M-1 && col == N-1){ //positive base case
    cout<<psf<<endl;
    return;
  }


  visited[row][col] = true; //mark the index while moving forward from the index so that index is not repeated

  floodFill(maze, row-1, col, psf+"t", visited);
  floodFill(maze, row, col-1, psf+"l", visited);
  floodFill(maze, row+1, col, psf+"d", visited);
  floodFill(maze, row, col+1, psf+"r", visited);

  visited[row][col] = false; //unmark the index at move backwards from the index

}

int main() {
  // int m=4, n=3;
  // cout<<"Enter the dimensions of the maze (m x n): ";
  // cin>>m>>n;

  int maze[M][N] = {{0, 1, 1},
                    {0, 0, 1},
                    {1, 0, 0},
                    {0, 1, 0},};
  bool visited[M][N];

  // cout<<"Enter the elements of the maze: \n";
  for(int i=0; i<M; i++) {
    for(int j=0; j<N; j++)
      visited[i][j] = false;
  }

  floodFill(maze, 0, 0, "", visited); //function call

  return 0;
}
