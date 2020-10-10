/*
1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner. Only two moves are allowed 'h' (1-step horizontal) and 'v' (1-step vertical).
3. Complete the body of getMazePath function - without changing signature - to get the list of all paths that can be used to move from top-left to bottom-right.*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> getMazePaths(int sr, int sc, int dr, int dc){
  if(sr==dr && sc==dc) { //positive base case
    vector<string> blankStr;
    blankStr.push_back("");
    return blankStr;
  }
  // if(sr>dr || sc>dc) {  //negative base case
  //   vector<string> emptyStr;
  //   return emptyStr;
  // }

  vector<string> hpaths;
  vector<string> vpaths;

  if(sc < dc)
    hpaths = getMazePaths(sr, sc+1, dr, dc);
  if(sr < dr)
    vpaths = getMazePaths(sr+1, sc, dr, dc);


  vector<string> finalStr;
  for(string s: hpaths) {
    finalStr.push_back("h" + s);
  }
  for(string s: vpaths) {
    finalStr.push_back("v" + s);
  }
  return finalStr;
}

int main() {
  int n, m;
  cout<<"Enter the number of rows and columns of maze: ";
  cin>>n>>m;

  vector<string> paths = getMazePaths(1, 1, n ,m);

  for(int i=0; i<paths.size(); i++)
    cout<<paths[i]<<" ";
  return 0;
}
