// Write a Program to Check Even or Odd Integers.

#include<iostream>
using namespace std;

int main (){
    int a;
    cout << "Enter an integer: ";
    cin >> a;

    if (a%2 == 0){
        
        cout << a << " is an Even number." << endl;
    }
    else{
        cout << a << " is an Odd number." << endl;
    }
}