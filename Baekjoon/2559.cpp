#include <bits/stdc++.h>
using namespace std;

int N, K, max_sum = -10000004;  // -100 * 100,000
int psum[100004];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin >> K;

    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        psum[i] = psum[i - 1] + x;
    }

    for (int i = K; i <= N; i++) {
        max_sum = max(max_sum, psum[i] - psum[i - K]);
    }

    cout << max_sum << '\n';
    return 0;
}