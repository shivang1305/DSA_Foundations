/*
1. You are given a string str. The string str will contains numbers only, where each number stands for a key pressed on a mobile phone.
2. The following list is the key to characters map :
    0 -> .;
    1 -> abc
    2 -> def
    3 -> ghi
    4 -> jkl
    5 -> mno
    6 -> pqrs
    7 -> tu
    8 -> vwx
    9 -> yz
3. Complete the body of getKPC function - without changing signature - to get the list of all words that could be produced by the keys in str.
*/

#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>

using namespace std;

string keypad[] = {".,", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void getKpc(string str, string ans) {
  if(str.length() == 0) {
    cout<<ans<<endl;
    return;
  }

  //seperating the first character and rest of the string
  string fstr = str.substr(0,1);
  int idx = stoi(fstr); //to convert from string to int
  string rstr = str.substr(1, str.size());

  for(int i=0; i<keypad[idx].length(); i++) {
    getKpc(rstr, ans+keypad[idx][i]);
  }
}

int main() {
  string str;
  cout<<"Enter the keypad combination(numbers only): ";
  cin>>str;

  getKpc(str, "");

  return 0;
}
