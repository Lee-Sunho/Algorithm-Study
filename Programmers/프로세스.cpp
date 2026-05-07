#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int, int>> dq;

    for (int i = 0; i < priorities.size(); i++) {
        dq.push_back({i, priorities[i]});
    }

    while (1) {
        int check = 1;
        auto cur = dq.front();
        dq.pop_front();
        for (int i = 0; i < dq.size(); i++) {
            if (cur.second < dq[i].second) {
                check = 0;
                break;
            }
        }

        if (check) {
            answer++;
            if (cur.first == location) break;
        } else {
            dq.push_back(cur);
        }
    }

    return answer;
}
