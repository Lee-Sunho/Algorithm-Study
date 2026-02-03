#include <bits/stdc++.h>
using namespace std;

string str;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> str && str != "end") {
        bool isAcceptable = false;
        int v_cnt = 0, c_cnt = 0;

        for (int i = 0; i < str.size(); i++) {
            if (isVowel(str[i])) {
                isAcceptable = true;
                v_cnt++;
                c_cnt = 0;
            } else {
                v_cnt = 0;
                c_cnt++;
            }

            if (v_cnt == 3 || c_cnt == 3) {
                isAcceptable = false;
                break;
            }

            if (i > 0 && str[i] == str[i - 1]) {
                if (str[i] == 'e' || str[i] == 'o') continue;
                isAcceptable = false;
                break;
            }
        }

        cout << "<" << str << "> is ";
        if (isAcceptable) {
            cout << "acceptable." << '\n';
        } else {
            cout << "not acceptable." << '\n';
        }
    }

    return 0;
}