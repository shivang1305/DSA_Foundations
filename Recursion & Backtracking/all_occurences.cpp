#include<iostream>
#include<vector>

using namespace std;

int* allOccurences(int A[], int idx, int ele, int N, int fsf) {
  if(idx == N){ //base case
    int* arr = new int[fsf];
    return arr;
  }
  if(A[idx] == ele){
    int* iarr = allOccurences(A, idx+1, ele, N, fsf+1);
    iarr[fsf] = idx;
    return iarr;
  }else{
    int* iarr = allOccurences(A, idx+1, ele, N, fsf);
    return iarr;
  }
}

int main() {
  int N;
  cout<<"enter the size of array: ";
  cin>>N;
  int Arr[N];
  cout<<"\nEnter the elements of array: ";
  for(int i=0; i<N; i++)
    cin>>Arr[i];

  int ele;
  cout<<"\nEnter the element to be searched for: ";
  cin>>ele;

  int* result = allOccurences(Arr, 0, ele, N, 0);

  cout<<"\nThe indices of all occurences of the specified element are: ";
  for(int i=0; i<sizeof(result)/4; i++)
    cout<<result[i]<<" ";

  return 0;
}
