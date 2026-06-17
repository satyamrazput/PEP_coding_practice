
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main() {
    Solution sol;
    string test_str = "{[()]}";
    
    if (sol.isValid(test_str)) {
        cout << "The string '" << test_str << "' is VALID." << endl;
    } else {
        cout << "The string '" << test_str << "' is INVALID." << endl;
    }
    
    return 0;
}