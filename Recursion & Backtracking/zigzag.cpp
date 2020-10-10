/*
1. Here are a few sets of inputs and outputs for your reference
Input1 -> 1
Output1 -> 1 1 1

Input2 -> 2
Output2 -> 2 1 1 1 2 1 1 1 2

Input2 -> 3
Output3 -> 3 2 1 1 1 2 1 1 1 2 3 2 1 1 1 2 1 1 1 2 3

2. Figure out the pattern and complete the recursive function pzz to achieve the above for any
positive number n.

*/

#include<iostream>

using namespace std;

void zigzag(int N) {
  if(N == 0)
    return;
  cout<<"Pre "<<N<<endl;
  zigzag(N - 1); //left call
  cout<<"In "<<N<<endl;
  zigzag(N - 1); //right call
  cout<<"Post "<<N<<endl;
}

int main() {
  int N;
  cout<<"Enter the number: ";
  cin>>N;
  zigzag(N);
  return 0;
}
