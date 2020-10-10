/*
Day 24 ->   DSA Foundations                                                      Date: 25-Sept-2020
*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int precedence (char ch) {
  if(ch == '+' || ch == '-')
    return 1;
  else if(ch == '*' || ch == '/')
    return 2;
}


int main() {
  string exp;
  cout<<"Enter the expression: ";
  getline(cin, exp);

  stack<string> operandsPre;
  stack<string> operandsPost;
  stack<char> operators;

  for(int i=0; i<exp.length(); i++) {

    if(exp[i] == '(')
      operators.push(exp[i]);

    else if(exp[i] == ')') {
      while(operators.top() != '(') {
        char op = operators.top();
        string opr(1, op);
        operators.pop();

        string preVal2 = operandsPre.top(); // val1 - val2 != val2 - val1
        operandsPre.pop();
        string preVal1 = operandsPre.top();
        operandsPre.pop();

        string ansPre = opr + preVal1 + preVal2;
        operandsPre.push(ansPre);

        /*---------------------------------------------------------------------*/

        string postVal2 = operandsPost.top(); // val1 - val2 != val2 - val1
        operandsPost.pop();
        string postVal1 = operandsPost.top();
        operandsPost.pop();

        string ansPost = postVal1 + postVal2 + opr;
        operandsPost.push(ansPost);
      }

      operators.pop(); //to pop out opening bracket also
    }

    else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
      //exp[i] is wanting to solve higher priority operators first or till it finds opening bracket or till the size of stack becomes zero
      while(!operators.empty() && operators.top() != '(' && precedence(exp[i]) <= precedence(operators.top())) {
        char op = operators.top();
        string opr(1, op);
        operators.pop();

        string preVal2 = operandsPre.top(); // val1 - val2 != val2 - val1
        operandsPre.pop();
        string preVal1 = operandsPre.top();
        operandsPre.pop();

        string ansPre = opr + preVal1 + preVal2;
        operandsPre.push(ansPre);

        /*---------------------------------------------------------------------*/

        string postVal2 = operandsPost.top(); // val1 - val2 != val2 - val1
        operandsPost.pop();
        string postVal1 = operandsPost.top();
        operandsPost.pop();

        string ansPost = postVal1 + postVal2 + opr;
        operandsPost.push(ansPost);
      }
      operators.push(exp[i]);
    }

    else {
      string s(1, exp[i]);
      operandsPre.push(s);
      operandsPost.push(s);
    }
  }

  //for all the remaining  operators and operands
  while(!operators.empty()) {
    char op = operators.top();
    string opr(1, op);
    operators.pop();

    string preVal2 = operandsPre.top(); // val1 - val2 != val2 - val1
    operandsPre.pop();
    string preVal1 = operandsPre.top();
    operandsPre.pop();

    string ansPre = opr + preVal1 + preVal2;
    operandsPre.push(ansPre);

    /*---------------------------------------------------------------------*/

    string postVal2 = operandsPost.top(); // val1 - val2 != val2 - val1
    operandsPost.pop();
    string postVal1 = operandsPost.top();
    operandsPost.pop();

    string ansPost = postVal1 + postVal2 + opr;
    operandsPost.push(ansPost);
  }

  cout<<"\nPrefix expression = "<<operandsPre.top();
  cout<<"\nPostfix expression = "<<operandsPost.top();

  return 0;
}
