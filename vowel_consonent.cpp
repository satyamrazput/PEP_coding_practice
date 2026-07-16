#include <iostream>
using namespace std;

// int main(){
//     char a;

//     cout<< "Enter the Alphabet:  ";
//     cin>> a;

//         if (a == 'a' || a == 'e' || a=='i' || a=='o'|| a=='u'){
//             cout <<"Your alphabet is vowel"; }
//         else
//         cout<<"your character is consonant";

//     return 0;
// };

void vowelorconsonent ( char x ){
if (x == 'a'||x == 'e'|| x == 'i'|| x == 'o'|| x == 'u' || x == 'A' || x == 'E'|| x == 'I' || x == 'O'|| x == 'U'){
cout<<"\nThe charactor : "<<x<<" is vowel"<<endl; 
}else
{
cout<<"\nThe charactor : "<<x<<" is Consonent " <<endl; 
}
};

int main (){
    vowelorconsonent ('b');
    vowelorconsonent ('A');

    return 0;

}