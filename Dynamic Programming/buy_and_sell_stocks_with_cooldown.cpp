#include<iostream>

using namespace std;

int main() {
  int days;
  cout<<"Enter the number of days: ";
  cin>>days;

  int prices[days];
  cout<<"\nEnter the price of stocks for each day: ";
  for(int i=0; i<days; i++)
    cin>>prices[i];

  int bsp = -prices[0];
  int ssp = 0, csp = 0;

  for(int i=1; i<days; i++) {
    int bspNew = 0, sspNew = 0, cspNew = 0;

    //bought state
    if(csp - prices[i] > bsp)
      bspNew = csp - prices[i];
    else
      bspNew = bsp;

    //sold state
    if(bsp + prices[i] > ssp)
      sspNew = bsp + prices[i];
    else
      sspNew = ssp;

    //cool down state
    if(ssp > csp)
      cspNew = ssp;
    else
      cspNew = csp;

    bsp = bspNew;
    ssp = sspNew;
    csp = cspNew;

  }

  cout<<ssp;

  return 0;
}
