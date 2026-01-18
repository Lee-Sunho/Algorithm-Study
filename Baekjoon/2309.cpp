/* 순열(완전탐색)을 이용한 방법 */
#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    do {
        int sum = 0;
        for (int i = 0; i < 7; i++) {
            sum += v[i];
        }

        if (sum == 100) break;
    } while (next_permutation(v.begin(), v.end()));

    for (int i = 0; i < 7; i++) {
        cout << v[i] << '\n';
    }
}