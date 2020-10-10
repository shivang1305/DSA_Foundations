/*
1. You are given a number n.
2. You are required to print the number of binary strings of length n with no consecutive 0's.
*/

#include<iostream>

using namespace std;

int main() {
  int length;
  cout<<"Enter the length of binary string: ";
  cin>>length;

  int count1, count0;
  int pcount1 = 1, pcount0 = 1;

  for(int i=2; i<=length; i++) {
      count1 = pcount0 + pcount1; //no boundation on strings ending with one
      count0 = pcount1; //since there is a boundation of strings ending with zero

      pcount0 = count0;
      pcount1 = count1;
  }

  cout<<count0 + count1; //jo zero par khatam hui hain string + jo 1 par khatam hui hain

  return 0;
}
