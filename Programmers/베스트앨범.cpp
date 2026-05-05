#include <bits/stdc++.h>

using namespace std;

bool comp1(pair<string, int> p1, pair<string, int> p2) {
    return p1.second > p2.second;
}

bool comp2(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> play_map;
    unordered_map<string, vector<pair<int, int>>> gen_map;
    vector<pair<string, int>> gen_v;

    for (int i = 0; i < genres.size(); i++) {
        play_map[genres[i]] += plays[i];
        gen_map[genres[i]].push_back({i, plays[i]});
    }

    for (auto pair : play_map) {
        gen_v.push_back({pair.first, pair.second});
    }

    sort(gen_v.begin(), gen_v.end(), comp1);

    for (auto& it : gen_map) {
        sort(it.second.begin(), it.second.end(), comp2);
    }

    for (auto& it : gen_v) {
        string g_name = it.first;
        auto songs = gen_map[g_name];

        for (int i = 0; i < songs.size() && i < 2; i++) {
            answer.push_back(songs[i].first);
        }
    }

    return answer;
}