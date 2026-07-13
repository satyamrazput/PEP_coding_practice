#include <iostream>
using namespace std;

int main(){
   int a = 10, b = 20; 

   cout << "before swaping"<<"\t" << a <<"\t" << b ;
   
   int temp = a;
   a = b ;
   b = temp; 

   cout <<"\nafter swaping "<< "\t" << a << "\t" << b ;

   return 0;

}