#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    stack <char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(')
        {
            st.push('(');
        }
        else if(s[i]==')')
        {
            if(st.empty())
            {
                cout<<"Not balanced";
                return 0;
            }
            else
            {
                st.pop();
            }
        }
    }
    if(st.empty())
        {
            cout<<"Balanced";
        }
        else
        {
            cout<<"Not balanced";
        }

        return 0;

    }