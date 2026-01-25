#include <bits/stdc++.h>
using namespace std;

int N;
string pattern, head, tail;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin >> pattern;

    auto end = pattern.find('*');  // 델리미터 인덱스 위치

    head = pattern.substr(0, end);
    tail = pattern.substr(end + 1);

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        if (str.length() < head.length() + tail.length()) {
            cout << "NE" << "\n";
            continue;
        }

        if (str.substr(0, head.length()) == head &&
            str.substr(str.length() - tail.length()) == tail) {
            cout << "DA" << "\n";
            continue;
        }

        cout << "NE" << "\n";
    }

    return 0;
}