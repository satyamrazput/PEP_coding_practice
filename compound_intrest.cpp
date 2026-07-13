#include <iostream>
using namespace std;

int main (){

    double P , R, T , A, CI;

    cout <<"Enter Principal Amount: ";
    cin >> P ;
    cout <<"Enter Rate of Interest: ";
    cin >> R ;
    cout <<"Enter Time Period: ";
    cin >> T ;

    A = P * (pow((1 + R / 100), T)) ;
    CI = A - P ;
   

    cout << "Compound intrest is: " << CI << endl;

    return 0;


}