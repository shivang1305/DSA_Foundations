#include<iostream>

using namespace std;

int main() {
  int days;
  cout<<"Enter the number of days: ";
  cin>>days;

  int prices[days];
  cout<<"\nEnter the prices of stocks at each day: ";
  for(int i=0; i<days; i++)
    cin>>prices[i];

  int buy = prices[0];
  int sell = prices[0];
  int profit = 0;

  for(int i=1; i<days; i++) {
    if(prices[i] < prices[i-1]) { //decrement
      profit += sell - buy;
      buy = prices[i];
      sell = prices[i];
    }
    else if(prices[i] >= prices[i-1]) //increment
      sell = prices[i];
  }

  profit += sell - buy;

  cout<<profit;
  return 0;
}
