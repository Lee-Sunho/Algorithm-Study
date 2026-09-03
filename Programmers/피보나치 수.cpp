#include <bits/stdc++.h>

using namespace std;

int dp[100001];

int fibo(int cur) {
    if (dp[cur] != -1) return dp[cur];
    if (cur <= 1) return cur;

    int ret = (fibo(cur - 2) + fibo(cur - 1)) % 1234567;
    dp[cur] = ret;
    return ret;
}

int solution(int n) {
    memset(dp, -1, sizeof(dp));
    int answer = fibo(n);
    return answer;
}