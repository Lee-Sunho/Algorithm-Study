#include <bits/stdc++.h>

using namespace std;

int cnt;
vector<string> answer;
vector<string> temp;
map<string, vector<string>> mmap;
map<string, vector<bool>> visited;

bool func(string cur) {
    if (cnt == 0) {
        answer = temp;
        return true;
    }

    for (int i = 0; i < mmap[cur].size(); i++) {
        if (visited[cur][i]) continue;

        temp.push_back(mmap[cur][i]);
        visited[cur][i] = true;
        cnt--;

        if (func(mmap[cur][i])) return true;

        temp.pop_back();
        visited[cur][i] = false;
        cnt++;
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    cnt = tickets.size();
    sort(tickets.begin(), tickets.end());

    for (int i = 0; i < tickets.size(); i++) {
        mmap[tickets[i][0]].push_back(tickets[i][1]);
        visited[tickets[i][0]].push_back(false);
    }

    temp.push_back("ICN");
    func("ICN");

    return answer;
}