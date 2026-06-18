#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string name;
    int roll, age;

    cout << "Enter Student Name: ";
    getline(cin, name);

    cout << "Enter Roll Number: ";
    cin >> roll;

    cout << "Enter Age: ";
    cin >> age;

    ofstream file("student.txt");

    if(file.is_open()) {
        file << "Name: " << name << endl;
        file << "Roll Number: " << roll << endl;
        file << "Age: " << age << endl;
        file.close();

        cout << "Data stored successfully." << endl;
    }

    return 0;
}