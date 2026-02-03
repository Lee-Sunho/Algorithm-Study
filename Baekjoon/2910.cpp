#include <bits/stdc++.h>
using namespace std;

int n, c, temp;
vector<int> v;
map<int, int> cnt;
map<int, int> idx;

bool cmp(int a, int b) {
    if (cnt[a] != cnt[b]) {
        return cnt[a] > cnt[b];
    }
    return idx[a] < idx[b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (cnt[temp] == 0) {
            idx[temp] = i;
        }
        cnt[temp]++;
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), cmp);
    for (int value : v) {
        cout << value << ' ';
    }
    return 0;
}