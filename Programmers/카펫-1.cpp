#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow;

    for (int h = 3; h <= sqrt(total); h++) {
        if (total % h != 0) continue;

        int w = total / h;
        if ((w - 2) * (h - 2) == yellow) return {w, h};
    }
    return {};
}