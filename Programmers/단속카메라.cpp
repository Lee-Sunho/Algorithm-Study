#include <bits/stdc++.h>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int camera;

    sort(routes.begin(), routes.end(), cmp);

    camera = routes[0][1];
    answer++;

    for (int i = 1; i < routes.size(); i++) {
        if (routes[i][0] > camera) {
            camera = routes[i][1];
            answer++;
        }
    }

    return answer;
}