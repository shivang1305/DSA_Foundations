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

  stack<int> operands;
  stack<char> operators;

  for(int i=0; i<exp.length(); i++) {

    if(exp[i] == '(')
      operators.push(exp[i]);

    else if(isdigit(exp[i]))
      operands.push(exp[i] - '0');

    else if(exp[i] == ')') {
      while(operators.top() != '(') {
        char op = operators.top();
        operators.pop();

        int val2 = operands.top(); // val1 - val2 != val2 - val1
        operands.pop();
        int val1 = operands.top();
        operands.pop();

        int ans = operation(val1, val2, op);

        operands.push(ans);
      }

      operators.pop(); //to pop out opening bracket also
    }

    else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
      //exp[i] is wanting to solve higher priority operators first or till it finds opening bracket or till the size of stack becomes zero
      while(!operators.empty() && operators.top() != '(' && precedence(exp[i]) <= precedence(operators.top())) {
        char op = operators.top();
        operators.pop();

        int val2 = operands.top(); // val1 - val2 != val2 - val1
        operands.pop();
        int val1 = operands.top();
        operands.pop();

        int ans = operation(val1, val2, op);

        operands.push(ans);
      }
      operators.push(exp[i]);
    }
  }

  //for all the remaining  operators and operands
  while(!operators.empty()) {
    char op = operators.top();
    operators.pop();

    int val2 = operands.top(); // val1 - val2 != val2 - val1
    operands.pop();
    int val1 = operands.top();
    operands.pop();

    int ans = operation(val1, val2, op);

    operands.push(ans);
  }

  cout<<"\nThe final ans after evaluating infix expression = "<<operands.top();
  return 0;
}
