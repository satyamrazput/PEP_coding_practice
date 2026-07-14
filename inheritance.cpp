#include<iostream>
using namespace std;

class animal{
public:
    void sound(){
        cout << "Animal sound" ;
    }
};

class Dog : public animal{

public :
 string breed;
    
    void display(){
        cout << "Breed is :  " << breed <<endl ;
    }
    void sound(){
        cout <<"Sound: Woof woof !";
    }
};

class Cat : public animal{
    public:
    void sound(){
        cout << "Sound: Meow !";
    }
};

class Cow : public animal {
    public :
    void sound(){
        cout<< "Sound: Mooooo !";
    }
};

int main()
{
    Dog dog;
    Cat cat;
    Cow cow;

    dog.breed = "Golden Retrever";

    dog.display();
    dog.sound();

    return 0;

}