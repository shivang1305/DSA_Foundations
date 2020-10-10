/*
1. You are given a number n, the size of a chess board.
2. You are required to place n number of queens in the n * n cells of board such that no queen can kill another.
Note - Queens kill at distance in all 8 directions
3. Complete the body of printNQueens function - without changing signature - to calculate and print all safe configurations of n-queens. Use sample input and output to get more idea.
*/

#include<iostream>

using namespace std;

#define N 4

bool safeMove(int chess[][N], int row, int col) {
  for(int i=row-1, j=col; i>=0; i--) { //check vertically upwards
    if(chess[i][j] == 1)
      return false;
  }
  for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) { //check left daigonally upwards
    if(chess[i][j] == 1)
      return false;
  }
  for(int i=row-1, j=col+1; i>=0 && j<N; i--, j++) { //check right daigonally upwards
    if(chess[i][j] == 1)
      return false;
  }
  return true;
}

void nQueens(int chess[][N], string qsf, int row) {
  if(row == N) {
    cout<<qsf<<endl;
    return;
  }

  for(int col=0; col<N; col++) {
    if(safeMove(chess, row, col) == true) {
      chess[row][col] = 1; //placing the queen at this index on the chess board
      nQueens(chess, qsf+to_string(row)+"-"+to_string(col)+", ", row+1);
      chess[row][col] = 0; //remove the queen while going back in recursion tree
    }
  }
}

int main() {
  int chess[N][N] = {0};

  nQueens(chess, "", 0);

  return 0;
}
