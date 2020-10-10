/*
1. You are given a number x.
2. You are given another number n.
3. You are required to calculate x raised to the power n.
   Don't change the signature of power function .
*/

#include<iostream>

using namespace std;

int powerLog(int N, int x) {
  if(x == 0) //base case
    return 1;
  if(x % 2 ==0) //even power
    return powerLog(N, x/2) * powerLog(N, x/2);
  else
    return  N * powerLog(N, x/2) * powerLog(N, x/2);
}

int main() {
  int N, x;
  cout<<"Enter the number & its power: ";
  cin>>N>>x;
  int result = powerLog(N, x);
  cout<<"\nLinear Power of the number is: "<<result;
  return 0;
}
