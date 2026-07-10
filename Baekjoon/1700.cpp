#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
vector<int> v;
vector<int> multi;
bool include[104];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < v.size(); i++) {
        if (include[v[i]]) continue;

        if (multi.size() < n) {
            multi.push_back(v[i]);
            include[v[i]] = true;
        } else {
            int pop_idx = -1;
            int last_idx = -1;

            for (int j = 0; j < multi.size(); j++) {
                int next_idx = 1e9;

                for (int k = i + 1; k < v.size(); k++) {
                    if (v[k] == multi[j]) {
                        next_idx = k;
                        break;
                    }
                }
                if (next_idx > last_idx) {
                    last_idx = next_idx;
                    pop_idx = j;
                }
            }

            include[multi[pop_idx]] = false;
            include[v[i]] = true;
            multi[pop_idx] = v[i];
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
