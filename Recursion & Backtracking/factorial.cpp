#include<iostream>

using namespace std;

int factorial(int N) {
  if(N == 0) //base case
    return 1;
  return N*factorial(N-1); //recurrence relation
}

int main() {
  int N;
  cout<<"Enter the number: ";
  cin>>N;
  int fact = factorial(N);
  cout<<"\nFactorial of the number is: "<<fact;
  return 0;
}
