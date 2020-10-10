/*
Day 26 ->  DSA Foundations                                                         Date:26-Sept-2020

Question :
---------
1. You are given a number n, representing the number of time-intervals.
2. In the next n lines, you are given a pair of space separated numbers.
3. The pair of numbers represent the start time and end time of a meeting (first number is start time and second number is end time)
4. You are required to merge the meetings and print the merged meetings output in increasing order of start time.

*/

#include<bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cout<<"Enter the number of intervals: ";
  cin>>N;

  map<int, int, greater<int> > intervals;

  for(int i=0; i<N; i++) {
    int startTime;
    cin>>startTime;

    int endTime;
    cin>>endTime;

    intervals.insert(make_pair(startTime, endTime));
  }

  stack<int> st;

  map<int, int> :: reverse_iterator it = intervals.rbegin();
  map<int, int> :: reverse_iterator itr = intervals.rbegin();
  itr++;

  st.push((*it).first);

  while(itr != intervals.rend()) {
    if((*it).second >= (*itr).first) { //intervals can be merged
      (*it).second = max((*it).second, (*itr).second);
      int key = itr->first;
      intervals.erase(key);
      itr++;
    }
    else {
      st.push((*itr).first);
      it = itr;
      itr++;
    }
  }

  map<int,int> :: reverse_iterator i;
  for (i=intervals.rbegin() ; i!=intervals.rend() ; i++)
      cout << "(" << (*i).first << ", "
           << (*i).second << ")" << endl;

  return 0;
}
