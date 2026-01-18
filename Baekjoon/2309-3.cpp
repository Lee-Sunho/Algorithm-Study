/* 재귀함수 조합을 이용한 방법 */

#include <bits/stdc++.h>
using namespace std;

vector<int> v, result;

void combi(int start) {
    int sum = 0;
    if (result.size() == 7) {
        for (int i : result) {
            sum += i;
        }
        if (sum == 100) {
            sort(result.begin(), result.end());
            for (int i : result) {
                cout << i << '\n';
            }
            exit(0);
        }
        return;
    }

    for (int i = start + 1; i < 9; i++) {
        result.push_back(v[i]);
        combi(i);
        result.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    combi(-1);
}