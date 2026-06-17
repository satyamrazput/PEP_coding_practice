//factorial of a number using pointer

#include<iostream>
using namespace std;    
  int main(){
    int fact=1,n,*ptr;
    cout<<"Enter a number :";
    cin>>n;
    ptr=&fact;
    for(int i=1; i<=n; i++){
        *ptr = (*ptr)*i;

  }
    cout<<"Factorial of "<<n<<" is :"<<fact;
    return 0;
}