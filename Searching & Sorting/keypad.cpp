/*
https://www.hackerearth.com/practice/algorithms/sorting/selection-sort/practice-problems/algorithm/old-keypad-in-a-foreign-land-24/
*/

#include<iostream>

using namespace std;

void selectionSort(int Freq[], int f, int Keys[], int k)
{
  int z = 0;
  int sum = 0;
  int ct = 1;
  for(int i=0; i<f; i++)
  {
    int max = i;
    if(i != f-1){
      for(int j=i+1; j<f; j++)
      {
        if(Freq[max] < Freq[j])
          max = j;
      }
    }
    if(Keys[z] > 0){
      if(z == k-1){
          sum = sum + Freq[max]*ct;
          Keys[z]--;
          z=0;
          ct++;
      }else{
        sum = sum + Freq[max]*ct;
        Keys[z]--;
        z++;
      }
    }else
      z++;
    if(max != i){
      int t = Freq[max];
      Freq[max] = Freq[i];
      Freq[i] = t;
    }
  }
  cout<<"\nThe sum is: "<<sum;
}

int main()
{
  int f;
  cout<<"Enter the number of letters: ";
  cin>>f;

  int Freq[f];
  cout<<"\nEnter the frequencies of elements: ";
  for(int i=0; i<f; i++)
    cin>>Freq[i];

  int k;
  cout<<"\nEnter the number of keys: ";
  cin>>k;

  int Keys[k];
  cout<<"\nEnter the keysize for each key: ";
  for(int i=0; i<k; i++)
    cin>>Keys[i];

  int sum = 0, count = 0;
  for(int i=0; i<k; i++)
    sum = sum + Keys[i];

  if(sum < f)
    cout<<"-1";
  else if(k >= f){
    for(int i=0; i<f; i++)
      count += Freq[i];
    cout<<count;
  }
  else
    selectionSort(Freq, f, Keys, k);

  return 0;
}
