#include <bits/stdc++.h>
using namespace std;

string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    getline(cin, str);

    for (char c : str) {
        if (c >= 'A' && c <= 'Z') {
            if (c + 13 <= 'Z') {
                cout << (char)(c + 13);
            } else {
                cout << (char)(c - 13);
            }
        } else if (c >= 'a' && c <= 'z') {
            if (c + 13 <= 'z') {
                cout << (char)(c + 13);
            } else {
                cout << (char)(c - 13);
            }
        } else {
            cout << c;
        }
    }
    return 0;
}