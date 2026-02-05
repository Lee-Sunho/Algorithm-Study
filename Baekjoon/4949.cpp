#include <bits/stdc++.h>
using namespace std;

string str;

bool check(string s) {
    stack<char> stk;

    for (char c : str) {
        if (c == '(' || c == '[')
            stk.push(c);
        else if (c == ')') {
            if (stk.size() && stk.top() == '(')
                stk.pop();
            else
                return false;
        } else if (c == ']') {
            if (stk.size() && stk.top() == '[')
                stk.pop();
            else
                return false;
        }
    }

    return stk.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        getline(cin, str);
        if (str == ".") break;

        if (check(str))
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }

    return 0;
}