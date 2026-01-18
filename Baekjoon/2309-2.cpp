/* 조합을 이용한 방법 */

#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    vector<int> temp = {0, 0, 1, 1, 1, 1, 1, 1, 1};

    do {
        int sum = 0;
        for (int i = 0; i < 9; i++) {
            if (temp[i]) {
                sum += v[i];
            }
        }

        if (sum == 100) break;
    } while (next_permutation(temp.begin(), temp.end()));

    for (int i = 0; i < 9; i++) {
        if (temp[i]) {
            cout << v[i] << '\n';
        }
    }
}