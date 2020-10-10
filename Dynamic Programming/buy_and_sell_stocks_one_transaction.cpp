#include<iostream>

using namespace std;

int main() {
  int days;
  cout<<"Enter the number of days: ";
  cin>>days;

  int arr[days];
  cout<<"\nEnter the prices of stocks at each day: ";
  for(int i=0; i<days; i++)
    cin>>arr[i];

  int dp[days]; //meaning - this array stores the profit if the stocks were sold on ith day.
  dp[0] = 0; //you cannot earn profit on the very first day

  int minProfit = arr[0];
  int maxProfit = dp[0];

  for(int i=1; i<days; i++) {
    if(minProfit > arr[i]) { //depreciation of price of stock for ith day
      dp[i] = 0;
      minProfit = arr[i];
    }
    else
      dp[i] = arr[i] - minProfit;

    if(maxProfit < dp[i]) //to find the max profit you have to check the profit at every point
      maxProfit = dp[i];
  }

  cout<<maxProfit;

  return 0;
}
