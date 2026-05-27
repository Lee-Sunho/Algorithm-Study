#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
    int cnt1 = 0;
    int cnt2 = name.length() - 1;
    int len = name.length();

    for (int i = 0; i < len; i++) {
        if (name[i] > 'N') {
            cnt1 += 'Z' - name[i] + 1;
        } else {
            cnt1 += name[i] - 'A';
        }
    }

    for (int i = 0; i < len; i++) {
        int next = i + 1;
        while (next < len && name[next] == 'A') {
            next++;
        }
        cnt2 = min(cnt2, (i * 2) + len - next);
        cnt2 = min(cnt2, (len - next) * 2 + i);
    }
    return cnt1 + cnt2;
}