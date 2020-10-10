/*
1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner.
3. In a single move you are allowed to jump 1 or more steps horizontally (as h1, h2, .. ), or 1 or more steps vertically (as v1, v2, ..) or 1 or more steps diagonally (as d1, d2, ..).
4. Complete the body of getMazePath function - without changing signature - to get the list of all paths that can be used to move from top-left to bottom-right.
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> getMazePathsJumps(int sr, int sc, int dr, int dc) {
  if(sr==dr && sc==dc) { //positive base case
    vector<string> blankStr;
    blankStr.push_back("");
    return blankStr;
  }

  vector<string> finalStr;

  for(int i=1; i<=dc-sc; i++) {
    vector<string> hpaths = getMazePathsJumps(sr, sc+i, dr, dc);
    for(string h: hpaths)
      finalStr.push_back("h"+to_string(i)+h);
  }

  for(int i=1; i<=dr-sr; i++) {
    vector<string> vpaths = getMazePathsJumps(sr+i, sc, dr, dc);
    for(string v: vpaths)
      finalStr.push_back("v"+to_string(i)+v);
  }

  for(int i=1; i<=dr-sr && i<=dc-sc; i++) {
    vector<string> dpaths = getMazePathsJumps(sr+i, sc+i, dr, dc);
    for(string d: dpaths)
      finalStr.push_back("d"+to_string(i)+d);
  }

  return finalStr;
}

int main() {
  int n, m;
  cout<<"Enter the number of rows and columns of maze: ";
  cin>>n>>m;

  vector<string> paths = getMazePathsJumps(1, 1, n ,m);

  for(int i=0; i<paths.size(); i++)
    cout<<paths[i]<<endl;
  return 0;
}
