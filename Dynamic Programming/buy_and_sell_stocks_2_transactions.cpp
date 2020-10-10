/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are required to print the maximum profit you can make if you are allowed two transactions at-most.
Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
  int days;
  cout<<"Enter the number of days: ";
  cin>>days;

  int prices[days];
  cout<<"\nEnter the prices of stocks for each day: \n";
  for(int i=0; i<days; i++)
    cin>>prices[i];

  int dpBuy[days] = {0}; //aaj ya aaj se phle sell krk mai max profit kitna le skta hu

  int buy = prices[0];

  for(int i=1; i<days; i++) {
    if(buy > prices[i]) {
      dpBuy[i] = dpBuy[i-1];
      buy = prices[i];
    }
    else
      dpBuy[i] = max(prices[i] - buy, dpBuy[i-1]);
  }

  int dpSell[days] = {0}; //aaj ya aaj k baad buy krk mai max profit kitna le skta hu

  int sell = prices[days - 1];

  for(int i=days-2; i>=0; i--) {
    if(sell < prices[i]) {
      dpSell[i] = dpSell[i+1];
      sell = prices[i];
    }
    else
      dpSell[i] = max(sell - prices[i], dpSell[i+1]);
  }

  //to find the overall max profit that can be made in 2 transactions only
  int overallSum = 0;

  for(int i=0; i<days; i++) {
    if(dpBuy[i] + dpSell[i] > overallSum)
      overallSum = dpBuy[i] + dpSell[i];
  }

  cout<<overallSum;

  return 0;
}
