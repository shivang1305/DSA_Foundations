/*
                                                                                  Date: 02-Oct-2020
1. You are given a prefix expression.
2. You are required to evaluate it and print it's value.
3. You are required to convert it to infix and print it.
4. You are required to convert it to postfix and print it.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int operation(int val1, int val2, char op) {
  if(op == '+')
    return val1 + val2;
  else if(op == '-')
    return val1 - val2;
  else if(op == '*')
    return val1 * val2;
  else
    return val1 / val2;
}

int main() {
  string exp;
  cout<<"Enter the prefix expression: ";
  cin>>exp;

  stack<int> eval;
  stack<string> postfix;
  stack<string> infix;

  for(int i=exp.size()-1; i>=0; i--) {
    if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
      //for eval stack
      int val1 = eval.top();
      eval.pop();
      int val2 = eval.top();
      eval.pop();
      int ans = operation(val1, val2, exp[i]);
      eval.push(ans);

      string op(1, exp[i]);

      //for infix stack
      string inVal1 = infix.top();
      infix.pop();
      string inVal2 = infix.top();
      infix.pop();
      string inAns = "(" + inVal1 + op + inVal2 + ")";
      infix.push(inAns);

      //for postfix stack
      string postVal1 = postfix.top();
      postfix.pop();
      string postVal2 = postfix.top();
      postfix.pop();
      string postAns = postVal1 + postVal2 + op;
      postfix.push(postAns);
    }
    else {
      eval.push(exp[i] - '0');

      string s(1, exp[i]);
      infix.push(s);
      postfix.push(s);
    }
  }

  cout<<eval.top();
  cout<<"\n"<<infix.top();
  cout<<"\n"<<postfix.top();

  return 0;
}
