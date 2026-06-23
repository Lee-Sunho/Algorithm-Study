#include <bits/stdc++.h>

using namespace std;
int cur_time, idx, ret, end_cnt;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());

    while (1) {
        int isEnd = 0;
        while (idx < jobs.size() && jobs[idx][0] <= cur_time) {
            pq.push({jobs[idx][1], jobs[idx][0]});
            idx++;
        }

        if (pq.size()) {
            cur_time = cur_time + pq.top().first;
            ret += cur_time - pq.top().second;
            pq.pop();
            end_cnt++;
        } else {
            cur_time = jobs[idx][0];
        }

        if (end_cnt == jobs.size()) break;
    }

    return ret / jobs.size();
}