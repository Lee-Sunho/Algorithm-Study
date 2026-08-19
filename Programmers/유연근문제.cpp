#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int sat_idx = (startday == 7) ? 6 : (7 - startday - 1);
    int sun_idx = (startday == 7) ? 0 : (sat_idx + 1);

    for (int i = 0; i < timelogs.size(); i++) {
        bool flag = true;
        for (int j = 0; j < timelogs[0].size(); j++) {
            if (j == sat_idx || j == sun_idx) continue;

            int end_time = schedules[i] + 10;
            if (end_time % 100 >= 60) {
                end_time = (end_time + 100) - 60;
            }
            if (timelogs[i][j] > end_time) {
                flag = false;
                break;
            }
        }
        if (flag) answer++;
    }

    return answer;
}