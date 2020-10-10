/*
Bishu went to fight for Coding Club. There were N soldiers with various powers. There will be Q rounds to fight and in each round Bishu's power will be varied. With power M, Bishu can kill all the soldiers whose power is less than or equal to M(<=M). After each round, All the soldiers who are dead in previous round will reborn.Such that in each round there will be N soldiers to fight. As Bishu is weak in mathematics, help him to count the number of soldiers that he can kill in each round and total sum of their powers.

1<=N<=10000

1<=power of each soldier<=100

1<=Q<=10000

1<=power of bishu<=100
*/
#include <iostream>

using namespace std;

int main()
{
  int N;
  cout<<"Enter the size: ";
  cin>>N;

  int Arr[N];
  cout<<"\nEnter the powers: ";
  for(int i=0; i<N; i++)
    cin>>Arr[i];

  int Q;
  cout<<"\nEnter the number of rounds: ";
  cin>>Q;

  int q[Q];
  cout<<"\nEnter power in each round: ";
  for(int i=0; i<Q; i++)
    cin>>q[i];

  for(int i=0; i<Q; i++)
  {
    int P = q[i];
    int count = 0, sum = 0;
    for(int j=0; j<N; j++)
    {
      if(P >= Arr[j])
      {
        count++;
        sum += Arr[j];
      }
    }
    cout<<"\n"<<count<<" "<<sum;
  }

  return 0;
}
