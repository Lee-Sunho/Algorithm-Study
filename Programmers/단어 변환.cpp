#include <bits/stdc++.h>

using namespace std;

int visited[51], answer = 1e9;
string s_target;
vector<string> v_words;

void func(string cur, int cnt) {
    if (cur == s_target) {
        answer = min(answer, cnt);
    }

    for (int i = 0; i < v_words.size(); i++) {
        int diff_cnt = 0;
        if (visited[i]) continue;

        for (int j = 0; j < v_words[i].size(); j++) {
            if (cur[j] != v_words[i][j]) diff_cnt++;
            if (diff_cnt > 1) break;
        }

        if (diff_cnt == 1) {
            visited[i] = 1;
            func(v_words[i], cnt + 1);
            visited[i] = 0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }

    s_target = target;
    v_words = words;

    func(begin, 0);

    if (answer == 1e9)
        return 0;
    else
        return answer;
}