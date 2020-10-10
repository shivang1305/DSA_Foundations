/*
1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are given a number "tar".
4. You are required to calculate and print true or false, if there is a subset the elements of which add up to "tar" or not.
*/

#include<iostream>

using namespace std;

int main() {
  int N;
  cout<<"Enter the size of the array: ";
  cin>>N;

  int Arr[N];
  cout<<"\nEnter the elements of array: ";
  for(int i=0; i<N; i++)
    cin>>Arr[i];

  int tar;
  cout<<"\n Enter the target value: ";
  cin>>tar;

  bool dp[N+1][tar+1] = {false};

  for(int i=0; i<=N; i++) {
    for(int j=0; j<=tar; j++) {
      if(i==0 && j==0) //agar koi b batting nhi krega toh zero runs ban jaenge
        dp[i][j] = true;
      else if(i==0) //zero k alawa kch b ni bnega bina batting kre
        dp[i][j] = false;
      else if(j==0) //zero runs koi b batsman bna skta hai bina batting kiye
        dp[i][j] = true;
      else {
        if(dp[i-1][j] == true) //kya phle k players batting krk required runs bna skte hain
          dp[i][j] = true; //agr haan toh mai bina batting kiye apni team k sth required score bnakr jeet skta hu
        else if(j >= Arr[i-1]) { //agr total score mere indivisual number se zyada hai tbhi mai batting kr skta hu
          if(dp[i-1][j-Arr[i-1]] == true) //agr mere batting krne k baad bache hue runs meri team bna skti h tbhi mere batting krne ka faida hai
            dp[i][j] = true;
        }
      }
    }
  }

  if(dp[N][tar] == 1)
    cout<<"true";
  else
    cout<<"false";

  return 0;
}
