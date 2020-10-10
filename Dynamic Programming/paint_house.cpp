/*
1. You are given a number n, representing the number of houses.
2. In the next n rows, you are given 3 space separated numbers representing the cost of painting nth house with red or blue or green color.
3. You are required to calculate and print the minimum cost of painting all houses without painting any consecutive house with same color.
*/

#include<iostream>

using namespace std;

int main() {
  int N;
  cout<<"Enter the number of houses: ";
  cin>>N;

  int cost[N][3];
  cout<<"\nEnter the cost of(RED, BLUE, GREEN) r,b,g: \n";
  for(int i=0; i<N; i++) {
    for(int j=0; j<3; j++)
      cin>>cost[i][j];
  }

  int r, b, g;
  r = cost[0][0];
  b = cost[0][1];
  g = cost[0][2];

  for(int i=1; i<N; i++) {
    int red = min(b, g) + cost[i][0];
    int blue = min(r, g) + cost[i][1];
    int green = min(r, b) + cost[i][2];

    r = red;
    b = blue;
    g = green;
  }

  cout<<min(r, min(b, g));
  return 0;
}
