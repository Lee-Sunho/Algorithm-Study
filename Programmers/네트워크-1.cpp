#include <bits/stdc++.h>

using namespace std;

bool visited[204];
int answer;

void func(int start, int n, vector<vector<int>>& computers) {
    if (start == n) return;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && computers[start][i] == 1) {
            visited[i] = true;
            func(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            answer++;
            visited[i] = true;
            func(i, n, computers);
        }
    }
    return answer;
}