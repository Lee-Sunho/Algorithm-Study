#include <bits/stdc++.h>

using namespace std;

int visited[51];

int solution(string begin, string target, vector<string> words) {
    if (find(words.begin(), words.end(), target) == words.end()) return 0;

    queue<pair<string, int>> q;
    q.push({begin, -1});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.first == target) {
            return visited[cur.second];
        }

        for (int i = 0; i < words.size(); i++) {
            if (visited[i]) continue;
            int diff_cnt = 0;

            for (int j = 0; j < words[i].length(); j++) {
                if (cur.first[j] != words[i][j]) diff_cnt++;
                if (diff_cnt > 1) break;
            }

            if (diff_cnt == 1) {
                if (cur.second == -1) {
                    visited[i] = 1;
                } else {
                    visited[i] = visited[cur.second] + 1;
                }
                q.push({words[i], i});
            }
        }
    }

    return 0;
}