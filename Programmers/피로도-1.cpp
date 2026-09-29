#include <bits/stdc++.h>

using namespace std;

int hp, n, max_cnt = -1;
vector<vector<int>> v;
bool visited[10];

void func(int cur) {
    max_cnt = max(max_cnt, cur);
    if (cur == n) return;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && hp >= v[i][0]) {
            visited[i] = true;
            hp -= v[i][1];
            func(cur + 1);
            visited[i] = false;
            hp += v[i][1];
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    hp = k;
    n = dungeons.size();
    v = dungeons;

    func(0);

    return max_cnt;
}