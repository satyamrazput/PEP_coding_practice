#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<char> st;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if(st.empty())
            {
                cout << "Not Balanced";
                return 0;
            }

            if((s[i] == ')' && st.top() != '(') ||
               (s[i] == '}' && st.top() != '{') ||
               (s[i] == ']' && st.top() != '['))
            {
                cout << "Not Balanced";
                return 0;
            }

            st.pop();
        }
    }

    if(st.empty())
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}