/*
1. You are given a number n and a number k in separate lines, representing the number of fences and number of colors.
2. You are required to calculate and print the number of ways in which the fences could be painted so that not more than two fences have same colors.
*/

#include<iostream>

using namespace std;

int main() {
  int N;
  cout<<"Enter the number of houses: ";
  cin>>N;

  int K;
  cout<<"\nEnter the number of colors: ";
  cin>>K;

  int same, diff, total;
  if(N >= 2) {

    same = K * 1;
    diff = K*(K-1);
    total = same + diff;

    for(int i=3; i<=N; i++) {
      same = diff;
      diff = total * (K-1);
      total = same + diff;
    }

  }else
    cout<<"Invalid input";

  cout<<total;

  return 0;
}
