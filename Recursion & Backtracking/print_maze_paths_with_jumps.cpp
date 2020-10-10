/*
1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner.
3. In a single move you are allowed to jump 1 or more steps horizontally (as h1, h2, .. ), or 1 or more steps vertically (as v1, v2, ..) or 1 or more steps diagonally (as d1, d2, ..).
4. Complete the body of getMazePath function - without changing signature - to get the list of all paths that can be used to move from top-left to bottom-right.
*/

#include<iostream>
#include<string>

using namespace std;

void printMazePathsJumps(int sr, int sc, int dr, int dc, string ans) {
  if(sr==dr && sc==dc) { //positive base case
    cout<<ans<<endl;
    return;
  }


  for(int i=1; i<=dc-sc; i++)
    printMazePathsJumps(sr, sc+i, dr, dc, ans+"h"+to_string(i));

  for(int i=1; i<=dr-sr; i++)
    printMazePathsJumps(sr+i, sc, dr, dc, ans+"v"+to_string(i));

  for(int i=1; i<=dc-sc && i<=dr-sr; i++)
    printMazePathsJumps(sr+i, sc+i, dr, dc, ans+"d"+to_string(i));

}

int main() {
  int n, m;
  cout<<"Enter the number of rows and columns of maze: ";
  cin>>n>>m;

  printMazePathsJumps(1, 1, n ,m, "");

  return 0;
}
