#include <iostream>
#include <stack>
using namespace std;

bool checkBalance(string ip) {
    stack<char> st;
    for (char it : ip) {
        if (it == '(' || it == '{' || it == '[') {
            st.push(it);
        } else if (it == ')' || it == '}' || it == ']') {
            if (st.empty())
                return false;
            char top = st.top();
            st.pop();
            if ((it == ')' && top != '(') ||
                (it == '}' && top != '{') ||
                (it == ']' && top != '['))
                return false;
        }
    }
    return st.empty();
}

int main() {
    string ip;
    cout << "Enter string to check for balanced delimiters: ";
    cin >> ip;
    bool ans = checkBalance(ip);
    if (ans) cout << "Balanced String";
    else cout << "Unbalanced String";
    return 0;
}
