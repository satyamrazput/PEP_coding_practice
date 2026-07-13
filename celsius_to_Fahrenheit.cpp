#include<iostream>
using namespace std;

float fahrenheit (float celsius){return (celsius - 32.0) * 5.0 / 9.0;}

int main (){

    float celsius , converted_value ;
    cout <<"enter temperature in celsius:";
    cin >> celsius;

    converted_value = fahrenheit (celsius);
    cout << "Temperatue in fahrenhite is:  "<< converted_value <<endl;
    
    return 0;

}