// 해시 이용한 방법
#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;

    for (string person : participant) {
        m[person]++;
    }

    for (string person : completion) {
        m[person]--;
    }

    for (auto pair : m) {
        if (pair.second > 0) {
            return pair.first;
        }
    }
}