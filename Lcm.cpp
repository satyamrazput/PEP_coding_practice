

#include<iostream>
using namespace std;

int gcd (int a, int b){

    return (b == 0) ? a : gcd(b, a % b);
}
int lcm (int a, int b) {
    return (a * b) / gcd(a, b); //Formula for LCM is (a*b)/GCD(a,b)
}
int main(){
    int a = 48, b = 18;
    cout <<"LCM = "<< lcm(a, b);
    return 0;
}