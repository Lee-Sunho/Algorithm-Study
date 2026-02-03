#include <bits/stdc++.h>
using namespace std;

int n;
string str, temp;
vector<string> v;

bool cmp(string a, string b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }

    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> str;

        for (char c : str) {
            if (isdigit(c)) {
                temp += c;
            } else if (temp.size()) {
                while (temp.size() && temp.front() == '0') {
                    temp.erase(0, 1);
                }
                if (temp.size() == 0) {
                    temp = "0";
                }
                v.push_back(temp);
                temp = "";
            }
        }

        if (temp.size()) {
            while (temp.size() && temp.front() == '0') {
                temp.erase(0, 1);
            }
            if (temp.size() == 0) {
                temp = "0";
            }

            v.push_back(temp);
            temp = "";
        }
    }

    sort(v.begin(), v.end(), cmp);
    for (string s : v) {
        cout << s << '\n';
    }

    return 0;
}