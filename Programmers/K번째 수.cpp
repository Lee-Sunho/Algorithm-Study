#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        vector<int> trimed(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
        sort(trimed.begin(), trimed.end());
        answer.push_back(trimed[commands[i][2] - 1]);
    }
    return answer;
}