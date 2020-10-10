/*
1. You are given a string str of digits. (will never start with a 0)
2. You are required to encode the str as per following rules
    1 -> a
    2 -> b
    3 -> c
    ..
    25 -> y
    26 -> z
3. Complete the body of printEncodings function - without changing signature - to calculate and print all encodings of str.
Use the input-output below to get more understanding on what is required
123 -> abc, aw, lc
993 -> iic
013 -> Invalid input. A string starting with 0 will not be passed.
103 -> jc
303 -> No output possible. But such a string maybe passed. In this case print nothing.

*/

#include<iostream>
#include<string>

using namespace std;

void printEncodings(string str, string ans) {
  if(str.length() == 0) {
    cout<<ans<<endl;
    return;
  }

  else if(str.length() == 1) {
    char ch = str[0];
    if(ch == '0')
      return;
    else {
      int idx = ch - '0';
      char alphabet = (char)('a' + idx - 1);
      cout<<ans+alphabet<<endl;
    }
  }

  else {
    string fstr = str.substr(0,1);
    if(fstr == "0")
      return;
    else {
      int idx = stoi(fstr);
      char alphabet = (char)('a' + idx - 1);
      string ros = str.substr(1, str.size());
      printEncodings(ros, ans+alphabet);
    }


    string ros2 = str.substr(0, 2);
    string ros3 = str.substr(2, str.size());
    int idx2 = stoi(ros2);
    if(idx2 <= 26) {
      char alphabet = (char)('a' + idx2 - 1);
      printEncodings(ros3, ans+alphabet);
    }

  }

}

int main() {
  string str;
  cout<<"Enter the string in the form of numbers only: ";
  cin>>str;

  printEncodings(str, "");

  return 0;
}
