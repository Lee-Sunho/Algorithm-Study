#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    unordered_map<string, int> mp;
    vector<int> answer;

    for (int i = 0; i < name.size(); i++) {
        mp[name[i]] = yearning[i];
    }

    for (int i = 0; i < photo.size(); i++) {
        int sum = 0;
        for (int j = 0; j < photo[i].size(); j++) {
            sum += mp[photo[i][j]];
        }

        answer.push_back(sum);
    }

    return answer;
}