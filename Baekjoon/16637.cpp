#include <bits/stdc++.h>
using namespace std;

int n;
long long ret;
string str;
vector<int> nums;
vector<char> ops;

long long calc(long long a, long long b, char op) {
    switch (op) {
        case '+':
            return a + b;

        case '-':
            return a - b;

        case '*':
            return a * b;
    }
    return 0;
}

long long solve(int idx, long long acc) {
    if (idx == ops.size()) {
        return acc;
    }

    if (idx == ops.size() - 1) {
        return solve(idx + 1, calc(acc, nums[idx + 1], ops[idx]));
    } else {
        return max(
            solve(idx + 1, calc(acc, nums[idx + 1], ops[idx])),
            solve(idx + 2, calc(acc, calc(nums[idx + 1], nums[idx + 2], ops[idx + 1]), ops[idx])));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> str;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            nums.push_back(str[i] - '0');
        else
            ops.push_back(str[i]);
    }

    ret = solve(0, nums[0]);

    cout << ret << '\n';

    return 0;
}