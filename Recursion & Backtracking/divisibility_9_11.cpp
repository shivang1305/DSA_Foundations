/*
Check the divisibility of a given number by 9 & 11 by recursion method.
*/

#include <iostream>

using namespace std;

int divBy9(int N) {  //a no is divisible by 9 only if sum of all its digits are divisible by 9
  if(N == 9) //base case
    return 1;
  if(N < 9) //base case
    return 0;
  int sum = 0;
  while(N > 0) { //obtaining sum of digits
    sum += N%10;
    N /= 10;
  }
  divBy9(sum); //recursive call
}

int divBy11(int N) { //a no is divisible by 11 only if the difference of sum of digits at odd and even positions is divisible by 11
    if(N == 0) //base case
      return 1;
    if(N < 11) //base case
      return 0;

    int sumEven=0, sumOdd=0;
    while(N > 0) { //obtaining sum of digits at odd and even positions
      sumOdd += N%10;
      N /= 10;
      sumEven += N%10;
      N /= 10;
    }
    int diff = sumEven > sumOdd ? (sumEven - sumOdd) : (sumOdd - sumEven);
    divBy11(diff); //recursive call
}

int main() {
  int N;
  cout<<"Enter the number: ";
  cin>>N;

  int result_9 = divBy9(N);
  int result_11 = divBy11(N);

  if(result_9 == 1)
    cout<<"\nDivisible by 9";
  else
    cout<<"\nNot divisible by 9";
  if(result_11 == 1)
    cout<<"\nDivisible by 11";
  else
    cout<<"\nNot divisible by 11";

  return 0;
}
