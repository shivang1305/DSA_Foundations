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

vector<string> getKpc(string str) {
  if(str.length() == 0) {
    vector<string> estr;
    estr.push_back("");
    return estr;
  }

  //seperating the first character and rest of the string
  string fstr = str.substr(0,1);
  int idx = stoi(fstr); //to convert from string to int
  string rstr = str.substr(1, str.size());

  vector<string> tempStr = getKpc(rstr);

  vector<string> finalStr;
  for(int i=0; i<keypad[idx].length(); i++) {
    for(string s : tempStr){
      finalStr.push_back(keypad[idx][i] + s);
    }
  }
  return finalStr;
}

int main() {
  string str;
  cout<<"Enter the keypad combination(numbers only): ";
  cin>>str;

  vector<string> combos = getKpc(str);

  for(auto itr = combos.begin(); itr!=combos.end(); itr++)
    cout<<*itr<<endl;

  return 0;
}
