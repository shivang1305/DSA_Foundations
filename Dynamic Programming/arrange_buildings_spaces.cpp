/*
   Space Building Space Bulding
   ------------------------------
              ROAD
   ------------------------------
   Space Space Building Space

   No two buildings can be made consecutive
*/

#include<iostream>

using namespace std;

int main() {
  int range;
  cout<<"Enter the range: ";
  cin>>range;

  int count_S, count_B;
  int pcount_S = 1, pcount_B = 1;

  for(int i=2; i<=range; i++) {
      count_S = pcount_S + pcount_B; //no boundation on space
      count_B = pcount_S; //since there is a boundation that no building can be consecutive

      pcount_S = count_S;
      pcount_B = count_B;
  }

  cout<<(count_S + count_B)*(count_S + count_B); //road k dono side yhi krna h
  return 0;
}
