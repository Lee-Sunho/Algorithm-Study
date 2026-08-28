#include <bits/stdc++.h>

using namespace std;

int psum[2001];
set<int> answer;

int solution(vector<int> elements) {
    int n = elements.size();

    for (int i = 1; i <= n * 2; i++) {
        psum[i] = psum[i - 1] + elements[(i - 1) % n];
    }

    for (int len = 1; len <= n; len++) {
        for (int start = 1; start <= n; start++) {
            int sum = psum[start + len - 1] - psum[start - 1];
            answer.insert(sum);
        }
    }

    return answer.size();
}