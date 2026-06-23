// Write a Program to Find Compound Interest.
#include <iostream>
using namespace std;

int main(){
    float p,r,t,ci;

    cout<<"Enter Principal Amount: ";
    cin>>p;
    cout<<"Enter Rate of Interest: ";
    cin>>r;
    cout<<"Enter Time in Years: ";
    cin>>t;

    ci = p * (pow((1+r/100),t));

    cout<<"\nCompound Interest = "<<ci<<endl;
}