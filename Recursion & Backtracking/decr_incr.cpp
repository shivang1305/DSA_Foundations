/*
1. You are given a positive number n.
2. You are required to print the counting from n to 1 and back to n again.
3. You are required to not use any loops. Complete the body of pdi function to achieve it.
   Don't change the signature of the function.
*/

#include<iostream>

using namespace std;

void func(int N) {
    if(N == 0) //base case
        return;
    cout<<N<<endl;
    func(N-1);
    cout<<N<<endl;
}

int main() {
    int N;
    cout<<"Enter the number: ";
    cin>>N;
    func(N);
    return 0;
}
