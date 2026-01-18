/* 1-C 트럭주차 */

#include <bits/stdc++.h>
using namespace std;

int a, b, c;
vector<pair<int, int>> v;
int cnt[104];
int sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> c;
    for (int i = 0; i < 3; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        v.push_back(p);
    }

    int min = 999;
    int max = 0;

    for (auto p : v) {
        if (p.first < min) {
            min = p.first;
        }

        if (p.second > max) {
            max = p.second;
        }
    }

    for (auto p : v) {
        for (int i = p.first; i < p.second; i++) {
            cnt[i]++;
        }
    }

    for (int i = min; i <= max; i++) {
        if (cnt[i] == 3) {
            sum += c * 3;
        } else if (cnt[i] == 2) {
            sum += b * 2;
        } else if (cnt[i] == 1) {
            sum += a;
        }
    }
    cout << sum;
}