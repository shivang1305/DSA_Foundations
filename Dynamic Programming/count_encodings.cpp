/*
1. You are given a string str of digits. (will never start with a 0)
2. You are required to encode the str as per following rules
    1 -> a
    2 -> b
    3 -> c
    ..
    25 -> y
    26 -> z
3. You are required to calculate and print the count of encodings for the string str.

     For 123 -> there are 3 encodings. abc, aw, lc
     For 993 -> there is 1 encoding. iic
     For 013 -> This is an invalid input. A string starting with 0 will not be passed.
     For 103 -> there is 1 encoding. jc
     For 303 -> there are 0 encodings. But such a string maybe passed. In this case
     print 0.
*/

#include<iostream>
#include<string>

using namespace std;

int main() {
  string digits;
  cout<<"Enter the digits: ";
  cin>>digits;

  int dp[digits.length()] = {0};
  dp[0] = 1; //single digit always encodes to an alphabet

  for(int i=1; i<digits.length(); i++) {

    if(digits[i-1] == '0' && digits[i] != '0') //zero - non zero
      dp[i] = dp[i-1];

    else if(digits[i-1] != '0' && digits[i] == '0') { //non zero - zero
      if(digits[i-1] == '1' || digits[i-1] == '2') //less than or equal to alphabets
        dp[i] = (i>=2 ? dp[i-2] : 1);
    }

    else{
      if(stoi(digits.substr(i-1, i+1)) <= 26)
        dp[i] = dp[i-1] + (i>=2 ? dp[i-2] : 1);
      else
        dp[i] = dp[i-1];
    }

  }

  cout<<dp[digits.length() - 1];

  return 0;
}
