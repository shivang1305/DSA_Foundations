/*
Day 25 -> DSA Foundations                                                       Date: 25-Sept-2020
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int operation(int a, int b, char op) {
  if(op == '+')
    return a + b;
  else if(op == '-')
    return a - b;
  else if(op == '*')
    return a * b;
  else if(op == '/')
    return a / b;
}

int main() {
  string exp;
  cout<<"Enter the postfix expression: ";
  getline(cin, exp);

  stack<int> eval;
  stack<string> infix;
  stack<string> prefix;

  for(int i=0; i<exp.size(); i++) {
    if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '*') {
      //for evaluation stack
      int val2 = eval.top();
      eval.pop();
      int val1 = eval.top();
      eval.pop();
      int ans = operation(val1, val2, exp[i]);
      eval.push(ans);

      string op(1, exp[i]);

      //for infix stack
      string valIn2 = infix.top();
      infix.pop();
      string valIn1 = infix.top();
      infix.pop();
      string ansIn = "(" + valIn1 + op + valIn2 + ")";
      infix.push(ansIn);

      //for prefix stack
      string valPre2 = prefix.top();
      prefix.pop();
      string valPre1 = prefix.top();
      prefix.pop();
      string ansPre = op + valPre1 + valPre2;
      prefix.push(ansPre);
    }
    else {
      eval.push(exp[i] - '0');

      string s(1, exp[i]);
      infix.push(s);
      prefix.push(s);
    }
  }

  cout<<eval.top();
  cout<<"\n"<<infix.top();
  cout<<"\n"<<prefix.top();

  return 0;
}
