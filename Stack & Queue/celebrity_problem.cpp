/*
  Day-24  ->    DSA Foundations                                                  Date: 25-Sept-2020
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cout<<"Enter the number of persons: ";
  cin>>N;

  int arr[N][N] = {0};
  cout<<"\nEnter the elements of matrix (0 -> does not know  1 -> knows): \n";
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++)
      cin>>arr[i][j];
  }

  stack<int> celebs;
  for(int i=0; i<N; i++)
    celebs.push(i);

  while(celebs.size() >= 2) {
    int p2 = celebs.top();
    celebs.pop();
    int p1 = celebs.top();
    celebs.pop();

    //p1 does not know p2 therefore p2 can't be a celebrity
    if(arr[p1][p2] == 0)
      celebs.push(p1);

    //p1 knows p2 therefore p1 can't be a celebrity
    else if(arr[p1][p2] == 1)
      celebs.push(p2);
  }

  for(int i=0; i<N; i++) {
    if(i != celebs.top()) {
      if(arr[i][celebs.top()] == 0 || arr[celebs.top()][i] == 1) {
        cout<<"\nNone is celebrity all are common people";
        return 0;
      }
    }
  }

  cout<<"\nCelebrity is : "<<celebs.top() + 1;

  return 0;
}
