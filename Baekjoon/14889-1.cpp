#include <bits/stdc++.h>
using namespace std;

int n, ret = 1e9;
int arr[24][24];

void func(int idx, vector<int>& v_start) {
    if (idx > n) return;

    if (v_start.size() == n / 2) {
        int start = 0, link = 0;
        vector<int> v_link;
        for (int i = 1; i <= n; i++) {
            if (find(v_start.begin(), v_start.end(), i) == v_start.end()) {
                v_link.push_back(i);
            }
        }

        for (int i = 0; i < v_start.size(); i++) {
            for (int j = i + 1; j < v_start.size(); j++) {
                start += arr[v_start[i]][v_start[j]];
                start += arr[v_start[j]][v_start[i]];
            }
        }

        for (int i = 0; i < v_link.size(); i++) {
            for (int j = i + 1; j < v_link.size(); j++) {
                link += arr[v_link[i]][v_link[j]];
                link += arr[v_link[j]][v_link[i]];
            }
        }

        ret = min(ret, abs(start - link));
        return;
    }

    v_start.push_back(idx);
    func(idx + 1, v_start);
    v_start.pop_back();
    func(idx + 1, v_start);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> start;

    func(1, start);

    cout << ret;

    return 0;
}
