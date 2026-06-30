#include <bits/stdc++.h>
using namespace std;

int n, lf, rt, visited[100004];
long long cnt;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    while (rt < n) {
        while (visited[v[rt]]) {
            visited[v[lf]] = 0;
            lf++;
        }

        visited[v[rt]] = 1;
        cnt += rt - lf + 1;
        rt++;
    }

    cout << cnt;

    return 0;
}
