#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
  string str;
  cout<<"Enter the balanced expression: ";
  getline(cin, str);

  stack<char> st;

  for(int i=0; i<str.length(); i++) {
    if(str[i] != ')')
      st.push(str[i]);
    else {
      if(st.top() == '(') {  //it means that there is nothing between opening and closing brackets
        cout<<"true";
        return 0;
      }

      while(st.top() != '(') //pop the elements till we get openeing brackets
        st.pop();
      st.pop();
    }
  }

  cout<<"false";

  return 0;
}
