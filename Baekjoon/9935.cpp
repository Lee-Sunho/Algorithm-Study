#include <bits/stdc++.h>
using namespace std;

string str, target, ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str >> target;

    for (int i = 0; i < str.size(); i++) {
        ret += str[i];

        if (ret.size() >= target.size()) {
            string sub = ret.substr(ret.size() - target.size());
            if (sub == target) {
                for (int i = 0; i < target.size(); i++) {
                    ret.pop_back();
                }
            }
        }
    }

    if (ret.size() == 0)
        cout << "FRULA";
    else
        cout << ret;

    return 0;
}