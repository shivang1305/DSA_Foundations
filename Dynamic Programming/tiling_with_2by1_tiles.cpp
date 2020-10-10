#include<iostream>

using namespace std;

int main() {
  int N;
  cout<<"Enter the size of floor: ";
  cin>>N;

  int i = 1, j = 2, curr;
    
  for(int k=3; k<=N; k++) {
    curr = i + j;
    i = j;
    j = curr;
  }

  cout<<curr;

  return 0;
}
