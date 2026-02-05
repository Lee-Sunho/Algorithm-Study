#include <bits/stdc++.h>
using namespace std;

int t;
string str;
stack<char> stk;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> str;
        for (char c : str) {
            if (c == ')' && stk.size() && stk.top() == '(')
                stk.pop();
            else {
                stk.push(c);
            }
        }

        if (stk.empty()) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }

        while (!stk.empty()) {
            stk.pop();
        }
    }

    return 0;
}