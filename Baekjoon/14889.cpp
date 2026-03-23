#include <bits/stdc++.h>
using namespace std;

int n, arr[21][21], min_res = 1e9;
vector<int> start;

void func(int idx, int depth) {
    int sum_start = 0;
    int sum_link = 0;

    if (depth == n / 2) {
        vector<int> link;
        for (int i = 1; i <= n; i++) {
            if (find(start.begin(), start.end(), i) == start.end()) {
                link.push_back(i);
            }
        }

        for (int i = 0; i < start.size(); i++) {
            for (int j = i + 1; j < start.size(); j++) {
                sum_start += arr[start[i]][start[j]];
                sum_start += arr[start[j]][start[i]];
            }
        }

        for (int i = 0; i < link.size(); i++) {
            for (int j = i + 1; j < link.size(); j++) {
                sum_link += arr[link[i]][link[j]];
                sum_link += arr[link[j]][link[i]];
            }
        }

        min_res = min(min_res, abs(sum_start - sum_link));
        return;
    }

    for (int i = idx; i <= n; i++) {
        start.push_back(i);
        func(i + 1, depth + 1);
        start.pop_back();
    }
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

    func(1, 0);
    cout << min_res;

    return 0;
}