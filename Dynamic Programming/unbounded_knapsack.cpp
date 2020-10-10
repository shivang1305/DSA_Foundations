/*
1. You are given a number n, representing the count of items.
2. You are given n numbers, representing the values of n items.
3. You are given n numbers, representing the weights of n items.
3. You are given a number "cap", which is the capacity of a bag you've.
4. You are required to calculate and print the maximum value that can be created in the bag without
    overflowing it's capacity.
Note -> Each item can be taken any number of times. You are allowed to put the same item again
        and again.
*/

#include<iostream>

using namespace std;

int main() {
  int n;
  cout<<"Enter the number of entities: ";
  cin>>n;

  int weights[n];
  cout<<"\nEnter the weights: ";
  for(int i=0; i<n; i++)
    cin>>weights[i];

  int values[n];
  cout<<"\nEnter the values: ";
  for(int i=0; i<n; i++)
    cin>>values[i];

  int capacity;
  cout<<"\nEnter the capacity of bag: ";
  cin>>capacity;

  int dp[capacity + 1] = {0};  //meaning of the array is- ith bag ki capacity k liye (weights-values) pair k repitition k sth hm kitni max value bag me store krwa skte hain.

  int maxVal;

  for(int i=1; i<=capacity; i++) {
    maxVal = 0;
    for(int j=0; j<n; j++)
      if(i >= weights[j]) {
        maxVal = max(maxVal, values[j] + dp[i - weights[j]]); //batting wala concept
    }
    dp[i] = maxVal;
  }

  cout<<dp[capacity];
  return 0;
}
