/*
1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner. Only two moves are allowed 'h' (1-step horizontal) and 'v' (1-step vertical).
3. Complete the body of getMazePath function - without changing signature - to get the list of all paths that can be used to move from top-left to bottom-right.*/

#include<iostream>
#include<string>

using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string ans){
  if(sr==dr && sc==dc) { //positive base case
    cout<<ans<<endl;
    return;
  }
  // if(sr>dr || sc>dc) {  //negative base case
  //   vector<string> emptyStr;
  //   return emptyStr;
  // }


  if(sc < dc)
    printMazePaths(sr, sc+1, dr, dc, ans+"h");
  if(sr < dr)
    printMazePaths(sr+1, sc, dr, dc, ans+"v");

}

int main() {
  int n, m;
  cout<<"Enter the number of rows and columns of maze: ";
  cin>>n>>m;

  printMazePaths(1, 1, n ,m, "");

  return 0;
}
