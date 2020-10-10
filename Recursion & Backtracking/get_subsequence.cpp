/*

*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> getSubsequence(string str){
  if(str.length() == 0){ //base case
    vector<string> rstr;
    rstr.push_back("");
    return rstr;
  }

  char ch = str[0];
  string subStr = str.substr(1, str.size());
  vector<string> resStr = getSubsequence(subStr);

  vector<string> finStr;
  for(string s: resStr){
    finStr.push_back(""+s);
  }
  for(string s: resStr){
    finStr.push_back(ch+s);
  }
  return finStr;
}

int main(){
  string str;
  cout<<"Enter the string: ";
  cin>>str;

  vector<string> res = getSubsequence(str);

  for(auto itr = res.begin(); itr!=res.end(); itr++)
    cout<<*itr<<endl;

  return 0;
}
