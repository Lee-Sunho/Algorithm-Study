/* 재귀를 이용한 풀이 */
#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
vector<int> v;
vector<int> temp;

void combi(int start) {
    if (temp.size() == 2) {
        if (temp[0] + temp[1] == m) {
            cnt++;
        }
        return;
    }

    for (int i = start + 1; i < n; i++) {
        temp.push_back(v[i]);
        combi(i);
        temp.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    combi(-1);
    cout << cnt;

    return 0;
}