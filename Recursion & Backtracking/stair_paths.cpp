/*
1. You are given a number n representing number of stairs in a staircase.
2. You are standing at the bottom of staircase. You are allowed to climb 1 step, 2 steps or 3 steps in one move.
3. Complete the body of getStairPaths function - without changing signature - to get the list of all paths that can be used to climb the staircase up.
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> getStairPaths(int numStairs){
  if(numStairs == 0) { //positive base case
    vector<string> blankStr;
    blankStr.push_back("");
    return blankStr;
  }
  if(numStairs < 0) {  //negative base case
    vector<string> emptyStr;
    return emptyStr;
  }

  vector<string> paths1 = getStairPaths(numStairs - 1);
  vector<string> paths2 = getStairPaths(numStairs - 2);
  vector<string> paths3 = getStairPaths(numStairs - 3);

  vector<string> finalStr;
  for(string s: paths1) {
    finalStr.push_back("1" + s);
  }
  for(string s: paths2) {
    finalStr.push_back("2" + s);
  }
  for(string s: paths3) {
    finalStr.push_back("3" + s);
  }
  return finalStr;
}

int main() {
  int numStairs;
  cout<<"Enter the number of stairs: ";
  cin>>numStairs;

  vector<string> paths = getStairPaths(numStairs);

  for(int i=0; i<paths.size(); i++)
    cout<<paths[i]<<" ";
  return 0;
}
