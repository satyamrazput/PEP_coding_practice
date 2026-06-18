#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("student.txt");
    string line;

    if (file.is_open()) {
        cout << "Student Details:\n" << endl;

        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    } else {
        cout << "Unable to open file!" << endl;
    }

    return 0;
}