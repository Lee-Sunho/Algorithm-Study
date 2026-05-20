#include <bits/stdc++.h>

using namespace std;

int N, cnt, visited[201];
vector<vector<int>> adj;

void func(int idx) {
    visited[idx] = 1;
    for (int i = 0; i < N; i++) {
        if (adj[idx][i] && !visited[i]) {
            func(i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    N = n;
    adj = computers;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            func(i);
            cnt++;
        }
    }
    return cnt;
}