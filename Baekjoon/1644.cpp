#include <bits/stdc++.h>
using namespace std;

int n, ret, sum;
bool is_prime[4000004];

vector<int> v_prime;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    memset(is_prime, 1, sizeof(is_prime));

    for (int i = 2; i <= sqrt(n); i++) {
        if (!is_prime[i]) continue;
        for (int j = 2; i * j <= n; j++) {
            is_prime[i * j] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) v_prime.push_back(i);
    }

    int low = 0, high = 0;

    while (1) {
        if (sum >= n)
            sum -= v_prime[low++];
        else if (high == v_prime.size())
            break;
        else
            sum += v_prime[high++];

        if (sum == n) ret++;
    }

    cout << ret;

    return 0;
}
