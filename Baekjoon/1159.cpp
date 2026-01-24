#include <bits/stdc++.h>
using namespace std;

int num;
int cnt[26];
int flag = 0;

int main() {
    cin >> num;
    for (int i = 0; i < num; i++) {
        string str;
        cin >> str;
        cnt[str[0] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= 5) {
            char c = i + 'a';
            cout << c;
            flag++;
        }
    }

    if (!flag) {
        cout << "PREDAJA";
    }
}