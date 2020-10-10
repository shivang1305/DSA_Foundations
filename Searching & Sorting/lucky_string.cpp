#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int luckyString(char A[], int lb, int mid, int ub) {
  int i=lb, j=mid+1;
  int ct1=0, ct2=0, ct3=0;
  while(i<=mid && j<=ub) {
    if(A[i] > A[j]) {
      ct2++;
      ct3++;
    }
    else if(A[i] < A[j]) {
      ct1++;
      ct3++;
    }
    else if(A[i] == A[j]) {
      ct1++;
      ct2++;
    }
    i++;
    j++;
  }

  int ct4 = std::min(ct1, ct2);
  int result = std::min(ct4, ct3);
  return result;
}

int main() {
  int N;
  cout<<"Enter the length of string (even numbers only):  ";
  cin>>N;

  char str[N];
  cout<<"\nEnter the characters of string:  ";
  for(int i=0; i<N; i++)
    cin>>str[i];

  char str1[N/2], str2[N/2];

  for(int i=0; i<N/2; i++)
    str1[i] = str[i];
  for(int i=N/2, j=0; i<N; i++, j++)
    str2[j] = str[i];

  std::sort(str1, str1+sizeof(str1));
  std::sort(str2, str2+sizeof(str2));

  for(int i=0; i<N/2; i++)
    str[i] = str1[i];
  for(int i=N/2, j=0; i<N; i++, j++)
    str[i] = str2[j];

  int mid = (0 + N - 1)/2;
  int result = luckyString(str, 0, mid, N-1);

  cout<<"\nMin number of changes required: "<<result;

  return 0;
}
