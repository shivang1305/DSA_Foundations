/*
1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are given a number "tar".
4. Complete the body of printTargetSumSubsets function - without changing signature - to calculate and print all subsets of given elements, the contents of which sum to "tar". Use sample input and output to get more idea.
*/

#include<iostream>

using namespace std;

void targetSubset(int Arr[], int N, int idx, string set, int tar, int sof) {
  if(sof > tar) //negative base case
    return;
  if(idx == N) {
    if(sof == tar) { //positive base case
      cout<<set<<endl;
      return;
    }
    return;
  }

  targetSubset(Arr, N, idx+1, set+" "+to_string(Arr[idx]), tar, sof+Arr[idx]);
  targetSubset(Arr, N, idx+1, set, tar, sof);
}

int main() {
  int N;
  cout<<"Enter the size of array: ";
  cin>>N;

  int Arr[N];

  cout<<"\nEnter the elements of the array: ";
  for(int i=0; i<N; i++)
    cin>>Arr[i];

  int target;
  cout<<"\nEnter the target sum: ";
  cin>>target;

  targetSubset(Arr, N, 0, "", target, 0); //function call

  return 0;
}
