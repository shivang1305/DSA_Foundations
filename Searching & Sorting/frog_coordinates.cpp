#include <iostream>

using namespace std;

int main()
{
  int X, Y, s, T;
  cout<<"\nEnter the coordinates(x, y): ";
  cin>>X>>Y;
  cout<<"\nEnter the side of square: ";
  cin>>s;
  cout<<"\nEnter the time : ";
  cin>>T;

  int count = 0;
  for(int i=X; i<=X+s; i++)
  {
    for(int j=Y; j<=Y+s; j++)
    {
      if(i+j<=T)
        count ++;
    }
  }

  cout<<"\nNumber of coordinates: "<<count;

  return 0;
}
