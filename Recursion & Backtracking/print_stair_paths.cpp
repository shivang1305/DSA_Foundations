/*
1. You are given a number n representing number of stairs in a staircase.
2. You are standing at the bottom of staircase. You are allowed to climb 1 step, 2 steps or 3 steps in one move.
3. Complete the body of getStairPaths function - without changing signature - to get the list of all paths that can be used to climb the staircase up.
*/

#include<iostream>
#include<string>

using namespace std;

void printStairPaths(int numStairs, string ans){
  if(numStairs == 0) { //positive base case
    cout<<ans<<endl;
    return;
  }
  if(numStairs < 0)   //negative base case
    return;

  printStairPaths(numStairs - 1, ans+"1");
  printStairPaths(numStairs - 2, ans+"2");
  printStairPaths(numStairs - 3, ans+"3");

}

int main() {
  int numStairs;
  cout<<"Enter the number of stairs: ";
  cin>>numStairs;

  printStairPaths(numStairs, "");

  return 0;
}
