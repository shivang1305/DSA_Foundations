/*
1. You are given a number n, representing the count of coins.
2. You are given n numbers, representing the denominations of n coins.
3. You are given a number "amt".
4. You are required to calculate and print the number of combinations of the n coins using which the amount "amt" can be paid.

Note1 -> You have an infinite supply of each coin denomination i.e. same coin denomination can be
         used for many installments in payment of "amt"
Note2 -> You are required to find the count of combinations and not permutations i.e.
         2 + 2 + 3 = 7 and 2 + 3 + 2 = 7 and 3 + 2 + 2 = 7 are different permutations of same
         combination. You should treat them as 1 and not 3.
*/

 #include<iostream>

 using namespace std;

 int main() {
   int N;
   cout<<"Enter the size of coins array: ";
   cin>>N;

   int coins[N];
   for(int i=0; i<N; i++)
    cin>>coins[i];

   int target;
   cout<<"Enter the target value: ";
   cin>>target;

   int dp[target + 1] = {0};
   dp[0] = 1;

   for(int i=0; i<N; i++) { //coins k array k liye
     for(int j=coins[i]; j<=target; j++) { //dp waale array k liye
       dp[j] += dp[j - coins[i]];
     }
   }

   cout<<"\nTotal number of combinations: "<<dp[target];

   return 0;
 }
