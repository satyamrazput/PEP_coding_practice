#include <iostream>
using namespace std;

int main(){
    float P , R , T , SI ;
    cout << "Enter Principal Amount: ";
    cin >> P ;
    cout << "Enter Rate of Interest: ";
    cin >> R ;
    cout << "Enter Time Period: ";
    cin >> T ;

    SI = (P * R * T)/100 ;
    cout << "simple intrest is:" << SI << endl;
    return 0;
}