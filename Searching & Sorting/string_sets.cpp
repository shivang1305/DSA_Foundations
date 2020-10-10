#include<iostream>
#include<string>
#include <bits/stdc++.h>

using namespace std;

void mergeArray(string A[], int lb, int mid, int ub) {
  string B[ub+1];
  int i = lb, k = lb, j = mid+1;
  while(i<=mid && j<=ub)
  {
    if(A[i].length() < A[j].length())
    {
      B[k] = A[i];
      i++;
    }
    else if(A[i].length() > A[j].length())
    {
      B[k] = A[j];
      j++;
    }
    else if(A[i].length() == A[j].length())
    {
      B[k] = A[i];
      i++;
    }
    k++;
  }
  if(i<=mid)
  {
    while(i<=mid)
    {
      B[k] = A[i];
      i++;
      k++;
    }
  }
  else
  {
    while(j<=ub)
    {
      B[k] = A[j];
      j++;
      k++;
    }
  }
  for(k=lb; k<=ub; k++)
    A[k] = B[k];
}

void mergeSort(string Arr[], int lb, int ub) {
  int mid;
  if(lb < ub) {
    mid = (lb + ub)/2;
    mergeSort(Arr, lb, mid);
    mergeSort(Arr, mid+1, ub);
    mergeArray(Arr, lb, mid, ub);
  }
}

vector<string> removeSpaces(string str) {
  //used to split string around spaces
  istringstream ss(str);

  //traverse through all words
  vector<string> s;
  do{
    //read a word
    string word;
    ss>>word;

    // inserting into the array
    s.push_back(word);

  }while(ss);
  return s;
}

int main() {
  int T;
  cout<<"Enter the number of testcases: ";
  cin>>T;

 cin.ignore();
  while(T--) {
    string str;
    cout<<"Enter the string: ";
    getline(cin, str);

    vector<string> s = removeSpaces(str);
    string val[s.size()];

    int z=0;
    for(auto i=s.begin(); i!=s.end(); i++) {
      val[z] = *i;
      z++;
    }

    mergeSort(val, 0, s.size() - 1);

    cout<<"\nUpdated string:";
    for(int i=0; i<s.size(); i++)
      cout<<val[i]<<" ";
    cout<<"\n";

  }


  return 0;
}
