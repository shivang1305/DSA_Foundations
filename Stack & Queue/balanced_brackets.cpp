#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
  string str;
  cout<<"Enter the expression: ";
  getline(cin, str);

  stack<char> st;
  for(int i=0; i<str.length(); i++) {
    if(str[i] == '(' || str[i] == '{' || str[i] == '[')
      st.push(str[i]);
    else {
      if(str[i] == ')') {
        if(st.empty() || st.top() != '(') {
          cout<<"Not Balanced";
          return 0;
        }
        else
          st.pop();
      }
      else if(str[i] == '}') {
        if(st.empty() || st.top() != '{') {
          cout<<"Not Balanced";
          return 0;
        }
        else
          st.pop();
      }
      else if(str[i] == ']') {
        if(st.empty() || st.top() != '[') {
          cout<<"Not Balanced";
          return 0;
        }
        else
          st.pop();
      }
    }
  }

  if(st.empty())
    cout<<"Balanced";
  else
    cout<<"Not Balanced";

  return 0;
}
