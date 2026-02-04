#include <bits/stdc++.h>
using namespace std;
#define prev xxxx

int n, g1, g2, sum1, sum2;
string prev;
pair<int, string> p;

int changeToInt(string s) {
    return atoi(s.substr(0, 2).c_str()) * 60 + atoi(s.substr(3, 2).c_str());
}

void printResult(int sum) {
    string hour = "00" + to_string(sum / 60);
    string minute = "00" + to_string(sum % 60);
    cout << hour.substr(hour.size() - 2, 2) << ":" << minute.substr(minute.size() - 2, 2) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p.first >> p.second;

        if (g1 > g2) {
            sum1 += changeToInt(p.second) - changeToInt(prev);
        }

        else if (g2 > g1) {
            sum2 += changeToInt(p.second) - changeToInt(prev);
        }

        p.first == 1 ? g1++ : g2++;
        prev = p.second;
    }

    if (g1 > g2) {
        sum1 += changeToInt("48:00") - changeToInt(prev);
    }

    else if (g2 > g1) {
        sum2 += changeToInt("48:00") - changeToInt(prev);
    }

    printResult(sum1);
    printResult(sum2);

    return 0;
}