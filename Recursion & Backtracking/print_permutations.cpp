/*
1. You are given a string str.
2. Complete the body of printPermutations function - without changing signature - to calculate and print all permutations of str.
*/

#include<iostream>
#include<string>

using namespace std;

void printPermutations(string str, string ans) {
  if(str.length() == 0) { //base case
    cout<<ans<<endl;
    return;
  }

  for(int i=0; i<str.length(); i++) {
    char ch = str[i];
    string str1 = str.substr(0, i);
    string str2 = str.substr(i+1, str.length());
    string rstr = str1 + str2;
    printPermutations(rstr, ans+ch);
  }
}

int main() {
  string str;
  cout<<"Enter the string: ";
  cin>>str;

  printPermutations(str, "");
  return 0;
}
