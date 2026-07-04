#include <bits/stdc++.h>

using namespace std;

int parents[101];

int find(int x) {
    if (parents[x] == -1) {
        return x;
    }

    return parents[x] = find(parents[x]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) {
        return false;
    }

    parents[b] = a;
    return true;
}

bool cmp(vector<int> v1, vector<int> v2) {
    return v1[2] < v2[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    memset(parents, -1, sizeof(parents));
    sort(costs.begin(), costs.end(), cmp);

    for (vector<int> v : costs) {
        if (merge(v[0], v[1])) {
            answer += v[2];
        }
    }

    return answer;
}