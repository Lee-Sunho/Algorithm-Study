#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    for (auto item : clothes) {
        m[item[1]]++;
    }

    for (auto pair : m) {
        answer *= pair.second + 1;
    }

    return answer - 1;
}