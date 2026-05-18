#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int n = brown + yellow;

    for (int r = 3; r <= n; r++) {
        if (n % r == 0) {
            int c = n / r;
            if (r > c) continue;
            if ((r - 2) * (c - 2) == yellow) {
                answer.push_back(c);
                answer.push_back(r);
                break;
            }
        }
    }
    return answer;
}