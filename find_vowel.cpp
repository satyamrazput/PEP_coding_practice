#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("student.txt");
    char ch;
    int vowels = 0;

    if (file.is_open()) {
        while (file.get(ch)) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                vowels++;
            }
        }

        file.close();
        cout << "Number of vowels in file: " << vowels << endl;
    } else {
        cout << "Unable to open file!" << endl;
    }

    return 0;
}