#include<iostream>

using namespace std;

int main() {
  int days;
  cout<<"Enter the number of days: ";
  cin>>days;

  int prices[days];
  cout<<"\nEnter the prices of stock for each day: \n";
  for(int i=0; i<days; i++)
    cin>>prices[i];

  int fees;
  cout<<"\nEnter the transaction fees: ";
  cin>>fees;

  int bsp = -prices[0];
  int ssp = 0;

  for(int i=1; i<days; i++) {
    int bspNew = 0;
    int sspNew = 0;

    if(bsp < ssp - prices[i]) //updating bought state
      bspNew = ssp - prices[i];
    else
      bspNew = bsp; //continuing the old bought state

    if(bsp + prices[i] - fees > ssp) //updating sell state
      sspNew = bsp + prices[i] - fees;
    else
      sspNew = ssp; //continuing the old sold state

    bsp = bspNew;
    ssp = sspNew;
  }

  cout<<ssp;

  return 0;
}
