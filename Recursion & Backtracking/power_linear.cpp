/*
1. You are given a number x.
2. You are given another number n.
3. You are required to calculate x raised to the power n.
   Don't change the signature of power function .
*/

#include<iostream>

using namespace std;

int power(int N, int x) {
  if(x == 0) //base case
    return 1;
  return N*power(N, x-1); //recurrence relation
}

int main() {
  int N, x;
  cout<<"Enter the number & its power: ";
  cin>>N>>x;
  int result = power(N, x);
  cout<<"\nLinear Power of the number is: "<<result;
  return 0;
}
