#include <bits/stdc++.h>

using namespace std;

int ret = -999, visited[10];
vector<vector<int>> v;

void func(int n, int cur) {
    ret = max(n, ret);

    for (int i = 0; i < v.size(); i++) {
        if (!visited[i] && cur >= v[i][0]) {
            visited[i] = 1;
            func(n + 1, cur - v[i][1]);
            visited[i] = 0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    v = dungeons;
    func(0, k);
    return ret;
}