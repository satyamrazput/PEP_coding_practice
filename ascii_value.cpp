#include<iostream>
using namespace std;

int main ()
{
    char ch ;

    cout << "Enter a character to find ASCII value: ";
    cin >> ch ;

    cout << "ASCII value of " << ch << " is: " << int(ch) << endl;

    return 0;
}