#include<iostream>
using namespace std;

int main (){
    int a = 10, b=20;

    cout<<"\nthe value of a before swapping: "<<"a ="<< a <<"\t" << "b = "<< b <<endl;

    int temp =a;
    a=b;
    b=temp;

    cout<<"\nthe value of a after swapping: "<<"a ="<< a << "\t" << "b ="<< b <<endl;

    return 0;


}