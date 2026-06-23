#include<iostream>
using namespace std;

int main() {
    int num [7] = {12,4,5,6,711,-1,-12};
    int size = 7;

    int smallest = INT_MAX;

    for (int i = 0; i<size; i++){
        if (num[i]< smallest){
            smallest = num[i];
        }
    }
    cout<<"\nThe smallest number in the array is: "<<smallest<<endl;

}