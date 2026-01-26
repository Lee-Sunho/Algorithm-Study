#include <bits/stdc++.h>
using namespace std;

string str, result;
map<char, int> _map;
char mid;
int num_odd;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str;

    for (char c : str) {
        _map[c]++;
    }

    for (auto it = _map.rbegin(); it != _map.rend(); it++) {
        if (it->second & 1) {
            mid = it->first;
            it->second--;
            if (++num_odd == 2) {
                break;
            }
        }
        for (int i = 0; i < it->second; i += 2) {
            result = it->first + result;
            result = result + it->first;
        }
    }

    if (num_odd > 1) {
        cout << "I'm Sorry Hansoo" << '\n';
        return 0;
    }

    int size = result.length();

    for (int i = 0; i < size; i++) {
        if (i == size / 2 && num_odd == 1) {
            cout << mid;
        }
        cout << result[i];
    }

    if (size == 0 && num_odd == 1) {
        cout << mid;
    }

    return 0;
}