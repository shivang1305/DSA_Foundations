/*
1. You are given a number n, representing the count of coins.
2. You are given n numbers, representing the denominations of n coins.
3. You are given a number "amt".
4. You are required to calculate and print the number of permutations of the n coins using which the amount "amt" can be paid.

Note1 -> You have an infinite supply of each coin denomination i.e. same coin denomination can be
         used for many installments in payment of "amt"
Note2 -> You are required to find the count of permutations and not combinations i.e.
         2 + 2 + 3 = 7 and 2 + 3 + 2 = 7 and 3 + 2 + 2 = 7 are different permutations of same
         combination. You should treat them as 3 and not 1.
*/

#include<iostream>

using namespace std;

int main() {
  int N;
  cout<<"Enter the number of coins: ";
  cin>>N;

  int coins[N];
  cout<<"\nEnter the value of coins: ";
  for(int i=0; i<N; i++)
    cin>>coins[i];

  int amount;
  cout<<"\nEnter the amount: ";
  cin>>amount;

  int dp[amount + 1] = {0};
  dp[0] = 1; //0 paise chukane ka hmesha ek tareeka hota hai, na kuch dena na kch lena

  for(int i=1; i<=amount; i++) { //dp waale array k liye
    for(int j=0; j<N; j++) { //coins waale array k liye
      if(coins[j] <= i)
        dp[i] += dp[i - coins[j]];
    }
  }

  cout<<"\nTotal number of possible permutations: "<<dp[amount];
  return 0;
}
