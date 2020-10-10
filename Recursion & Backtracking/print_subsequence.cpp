#include<iostream>
#include<string>

using namespace std;

void getSubsequence(string que, string ans) {
  if(que.size() == 0) {
    cout<<ans<<endl;
    return;
  }

  char ch = que[0];
  string ros = que.substr(1, que.size());

  getSubsequence(ros, ans+ch);
  getSubsequence(ros, ans+"");
}

int main() {
  string str;
  cout<<"Enter the string: ";
  cin>>str;

  getSubsequence(str, "");

  return 0;
}
